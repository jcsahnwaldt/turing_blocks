
#include "Action.h"

#include "Value.h"
#include "Step.h"
#include "State.h"
#include "Cell.h"

Action::Action(const char* n, State& cs, State& ns, Value& v, Step& t, long& c) :
  name(n), value(&v), step(&t), count(c), current(&cs), next(&ns) {}

void Action::print() {
  std::cout << "Action " << count << ": " << name << ": "
  << "set " << current->cell << " from " << current->cell->value << " to " << value << ", "
  << "move " << step << ", ";
}
