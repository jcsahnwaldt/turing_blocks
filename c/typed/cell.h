#ifndef CELL_H
#define CELL_H

struct value_t;
struct cells_t;

typedef struct cell_t {
  long id;
  cell_t* _left = NULL;
  cell_t* _right = NULL;
  cell_t(long id);
  value_t* value; // current value
  cell_t* left();
  cell_t* right();
} cell_t;

#endif
