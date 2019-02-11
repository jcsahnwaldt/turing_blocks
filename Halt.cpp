
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, Value* v, Step* sp) : Transition::Transition(n, v, sp) {}

void Halt::go() {
  std::cout << "Transition " << ++count << ": "  << name << ": set " << value << ", move " << step << ", halt" << std::endl;
  cell->value = value;
  step->cell = cell;
  step->go();
  // halt
}
