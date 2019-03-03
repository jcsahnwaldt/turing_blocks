#ifndef ACTION_H
#define ACTION_H

typedef struct value_t value_t;
typedef struct step_t step_t;
typedef struct state_t state_t;

extern unsigned long action_count; // number of actions so far
extern unsigned long action_count_max; // max number of actions, 0 means unbounded

typedef struct action_t action_t;
struct action_t {
  const char* name; // name, only used for logging

  value_t* value; // new value for current cell
  step_t* step; // gets next cell
  state_t* current; // current state
  state_t* next; // next state

  void (*do_cell)(action_t*);
  void (*do_next)(action_t*);
};

void init_goto(action_t*, const char*, state_t* cs, state_t* ns, value_t*, step_t*);
void init_halt(action_t*, const char*, state_t*, value_t*, step_t*);

#endif
