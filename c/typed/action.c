
#include "action.h"

#include "value.h"
#include "step.h"
#include "state.h"
#include "cell.h"

#include "method.h"
#include <stdio.h>

static void action_print(action_t* a) {
  printf("action %ld: %s: ", *a->counter, a->name);
  printf("set cell %ld from %s to %s, ", a->current->cell->id, a->current->cell->value->name, a->value->name);
  printf("move %s, ", a->step->name);
}

static void do_cell(action_t* a) {
  (*a->counter)++;
  a->print(a);
  a->current->cell->value = a->value;
  a->step->action = a;
  CALL(a->step, do_move);
}

static void goto_next(action_t* a) {
  if (a->max >= 0 && *a->counter >= a->max) return;
  CALL(a->next, go);
}

static void goto_print(action_t* a) {
  action_print(a);
  printf("goto %s\n", a->next->name);
}

void goto_init(action_t* a, const char* n, state_t* cs, state_t* ns, value_t* v, step_t* t, long* c, long m) {
  a->name = n;
  a->counter = c;
  a->max = m;

  a->current = cs;
  a->next = ns;
  a->value = v;
  a->step = t;

  a->do_cell = do_cell;
  a->do_next = goto_next;
  a->print = goto_print;
}

static void halt_print(action_t* a) {
  action_print(a);
  printf("halt\n");
}

static void halt_next() {
  // halt
}

void halt_init(action_t* a, const char* n, state_t* s, value_t* v, step_t* t, long* c) {
  a->name = n;
  a->counter = c;
  a->max = -1;

  a->current = s;
  a->next = s;
  a->value = v;
  a->step = t;

  a->do_cell = do_cell;
  a->do_next = halt_next;
  a->print = halt_print;
}
