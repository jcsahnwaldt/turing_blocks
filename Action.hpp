#ifndef ACTION_HPP
#define ACTION_HPP

struct Value;
struct Step;
struct Cell;

struct Action {
protected:
  const char* const name; // name, only used for logging
  Value* const value; // new value for current cell
  Step* const step; // gets next cell
  long& count; // number of actions so far
  const long max; // max number of actions, <= 0 means unbounded
  virtual void print() = 0;
public:
  Action(const char* name, Value* value, Step* step, long& count, long max = 0);
  Cell* cell = nullptr; // current cell
  virtual void go() = 0;
};

#endif
