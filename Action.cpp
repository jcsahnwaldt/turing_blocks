
#include "Action.hpp"

#include <iostream>

Action::Action(const char* n, Value* v, Step* s) : name(n), value(v), step(s) {
  std::cout << "Action constructor: " << name << std::endl;
}

Action::~Action() {
  std::cout << "Action destructor: " << name << std::endl;
}

int Action::count;
int Action::maxCount;
