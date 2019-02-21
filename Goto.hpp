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
  State* const state; // next state
  Goto(const char* n, Value* value, Step* step, State* state, long& count, long max = -1);
  void go_1() override;
};

#endif
