#ifndef STEP_H
#define STEP_H

typedef struct action_t action_t;

typedef struct step_t step_t;
struct step_t {
  const char* name;
  action_t* action;
  void (*do_move)(step_t*);
};

void step_init_left(step_t*);
void step_init_right(step_t*);
void step_init_none(step_t*);

#endif
