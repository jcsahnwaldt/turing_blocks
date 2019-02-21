#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>

class Cell;

struct Step {
  Cell* cell;
  virtual void go() = 0;
  virtual void print(std::ostream&) const = 0;
};

struct StepLeft final : Step {
  void go() override;
  void print(std::ostream&) const override;
};

struct StepRight final : Step {
  void go() override;
  void print(std::ostream&) const override;
};

struct StepNone final : Step {
  void go() override;
  void print(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const Step*);

#endif
