
#include "Val.hpp"

#include "State.hpp"

void Val0::go() { state->trans = state->trans0; }
void Val0::print(std::ostream& os) const { os << "ZERO"; }

void Val1::go() { state->trans = state->trans1; }
void Val1::print(std::ostream& os) const { os << "ONE"; }

std::ostream& operator<<(std::ostream& os, const Val* val) {
  val->print(os);
  return os;
}
