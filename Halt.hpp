#ifndef HALT_HPP
#define HALT_HPP

#include "Transition.hpp"

struct Halt final : Transition {
  Halt(const char* n, Value* value, Step* step);
  void go();
};

#endif
