#ifndef GOTO_HPP
#define GOTO_HPP

#include "Action.hpp"

struct State;

struct Goto final : Action {
  State* const state; // next state
  Goto(const char* n, Value* value, Step* step, State* state);
  void go();
};

#endif