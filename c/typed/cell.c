
#include "cell.h"

#include <stdlib.h>
#include <stdbool.h>

static cell_t* left(cell_t* c) {
  if (! c->_left) {
    cell_t* n = malloc(sizeof(cell_t));
    cell_init(n, c->id - 1, c->def_value, c->counter);
    n->_right = c;
    c->_left = n;
  }
  return c->_left;
}

static cell_t* right(cell_t* c) {
  if (! c->_right) {
    cell_t* n = malloc(sizeof(cell_t));
    cell_init(n, c->id + 1, c->def_value, c->counter);
    n->_left = c;
    c->_right = n;
  }
  return c->_right;
}

void cell_init(cell_t* c, long id, value_t* v, long* p) {
  (*p)++;
  c->id = id;
  c->counter = p;
  c->def_value = v;
  c->value = v;
  c->_left = NULL;
  c->_right = NULL;
  c->left = left;
  c->right = right;
}

static void cell_free(cell_t* p, bool left) {
  while (p) {
    cell_t* c = p;
    p = left ? p->_left : p->_right;
    free(c);
  }
}

void cell_destroy(cell_t* c) {
  cell_free(c->_left, true);
  cell_free(c->_right, false);
}
