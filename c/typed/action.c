
#include "action.h"

#include "value.h"
#include "step.h"
#include "state.h"
#include "cell.h"

#include "method.h"
#include <stdio.h>

unsigned long action_count = 0;
unsigned long action_count_max = 0;

static void print_action(action_t* a) {
  printf("action %ld: %s: ", action_count, a->name);
  printf("set cell %ld from %s to %s, ", a->current->cell->id, a->current->cell->value->name, a->value->name);
  printf("move %s, ", a->step->name);
}

static void print_goto(action_t* a) {
  print_action(a);
  printf("goto %s\n", a->next->name);
}

static void print_halt(action_t* a) {
  print_action(a);
  printf("halt\n");
}

static void do_cell_goto(action_t* a) {
  action_count++;
  print_goto(a);

  a->current->cell->value = a->value;
  a->step->action = a;
  CALL(a->step, do_move);
}

static void do_cell_halt(action_t* a) {
  action_count++;
  print_halt(a);

  a->current->cell->value = a->value;
  a->step->action = a;
  CALL(a->step, do_move);
}

static void do_next_goto(action_t* a) {
  if (action_count_max > 0 && action_count >= action_count_max) return;

  CALL(a->next, go);
}

static void do_next_halt() {
  // halt
}

static void init_action(action_t* a, const char* n, state_t* cs, state_t* ns, value_t* v, step_t* t) {
  a->name = n;

  a->current = cs;
  a->next = ns;
  a->value = v;
  a->step = t;
}

void init_goto(action_t* a, const char* n, state_t* cs, state_t* ns, value_t* v, step_t* t) {
  init_action(a, n, cs, ns, v, t);
  a->do_cell = do_cell_goto;
  a->do_next = do_next_goto;
}

void init_halt(action_t* a, const char* n, state_t* s, value_t* v, step_t* t) {
  init_action(a, n, s, s, v, t);
  a->do_cell = do_cell_halt;
  a->do_next = do_next_halt;
}
