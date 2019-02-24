
#include "Value.hpp"

#include "State.hpp"
#include "Action.hpp"

void Value0::do_action() {
  state->action0->do_cell();
}

void Value0::print(std::ostream& os) const {
  os << "ZERO";
}

void Value1::do_action() {
  state->action1->do_cell();
}

void Value1::print(std::ostream& os) const {
  os << "ONE";
}

std::ostream& operator<<(std::ostream& os, const Value* value) {
  value->print(os);
  return os;
}
