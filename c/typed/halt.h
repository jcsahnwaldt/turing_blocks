#ifndef HALT_H
#define HALT_H

#include "action.h"

typdef struct halt_t {
  void print() override;
  halt_t(const char* name, state_t* state, value_t* value, step_t* step, long* count);
  void do_cell() override;
  void do_next() override;
} halt_t;

#endif
