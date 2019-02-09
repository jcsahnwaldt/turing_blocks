#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>

struct Cell;

struct Step {
  Cell* cell;
  virtual void go() = 0;
  virtual void print(std::ostream& os) const = 0;
};

struct StepLeft final : Step {
  void go();
  void print(std::ostream& os) const;
};

struct StepRight final : Step {
  void go();
  void print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Step* step);

#endif
