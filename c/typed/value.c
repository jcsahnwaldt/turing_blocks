
#include "value.h"

#include "state.h"
#include "action.h"

void value0::do_action() {
  state->action0->do_cell();
}

void value0::print(std::ostream& os) const {
  os << "ZERO";
}

void value1::do_action() {
  state->action1->do_cell();
}

void value1::print(std::ostream& os) const {
  os << "ONE";
}

std::ostream& operator<<(std::ostream& os, const value* value) {
  value->print(os);
  return os;
}
