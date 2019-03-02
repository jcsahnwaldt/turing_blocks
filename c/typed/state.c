
#include "state.h"
#include "cell.h"
#include "action.h"
#include "value.h"

#include "method.h"

void go(state_t* s) {
  s->cell->value->state = s;
  CALL(s->cell->value, do_action);
}

void state_init(state_t* s, const char* n, action_t* a_0, action_t* a_1) {
  s->name = n;
  s->action_0 = a_0;
  s->action_1 = a_1;
  s->go = go;
}
