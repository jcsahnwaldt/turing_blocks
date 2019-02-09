#ifndef ACTION_HPP
#define ACTION_HPP

#include "Trans.hpp"

struct Step;
struct State;
struct Val;

struct Action final : Trans {
  Val* const val; // new value for current cell
  Step* const step; // gets next cell
  State* const state; // next state

  Action(Val* v, Step* sp, State* st);
  void go();
  ~Action();
};

#endif
