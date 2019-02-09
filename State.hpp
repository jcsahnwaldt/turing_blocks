#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

struct Cell;
struct Trans;

struct State final {
  const char* name;

  Trans* trans0;
  Trans* trans1;

  State(const char* name);

  Trans* trans = nullptr; // current trans
  Cell* cell = nullptr; // current cell

  void go();
};

std::ostream& operator<<(std::ostream& os, const State* state);

#endif