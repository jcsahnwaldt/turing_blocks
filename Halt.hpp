#ifndef HALT_HPP
#define HALT_HPP

#include "Action.hpp"

class Halt final : public Action {
protected:
  void print() override;
public:
  Halt(const char* n, State* current, State* next, Value* value, Step* step, long& count);
  void do_next() override;
};

#endif
