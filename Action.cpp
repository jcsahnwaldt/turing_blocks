
#include "Action.hpp"

#include "Value.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Action::Action(const char* n, State* cs, State* ns, Value* v, Step* s, long& c) :
  name(n), value(v), step(s), count(c), current(cs), next(ns) {}

void Action::print() {
  std::cout << "Action " << count << ": " << name << ": "
  << "set " << current->cell << " from " << current->cell->value << " to " << value << ", "
  << "move " << step << ", ";
}
