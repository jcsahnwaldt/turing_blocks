#ifndef STEP_HPP
#define STEP_HPP

#include <iostream>

class action;

struct step {
  action* action;
  virtual void do_move() = 0;
  virtual void print(std::ostream&) const = 0;
};

struct stepLeft final : step {
  void do_move() override;
  void print(std::ostream&) const override;
};

struct stepRight final : step {
  void do_move() override;
  void print(std::ostream&) const override;
};

struct stepNone final : step {
  void do_move() override;
  void print(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const step*);

#endif
