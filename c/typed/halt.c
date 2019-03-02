
#include "halt.h"

#include <iostream>

#include "Value.h"
#include "Step.h"
#include "cell.h"
#include "State.h"

halt::halt(const char* n, State& s, Value& v, Step& t, long& c) :
  action(n, s, s, v, t, c) {}

void halt::print() {
  action::print();
  std::cout << "halt" << std::endl;
}

void halt::do_cell() {
  ++count;
  print();
  current->cell->value = value;
  step->action = this;
  step->do_move();
}

void halt::do_next() {
  // halt
}
