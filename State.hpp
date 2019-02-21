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
  State(const char* name, Action& action0, Action& action1);
  Action* const action0;
  Action* const action1;

  Cell* cell = nullptr; // current cell
  void go();
};

std::ostream& operator<<(std::ostream&, const State*);

#endif
