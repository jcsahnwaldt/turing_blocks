#ifndef ACTION_HPP
#define ACTION_HPP

struct Value;
struct Step;
struct Cell;

struct Action {
  static int count; // number of actions so far
  static int maxCount; // max number of actions, <= 0 means unbounded

  const char* const name;
  Value* const value; // new value for current cell
  Step* const step; // gets next cell

  Action(const char* name, Value* value, Step* step);
  virtual ~Action();

  Cell* cell = nullptr; // current cell
  virtual void go() = 0;
};

#endif
