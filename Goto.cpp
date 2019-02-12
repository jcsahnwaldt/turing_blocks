
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Goto::Goto(const char* n, Value* v, Step* sp, State* st) : Action::Action(n, v, sp), state(st) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
static void print(Goto* p) {
  std::cout << "Action " << Action::count << ": "  << p->name << ": set " << p->value << ", move " << p->step << ", goto " << p->state << std::endl;
}

void Goto::go() {
  ++count;
  print(this);
  if (count == maxCount) return;
  cell->value = value;
  step->cell = cell;
  step->go();
  state->cell = step->cell;
  state->go();
}
