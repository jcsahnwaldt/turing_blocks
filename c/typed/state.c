
#include <iostream>

#include "state.h"
#include "cell.h"
#include "action.h"
#include "Value.h"

state::state(const char* n, action& a0, action& a1) :
  name(n), action0(&a0), action1(&a1) {}

void state::go() {
  cell->value->state = this;
  cell->value->do_action();
}

std::ostream& operator<<(std::ostream& os, const state* state) {
  os << state->name;
  return os;
}
