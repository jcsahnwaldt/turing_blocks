#ifndef CELLS_HPP
#define CELLS_HPP

#include <deque>

#include "Cell.hpp"

struct Value;

struct Cells final {
private:
  std::deque<Cell> cells;
  Value& defaultValue; // default value for new cells
  friend struct Cell;
public:
  Cells(Value& defaultValue);
  Cell& root;
};

#endif
