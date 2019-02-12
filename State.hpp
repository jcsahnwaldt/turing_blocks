#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

struct Cell;
struct Action;

struct State final {
  const char* const name;

  Action* action0;
  Action* action1;

  State(const char* name);
  ~State();

  Action* action = nullptr; // current action
  Cell* cell = nullptr; // current cell

  void go();
};

std::ostream& operator<<(std::ostream& os, const State* state);

#endif
