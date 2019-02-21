
#include "Action.hpp"

#include "Value.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

void Action::print() {
  std::cout << "Action " << count << ": " << name << ": "
  << "set " << current->cell << " from " << current->cell->value << " to " << value << ", "
  << "move " << step << ", ";
}
