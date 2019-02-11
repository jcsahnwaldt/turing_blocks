
#include "Transition.hpp"

#include <iostream>

Transition::Transition(const char* n, Val* v, Step* s) : name(n), val(v), step(s) {
  std::cout << "Transition constructor: " << name << std::endl;
}

Transition::~Transition() {
  std::cout << "Transition destructor: " << name << std::endl;
}

int Transition::count;
