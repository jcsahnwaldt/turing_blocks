#ifndef ACTION_HPP
#define ACTION_HPP

struct Value;
struct Step;
class State;

class Action {
protected:
  const char* const name; // name, only used for logging
  Value* const value; // new value for current cell
  Step* const step; // gets next cell
  long& count; // number of actions so far
  virtual void print();
public:
  Action(const char* name, State& current, State& next, Value& value, Step& step, long& count);
  State* const current; // current state
  State* const next; // next state
  virtual void do_cell() = 0;
  virtual void do_next() = 0;
};

#endif
