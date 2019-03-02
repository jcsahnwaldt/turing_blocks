
#include "value.h"

#include "state.h"
#include "action.h"

static void do_action_0(value_t* v) {
  action_t* a = v->state->action_0;
  a->do_cell(a);
}

void value_init_0(value_t* v) {
  v->name = "ZERO";
  v->do_action = do_action_0;
}

static void do_action_1(value_t* v) {
  action_t* a = v->state->action_1;
  a->do_cell(a);
}

void value_init_1(value_t* v) {
  v->name = "ONE";
  v->do_action = do_action_1;
}
