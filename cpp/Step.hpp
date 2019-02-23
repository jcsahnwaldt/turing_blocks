#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>

class Action;

struct Step {
  Action* action;
  virtual void do_move() = 0;
  virtual void print(std::ostream&) const = 0;
};

struct StepLeft final : Step {
  void do_move() override;
  void print(std::ostream&) const override;
};

struct StepRight final : Step {
  void do_move() override;
  void print(std::ostream&) const override;
};

struct StepNone final : Step {
  void do_move() override;
  void print(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const Step*);

#endif
