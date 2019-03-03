
#include "cell.h"

#include <stdlib.h>
#include <stdbool.h>

value_t* cell_default_value = NULL;
unsigned long cell_count = 0;

static cell_t* left(cell_t* c) {
  if (! c->_left) {
    cell_t* n = malloc(sizeof(cell_t));
    init_cell(n, c->id - 1);
    n->_right = c;
    c->_left = n;
  }
  return c->_left;
}

static cell_t* right(cell_t* c) {
  if (! c->_right) {
    cell_t* n = malloc(sizeof(cell_t));
    init_cell(n, c->id + 1);
    n->_left = c;
    c->_right = n;
  }
  return c->_right;
}

void init_cell(cell_t* c, long id) {
  cell_count++;
  c->id = id;
  c->value = cell_default_value;
  c->_left = NULL;
  c->_right = NULL;
  c->left = left;
  c->right = right;
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
