
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

Goto::Goto(const char* n, Value* v, Step* sp, State* st, long& c, long m) :
  Action::Action(n, v, sp, c), max(m), state(st) {}

void Goto::print() {
  Action::print();
  std::cout << "goto " << state << std::endl;
}

void Goto::go_1() {
  state->cell = cell;
  if (max < 0 || count < max) state->go();
}
