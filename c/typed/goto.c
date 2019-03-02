
#include "Goto.h"

#include <iostream>

#include "Value.h"
#include "Step.h"
#include "Cell.h"
#include "State.h"

Goto::Goto(const char* n, State& cs, State& ns, Value& v, Step& t, long& c, long m) :
  action(n, cs, ns, v, t, c), max(m) {}

void Goto::print() {
  action::print();
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
