
#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Action.hpp"
#include "Value.hpp"

State::State(const char* n) :
  name(n) {}

void State::go_0() {
  cell->value->state = this;
  cell->value->go();
}

void State::go_1() {
  action->go_0();
}

std::ostream& operator<<(std::ostream& os, const State* state) {
  os << state->name;
  return os;
}
