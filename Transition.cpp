
#include "Transition.hpp"

#include <iostream>

Transition::Transition(const char* n, Value* v, Step* s) : name(n), value(v), step(s) {
  std::cout << "Transition constructor: " << name << std::endl;
}

Transition::~Transition() {
  std::cout << "Transition destructor: " << name << std::endl;
}

int Transition::count;
