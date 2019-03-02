#ifndef HALT_HPP
#define HALT_HPP

#include "action.h"

class halt final : public action {
protected:
  void print() override;
public:
  halt(const char* name, State& state, Value& value, Step& step, long& count);
  void do_cell() override;
  void do_next() override;
};

#endif
