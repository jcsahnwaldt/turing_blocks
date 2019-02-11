#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>

struct State;

struct Value {
  State* state;
  virtual void go() = 0;
  virtual void print(std::ostream& os) const = 0;
};

struct Value0 final : Value {
  void go();
  void print(std::ostream& os) const;
};

struct Value1 final : Value {
  void go();
  void print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Value* value);

#endif
