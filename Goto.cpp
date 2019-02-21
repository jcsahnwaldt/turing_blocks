
#include "Goto.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

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
