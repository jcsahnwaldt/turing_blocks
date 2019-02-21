
#include "Step.hpp"

#include "Action.hpp"
#include "Cell.hpp"

void StepLeft::go() {
  action->cell = action->cell->left();
  action->go_1();
}

void StepLeft::print(std::ostream& os) const {
  os << "LEFT";
}

void StepRight::go() {
  action->cell = action->cell->right();
  action->go_1();
}

void StepRight::print(std::ostream& os) const {
  os << "RIGHT";
}

void StepNone::go() {
  action->go_1();
}

void StepNone::print(std::ostream& os) const {
  os << "NONE";
}

std::ostream& operator<<(std::ostream& os, const Step* step) {
  step->print(os);
  return os;
}
