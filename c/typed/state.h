#ifndef STATE_H
#define STATE_H

typedef struct cell_t cell_t;
typedef struct action_t action_t;

typedef struct state_t state_t;
struct state_t {
  const char* name;
  action_t* action_0;
  action_t* action_1;
  cell_t* cell; // current cell
  void (*go)(state_t*);
};

void state_init(state_t*, const char*, action_t*, action_t*);


#endif
