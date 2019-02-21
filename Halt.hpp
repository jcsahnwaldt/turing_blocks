#ifndef HALT_HPP
#define HALT_HPP

#include "Action.hpp"

class Halt final : public Action {
protected:
  void print() override;
public:
  Halt(const char* n, Value* value, Step* step, long& count);
  void go_1() override;
};

#endif
