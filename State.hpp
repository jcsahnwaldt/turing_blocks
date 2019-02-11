#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

struct Cell;
struct Transition;

struct State final {
  const char* const name;

  Transition* trans0;
  Transition* trans1;

  State(const char* name);
  ~State();

  Transition* trans = nullptr; // current transition
  Cell* cell = nullptr; // current cell

  void go();
};

std::ostream& operator<<(std::ostream& os, const State* state);

#endif