#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>

class state;

struct Value {
  state* state;
  virtual void do_action() = 0;
  virtual void print(std::ostream&) const = 0;
};

struct Value0 final : Value {
  void do_action() override;
  void print(std::ostream&) const override;
};

struct Value1 final : Value {
  void do_action() override;
  void print(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, const Value*);

#endif
