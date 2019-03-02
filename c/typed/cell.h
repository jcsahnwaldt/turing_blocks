#ifndef CELL_H
#define CELL_H

typedef struct value_t value_t;

typedef struct cell_t cell_t;
struct cell_t {
  long id;
  long* counter;
  value_t* def_value; // default value
  value_t* value; // current value
  cell_t* _left;
  cell_t* _right;
};

void cell_init(cell_t*, long id, value_t*, long* count);
cell_t* left(cell_t*);
cell_t* right(cell_t*);

#endif
