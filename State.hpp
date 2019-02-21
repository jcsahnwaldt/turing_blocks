#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

class Cell;
class Action;

class State final {
private:
  const char* const name;
  friend std::ostream& operator<<(std::ostream&, const State*);
public:
  State(const char* name);

  Action* action0; // TODO: should be Action* const
  Action* action1; // TODO: should be Action* const

  Cell* cell = nullptr; // current cell
  void go();
};

std::ostream& operator<<(std::ostream&, const State*);

#endif
