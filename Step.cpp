
#include "Step.hpp"

#include "Action.hpp"
#include "State.hpp"
#include "Cell.hpp"

void StepLeft::go() {
  action->next->cell = action->current->cell->left();
  action->go_1();
}

void StepLeft::print(std::ostream& os) const {
  os << "LEFT";
}

void StepRight::go() {
  action->next->cell = action->current->cell->right();
  action->go_1();
}

void StepRight::print(std::ostream& os) const {
  os << "RIGHT";
}

void StepNone::go() {
  action->next->cell = action->current->cell;
  action->go_1();
}

void StepNone::print(std::ostream& os) const {
  os << "NONE";
}

std::ostream& operator<<(std::ostream& os, const Step* step) {
  step->print(os);
  return os;
}
