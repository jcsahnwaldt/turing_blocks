#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>

struct Value;

struct Cell final {
private:
  const int id;
  Cell* _left = nullptr;
  Cell* _right = nullptr;
  Cell* _get_or_create(bool);
  static void _delete_all(Cell*, bool);
public:
  static int count; // number of cells created
  static Value* defaultValue; // default value for new cells
  Value* value; // current value

  Cell();
  Cell* left();
  Cell* right();
  ~Cell();
};

#endif
