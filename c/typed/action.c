
#include "action.h"

#include "Value.h"
#include "Step.h"
#include "State.h"
#include "cell.h"

action::action(const char* n, State& cs, State& ns, Value& v, Step& t, long& c) :
  name(n), value(&v), step(&t), count(c), current(&cs), next(&ns) {}

void action::print() {
  std::cout << "action " << count << ": " << name << ": "
  << "set " << current->cell << " from " << current->cell->value << " to " << value << ", "
  << "move " << step << ", ";
}
