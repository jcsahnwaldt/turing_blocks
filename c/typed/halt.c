
#include "Halt.h"

#include <iostream>

#include "Value.h"
#include "Step.h"
#include "cell.h"
#include "State.h"

Halt::Halt(const char* n, State& s, Value& v, Step& t, long& c) :
  action(n, s, s, v, t, c) {}

void Halt::print() {
  action::print();
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
