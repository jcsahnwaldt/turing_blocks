
#include "step.h"

#include "action.h"
#include "state.h"
#include "cell.h"

#include "method.h"

static void move_left(step_t* s) {
  s->action->next->cell = CALL(s->action->current->cell, left);
  CALL(s->action, do_next);
}

void step_init_left(step_t* s) {
  s->name = "LEFT";
  s->do_move = move_left;
}

static void move_right(step_t* s) {
  s->action->next->cell = CALL(s->action->current->cell, right);
  CALL(s->action, do_next);
}

void step_init_right(step_t* s) {
  s->name = "RIGHT";
  s->do_move = move_right;
}

static void move_none(step_t* s) {
  s->action->next->cell = s->action->current->cell;
  CALL(s->action, do_next);
}

void step_init_none(step_t* s) {
  s->name = "NONE";
  s->do_move = move_none;
}
