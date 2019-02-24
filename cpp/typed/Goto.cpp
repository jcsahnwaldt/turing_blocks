
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

Goto::Goto(const char* n, State& cs, State& ns, Value& v, Step& t, long& c, long m) :
  Action(n, cs, ns, v, t, c), max(m) {}

void Goto::print() {
  Action::print();
  std::cout << "goto " << next << std::endl;
}

void Goto::do_cell() {
  ++count;
  print();
  current->cell->value = value;
  step->action = this;
  step->do_move();
}

void Goto::do_next() {
  if (max >= 0 && count >= max) return;
  next->go();
}
