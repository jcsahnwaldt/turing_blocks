
#include "Halt.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "Cell.hpp"

Halt::Halt(const char* n, Value* v, Step* sp) : Transition::Transition(n, v, sp) {}

__attribute__((noinline)) // if this is inline, clang doesn't optimize tail-calls :-(
static void print(Halt* p) {
  std::cout << "Transition " << Transition::count << ": "  << p->name << ": set " << p->value << ", move " << p->step << ", halt" << std::endl;
}

void Halt::go() {
  ++count;
  print(this);
  cell->value = value;
  step->cell = cell;
  step->go();
  // halt
}
