
#include "Action.hpp"

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Action::Action(const char* n, Value* v, Step* s, long& c) :
  name(n), value(v), step(s), count(c) {}

void Action::go_0() {
  ++count;
  print();
  cell->value = value;
  step->action = this;
  step->go();
}
