
#include "Step.hpp"

#include "Action.hpp"
#include "State.hpp"
#include "Cell.hpp"

void StepLeft::do_move() {
  action->next->cell = action->current->cell->left();
  action->do_next();
}

void StepLeft::print(std::ostream& os) const {
  os << "LEFT";
}

void StepRight::do_move() {
  action->next->cell = action->current->cell->right();
  action->do_next();
}

void StepRight::print(std::ostream& os) const {
  os << "RIGHT";
}

void StepNone::do_move() {
  action->next->cell = action->current->cell;
  action->do_next();
}

void StepNone::print(std::ostream& os) const {
  os << "NONE";
}

std::ostream& operator<<(std::ostream& os, const Step* step) {
  step->print(os);
  return os;
}
