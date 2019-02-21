
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, Value* v, Step* sp, long& c, long m) :
  Action::Action(n, v, sp, c, m) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
void Halt::print() {
  std::cout << "Action " << count << ": "  << name << ": set " << cell << " to " << value << ", move " << step << ", halt" << std::endl;
}

void Halt::go() {
  ++count;
  print();
  cell->value = value;
  step->cell = cell;
  step->go();
  // halt
}
