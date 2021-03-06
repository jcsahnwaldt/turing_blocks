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
  Goto(const char* name, State& current, State& next, Value& value, Step& step, long& count, long max = -1);
  void do_cell() override;
  void do_next() override;
};

#endif
