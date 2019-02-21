#ifndef GOTO_HPP
#define GOTO_HPP

#include "Action.hpp"

class State;

class Goto final : public Action {
protected:
  void print() override;
public:
  State* const state; // next state
  Goto(const char* n, Value* value, Step* step, State* state, long& count, long max = 0);
  void go() override;
};

#endif
