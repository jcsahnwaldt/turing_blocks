#ifndef ACTION_H
#define ACTION_H

struct value;
struct step;
class state;

class action {
protected:
  const char* const name; // name, only used for logging
  value* const value; // new value for current cell
  step* const step; // gets next cell
  long& count; // number of actions so far
  virtual void print();
public:
  action(const char* name, state& current, state& next, value& value, step& step, long& count);
  state* const current; // current state
  state* const next; // next state
  virtual void do_cell() = 0;
  virtual void do_next() = 0;
};

#endif
