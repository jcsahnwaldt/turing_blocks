
#include "cell.h"

#include <stdlib.h>
#include <stdbool.h>

value_t* cell_default_value = NULL;
unsigned long cell_count = 0;

static cell_t* get_left(cell_t* c) {
  return c->_left;
}

static cell_t* get_right(cell_t* c) {
  return c->_right;
}

static cell_t* init_left(cell_t* c) {
  cell_t* n = malloc(sizeof(cell_t));
  init_cell(n, c->id - 1);
  n->_right = c;
  n->right = get_right;
  c->_left = n;
  c->left = get_left;
  return n;
}

static cell_t* init_right(cell_t* c) {
  cell_t* n = malloc(sizeof(cell_t));
  init_cell(n, c->id + 1);
  n->_left = c;
  n->left = get_left;
  c->_right = n;
  c->right = get_right;
  return n;
}

void init_cell(cell_t* c, long id) {
  cell_count++;
  c->id = id;
  c->value = cell_default_value;
  c->_left = NULL;
  c->_right = NULL;
  c->left = init_left;
  c->right = init_right;
}

static void free_cells(cell_t* p, bool left) {
  while (p) {
    cell_t* c = p;
    p = left ? p->_left : p->_right;
    free(c);
  }
}

void destroy_cell(cell_t* c) {
  free_cells(c->_left, true);
  free_cells(c->_right, false);
}
