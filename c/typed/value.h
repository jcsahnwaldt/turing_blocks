#ifndef VALUE_H
#define VALUE_H

#include <iostream>

struct state;

struct value {
  state* state;
  virtual void do_action() = 0;
  virtual void print(std::ostream&) const = 0;
};

struct value0 final : value {
  void do_action() override;
  void print(std::ostream&) const override;
};

struct value1 final : value {
  void do_action() override;
  void print(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const value*);

#endif
