#ifndef ACTION_H
#define ACTION_H

struct value_t;
struct step_t;
struct state_t;

typedef struct action_t {
  const char* const name; // name, only used for logging
  value_t* const value; // new value for current cell
  step_t* const step; // gets next cell
  long* count; // number of actions so far
  virtual void print();
  action(const char* name, state* current, state* next, value* value, step* step, long* count);
  state* const current; // current state
  state* const next; // next state
  virtual void do_cell() = 0;
  virtual void do_next() = 0;
} action_t;

#endif
