
#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Action.hpp"
#include "Value.hpp"

void State::go() {
  cell->value->state = this;
  cell->value->do_action();
}

std::ostream& operator<<(std::ostream& os, const State* state) {
  os << state->name;
  return os;
}
