
#include "Value.hpp"

#include "State.hpp"

void Value0::go() { state->trans = state->trans0; }
void Value0::print(std::ostream& os) const { os << "ZERO"; }

void Value1::go() { state->trans = state->trans1; }
void Value1::print(std::ostream& os) const { os << "ONE"; }

std::ostream& operator<<(std::ostream& os, const Value* value) {
  value->print(os);
  return os;
}
