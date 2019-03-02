#ifndef ACTION_HPP
#define ACTION_HPP

struct Value;
struct step;
class state;

class action {
protected:
  const char* const name; // name, only used for logging
  Value* const value; // new value for current cell
  step* const step; // gets next cell
  long& count; // number of actions so far
  virtual void print();
public:
  action(const char* name, state& current, state& next, Value& value, step& step, long& count);
  state* const current; // current state
  state* const next; // next state
  virtual void do_cell() = 0;
  virtual void do_next() = 0;
};

#endif
