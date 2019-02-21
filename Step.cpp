
#include "Step.hpp"

#include "Cell.hpp"

void StepLeft::go() { cell = cell->left(); }
void StepLeft::print(std::ostream& os) const { os << "LEFT"; }

void StepRight::go() { cell = cell->right(); }
void StepRight::print(std::ostream& os) const { os << "RIGHT"; }

void StepNone::go() {}
void StepNone::print(std::ostream& os) const { os << "NONE"; }

std::ostream& operator<<(std::ostream& os, const Step* step) {
  step->print(os);
  return os;
}
