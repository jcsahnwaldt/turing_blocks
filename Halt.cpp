
#include "Halt.hpp"

#include <iostream>

#include "Val.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, Val* v, Step* sp) : Transition::Transition(n, v, sp) {}

void Halt::go() {
  std::cout << "Transition " << ++count << ": "  << name << ": set " << val << ", move " << step << ", halt" << std::endl;
  cell->val = val;
  step->cell = cell;
  step->go();
  // halt
}
