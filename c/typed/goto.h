#ifndef GOTO_H
#define GOTO_H

#include "action.h"

struct state;

typdef struct goto_t {
  const long max; // max number of actions, < 0 means unbounded
  void print() override;
  goto_t(const char* name, state_t* current, state_t* next, value_t* value, step_t* step, long* count, long max = -1);
  void do_cell() override;
  void do_next() override;
} goto_t;

#endif
