#ifndef HALT_HPP
#define HALT_HPP

#include "Action.hpp"

class Halt final : public Action {
protected:
  void print() override;
public:
  template<class States>
  Halt(const char* name, const States& states, int state, Value* value, Step* step, long& count) :
    Action::Action(name, states, state, state, value, step, count) {}
  void do_cell() override;
  void do_next() override;
};

#endif
