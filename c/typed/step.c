
#include "step.h"

#include "action.h"
#include "state.h"
#include "cell.h"

static void move_left(step_t* s) {
  action_t* a = s->action;
  a->next->cell = left(a->current->cell);
  a->do_next(a);
}

void step_init_left(step_t* s) {
  s->name = "LEFT";
  s->do_move = move_left;
}

static void move_right(step_t* s) {
  action_t* a = s->action;
  a->next->cell = right(a->current->cell);
  a->do_next(a);
}

void step_init_right(step_t* s) {
  s->name = "RIGHT";
  s->do_move = move_right;
}

static void move_none(step_t* s) {
  action_t* a = s->action;
  a->next->cell = a->current->cell;
  a->do_next(a);
}

void step_init_none(step_t* s) {
  s->name = "NONE";
  s->do_move = move_none;
}
