
#include "action.h"

#include "value.h"
#include "step.h"
#include "state.h"
#include "cell.h"

action::action(const char* n, state& cs, state& ns, value& v, step& t, long& c) :
  name(n), value(&v), step(&t), count(c), current(&cs), next(&ns) {}

void action::print() {
  std::cout << "action " << count << ": " << name << ": "
  << "set " << current->cell << " from " << current->cell->value << " to " << value << ", "
  << "move " << step << ", ";
}
