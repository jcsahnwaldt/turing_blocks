#ifndef GOTO_HPP
#define GOTO_HPP

#include "action.h"

class state;

class goto final : public action {
private:
  const long max; // max number of actions, < 0 means unbounded
protected:
  void print() override;
public:
  goto(const char* name, state& current, state& next, Value& value, Step& step, long& count, long max = -1);
  void do_cell() override;
  void do_next() override;
};

#endif
