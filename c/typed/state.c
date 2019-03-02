
#include <iostream>

#include "State.h"
#include "Cell.h"
#include "Action.h"
#include "Value.h"

State::State(const char* n, Action& a0, Action& a1) :
  name(n), action0(&a0), action1(&a1) {}

void State::go() {
  cell->value->state = this;
  cell->value->do_action();
}

std::ostream& operator<<(std::ostream& os, const State* state) {
  os << state->name;
  return os;
}
