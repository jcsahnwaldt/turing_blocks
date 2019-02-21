
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, State* cs, State* ns, Value* v, Step* sp, long& c) :
  Action::Action(n, cs, ns, v, sp, c) {}

void Halt::print() {
  Action::print();
  std::cout << "halt" << std::endl;
}

void Halt::go_1() {
  // halt
}
