
#include "step.h"

#include "action.h"
#include "state.h"
#include "cell.h"

void stepLeft::do_move() {
  action->next->cell = action->current->cell->left();
  action->do_next();
}

void stepLeft::print(std::ostream& os) const {
  os << "LEFT";
}

void stepRight::do_move() {
  action->next->cell = action->current->cell->right();
  action->do_next();
}

void stepRight::print(std::ostream& os) const {
  os << "RIGHT";
}

void stepNone::do_move() {
  action->next->cell = action->current->cell;
  action->do_next();
}

void stepNone::print(std::ostream& os) const {
  os << "NONE";
}

std::ostream& operator<<(std::ostream& os, const step* step) {
  step->print(os);
  return os;
}
