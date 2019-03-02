#ifndef STATE_H
#define STATE_H

struct cell_t;
struct action_t;

typedef struct state_t {
  const char* const name;
  state_t(const char* name, action_t* action0, action_t* action1);
  action_t* const action0;
  action_t* const action1;

  cell_t* cell = NULL; // current cell
  void go();
} state_t;

#endif
