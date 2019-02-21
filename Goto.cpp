
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Goto::Goto(const char* n, Value* v, Step* sp, State* st, long& c, long m) :
  Action::Action(n, v, sp, c, m), state(st) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
void Goto::print() {
  std::cout << "Action " << count << ": "  << name << ": set " << cell << " to " << value << ", move " << step << ", goto " << state << std::endl;
}

void Goto::go() {
  ++count;
  print();
  if (count == max) return;
  cell->value = value;
  step->cell = cell;
  step->go();
  state->cell = step->cell;
  state->go();
}
