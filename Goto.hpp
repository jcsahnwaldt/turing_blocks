#ifndef GOTO_HPP
#define GOTO_HPP

#include "Action.hpp"

struct State;

struct Goto final : Action {
protected:
  void print();
public:
  State* const state; // next state
  Goto(const char* n, Value* value, Step* step, State* state, long& count, long max = 0);
  void go();
};

#endif
