#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

class cell;
class action;

class state final {
private:
  const char* const name;
  friend std::ostream& operator<<(std::ostream&, const state*);
public:
  state(const char* name, action& action0, action& action1);
  action* const action0;
  action* const action1;

  cell* cell = nullptr; // current cell
  void go();
};

std::ostream& operator<<(std::ostream&, const state*);

#endif
