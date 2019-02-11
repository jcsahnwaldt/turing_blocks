#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Transition.hpp"
#include "Value.hpp"

State::State(const char* n) : name(n) {
  std::cout << "State constructor: " << name << std::endl;
}

State::~State() {
  std::cout << "State destructor: " << name << std::endl;
}

void State::go() {
  cell->value->state = this;
  cell->value->go();
  trans->cell = cell;
  trans->go();
}

std::ostream& operator<<(std::ostream& os, const State* state) {
  os << state->name;
  return os;
}
