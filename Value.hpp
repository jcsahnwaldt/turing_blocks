#ifndef VAL_HPP
#define VAL_HPP

#include <iostream>

struct State;

struct Val {
  State* state;
  virtual void go() = 0;
  virtual void print(std::ostream& os) const = 0;
};

struct Val0 final : Val {
  void go();
  void print(std::ostream& os) const;
};

struct Val1 final : Val {
  void go();
  void print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Val* val);

#endif