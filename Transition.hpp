#ifndef TRANS_HPP
#define TRANS_HPP

struct Cell;

struct Trans {
  static int count; // number of transitions so far

  Cell* cell = nullptr; // current cell
  virtual void go() = 0;
  virtual ~Trans();
};

#endif
