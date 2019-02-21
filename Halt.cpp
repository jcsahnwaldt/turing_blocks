
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

void Halt::print() {
  Action::print();
  std::cout << "halt" << std::endl;
}

void Halt::do_cell() {
  current->cell->value = value;
  step->action = this;
  step->do_move();
}

void Halt::do_next() {
  ++count;
  print();
  // halt
}
