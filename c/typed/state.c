
#include "state.h"
#include "cell.h"
#include "action.h"
#include "value.h"

void go(state_t* s) {
  value_t* v = s->cell->value;
  v->state = s;
  v->do_action(v);
}

void state_init(state_t* s, const char* n, action_t* a_0, action_t* a_1) {
  s->name = n;
  s->action_0 = a_0;
  s->action_1 = a_1;
  s->go = go;
}
