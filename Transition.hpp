#ifndef TRANSITION_HPP
#define TRANSITION_HPP

struct Value;
struct Step;
struct Cell;

struct Transition {
  static int count; // number of transitions so far
  static int maxCount; // max number of transitions, <= 0 means unbounded

  const char* const name;
  Value* const value; // new value for current cell
  Step* const step; // gets next cell

  Transition(const char* name, Value* value, Step* step);
  virtual ~Transition();

  Cell* cell = nullptr; // current cell
  virtual void go() = 0;
};

#endif
