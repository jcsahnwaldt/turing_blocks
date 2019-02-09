#ifndef HALT_HPP
#define HALT_HPP

#include "Trans.hpp"

struct Halt final : Trans {
  void go();
  ~Halt();
};

#endif
