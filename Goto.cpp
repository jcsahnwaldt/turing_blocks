
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

Goto::Goto(const char* n, State* cs, State* ns, Value* v, Step* s, long& c, long m) :
  Action::Action(n, cs, ns, v, s, c), max(m) {}

void Goto::print() {
  Action::print();
  std::cout << "goto " << next << std::endl;
}

void Goto::go_1() {
  if (max < 0 || count < max) next->go_0();
}
