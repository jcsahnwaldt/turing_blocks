
#include "Action.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Action::Action(const char* n, Value* v, Step* sp, State* st) : Transition::Transition(n, v, sp), state(st) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
static void print(Action* p) {
  std::cout << "Transition " << Transition::count << ": "  << p->name << ": set " << p->value << ", move " << p->step << ", goto " << p->state << std::endl;
}

void Action::go() {
  ++count;
  print(this);
  if (count == maxCount) return;
  cell->value = value;
  step->cell = cell;
  step->go();
  state->cell = step->cell;
  state->go();
}
