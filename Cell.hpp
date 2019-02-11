#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <memory>

struct Value;

struct Cell final {
private:
  const int _id;
  bool _root = false;
  bool _left;
  std::unique_ptr<Cell> _next;
  Cell* _prev = nullptr;
  Cell* _get_or_create(bool);
  Cell(bool);
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
