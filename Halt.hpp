#ifndef HALT_HPP
#define HALT_HPP

#include "Action.hpp"

struct Halt final : Action {
  Halt(const char* n, Value* value, Step* step);
  void go();
};

#endif
