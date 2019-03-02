
#include "value.h"

#include "state.h"
#include "action.h"

#include "method.h"

static void do_action_0(value_t* v) {
  CALL(v->state->action_0, do_cell);
}

void value_init_0(value_t* v) {
  v->name = "ZERO";
  v->do_action = do_action_0;
}

static void do_action_1(value_t* v) {
  CALL(v->state->action_1, do_cell);
}

void value_init_1(value_t* v) {
  v->name = "ONE";
  v->do_action = do_action_1;
}
