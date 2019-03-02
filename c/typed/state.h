#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

class Cell;
class action;

class State final {
private:
  const char* const name;
  friend std::ostream& operator<<(std::ostream&, const State*);
public:
  State(const char* name, action& action0, action& action1);
  action* const action0;
  action* const action1;

  Cell* cell = nullptr; // current cell
  void go();
};

std::ostream& operator<<(std::ostream&, const State*);

#endif
