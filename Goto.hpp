#ifndef GOTO_HPP
#define GOTO_HPP

#include "Action.hpp"

class State;

class Goto final : public Action {
private:
  const long max; // max number of actions, < 0 means unbounded
protected:
  void print() override;
public:
  template<class States>
  Goto(const char* name, const States& states, int current, int next, Value* value, Step* step, long& count, long max = -1) :
    Action(name, states, current, next, value, step, count), max(max) {}
  void do_cell() override;
  void do_next() override;
};

#endif
