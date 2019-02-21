
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, Value* v, Step* sp, long& c) :
  Action::Action(n, v, sp, c) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
void Halt::print() {
  std::cout << "Action " << count << ": "  << name << ": set " << cell << " from " << cell->value << " to " << value << ", move " << step << ", halt" << std::endl;
}

void Halt::go_1() {
  // halt
}
