#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>

struct Val;

struct Cell final {
private:
  const int id;
  Cell* _left = nullptr;
  Cell* _right = nullptr;
public:
  static int count; // number of cells created
  static Val* def; // default value
  Val* val; // current value

  Cell();
  Cell* left();
  Cell* right();
  ~Cell();
};

#endif