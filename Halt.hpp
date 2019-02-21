#ifndef HALT_HPP
#define HALT_HPP

#include "Action.hpp"

struct Halt final : Action {
protected:
  void print();
public:
  Halt(const char* n, Value* value, Step* step, long& count, long max = 0);
  void go();
};

#endif
