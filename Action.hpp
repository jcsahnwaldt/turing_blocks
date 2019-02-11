#ifndef ACTION_HPP
#define ACTION_HPP

#include "Transition.hpp"

struct State;

struct Action final : Transition {
  State* const state; // next state
  Action(const char* n, Val* val, Step* step, State* state);
  void go();
};

#endif
