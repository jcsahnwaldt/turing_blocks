
#include "goto.h"

#include <iostream>

#include "Value.h"
#include "Step.h"
#include "cell.h"
#include "State.h"

goto::goto(const char* n, State& cs, State& ns, Value& v, Step& t, long& c, long m) :
  action(n, cs, ns, v, t, c), max(m) {}

void goto::print() {
  action::print();
  std::cout << "goto " << next << std::endl;
}

void goto::do_cell() {
  ++count;
  print();
  current->cell->value = value;
  step->action = this;
  step->do_move();
}

void goto::do_next() {
  if (max >= 0 && count >= max) return;
  next->go();
}
