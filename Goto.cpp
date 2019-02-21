
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

Goto::Goto(const char* n, Value* v, Step* sp, State* st, long& c, long m) :
  Action::Action(n, v, sp, c), max(m), state(st) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
void Goto::print() {
  std::cout << "Action " << count << ": "  << name << ": set " << cell << " from " << cell->value << " to " << value << ", move " << step << ", goto " << state << std::endl;
}

void Goto::go_1() {
  state->cell = cell;
  if (max < 0 || count < max) state->go();
}
