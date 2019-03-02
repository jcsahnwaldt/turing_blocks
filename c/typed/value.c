
#include "value.h"

#include "state.h"
#include "action.h"

#include "method.h"

static void do_action_0(value_t* v) {
  CALL(v->state->action_0, do_cell);
}

static void do_action_1(value_t* v) {
  CALL(v->state->action_1, do_cell);
}

void init_value_0(value_t* v) {
  v->name = "ZERO";
  v->do_action = do_action_0;
}

void init_value_1(value_t* v) {
  v->name = "ONE";
  v->do_action = do_action_1;
}
