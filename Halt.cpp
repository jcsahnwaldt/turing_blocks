
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, Value* v, Step* sp, long& c) :
  Action::Action(n, v, sp, c) {}

void Halt::print() {
  Action::print();
  std::cout << "halt" << std::endl;
}

void Halt::go_1() {
  // halt
}
