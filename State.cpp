#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Trans.hpp"
#include "Val.hpp"

State::State(const char* n) : name(n) {}

void State::go() {
  cell->val->state = this;
  cell->val->go();
  trans->cell = cell;
  trans->go();
}

std::ostream& operator<<(std::ostream& os, const State* state) {
  os << state->name;
  return os;
}
