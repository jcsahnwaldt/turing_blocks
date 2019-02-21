#ifndef ACTION_HPP
#define ACTION_HPP

struct Value;
struct Step;
class Cell;

class Action {
protected:
  const char* const name; // name, only used for logging
  Value* const value; // new value for current cell
  Step* const step; // gets next cell
  long& count; // number of actions so far
  virtual void print();
public:
  Action(const char* name, Value* value, Step* step, long& count);
  Cell* cell = nullptr; // current cell
  virtual void go_0();
  virtual void go_1() = 0;
};

#endif
