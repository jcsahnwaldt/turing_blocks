#ifndef HALT_HPP
#define HALT_HPP

#include "action.h"

class Halt final : public action {
protected:
  void print() override;
public:
  Halt(const char* name, State& state, Value& value, Step& step, long& count);
  void do_cell() override;
  void do_next() override;
};

#endif
