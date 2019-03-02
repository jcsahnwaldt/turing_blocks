
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"
#include "State.hpp"

Halt::Halt(const char* n, State& s, Value& v, Step& t, long& c) :
  Action(n, s, s, v, t, c) {}

void Halt::print() {
  Action::print();
  std::cout << "halt" << std::endl;
}

void Halt::do_cell() {
  ++count;
  print();
  current->cell->value = value;
  step->action = this;
  step->do_move();
}

void Halt::do_next() {
  // halt
}
