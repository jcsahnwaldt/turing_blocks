
#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Action.hpp"
#include "Value.hpp"

State::State(const char* n) :
  name(n) {}

void State::go() {
  cell->value->state = this;
  cell->value->go();
  action->cell = cell;
  action->go();
}

std::ostream& operator<<(std::ostream& os, const State* state) {
  os << state->name;
  return os;
}
