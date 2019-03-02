
#include "halt.h"

#include <iostream>

#include "value.h"
#include "step.h"
#include "cell.h"
#include "state.h"

halt::halt(const char* n, state& s, value& v, step& t, long& c) :
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
