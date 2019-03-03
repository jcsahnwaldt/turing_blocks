#ifndef CELL_H
#define CELL_H

typedef struct value_t value_t;

extern value_t* cell_default_value; // default value
extern unsigned long cell_count;

typedef struct cell_t cell_t;
struct cell_t {
  long id;

  value_t* value; // current value
  cell_t* _left;
  cell_t* _right;
  cell_t* (*left)(cell_t*);
  cell_t* (*right)(cell_t*);
};

void init_cell(cell_t*, long id);
void destroy_cell(cell_t*);

#endif
