#ifndef TRANSITION_HPP
#define TRANSITION_HPP

struct Val;
struct Step;
struct Cell;

struct Transition {
  static int count; // number of transitions so far

  const char* const name;
  Val* const val; // new value for current cell
  Step* const step; // gets next cell

  Transition(const char* name, Val* val, Step* step);
  virtual ~Transition();

  Cell* cell = nullptr; // current cell
  virtual void go() = 0;
};

#endif
