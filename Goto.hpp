#ifndef GOTO_HPP
#define GOTO_HPP

#include "Action.hpp"

class State;

class Goto final : public Action {
private:
  const long max; // max number of actions, < 0 means unbounded
protected:
  void print() override;
public:
  Goto(const char* n, State* current, State* next, Value* value, Step* step, long& count, long max = -1);
  void go_1() override;
};

#endif
