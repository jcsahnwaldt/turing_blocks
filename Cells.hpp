#ifndef CELLS_HPP
#define CELLS_HPP

#include <deque>

#include "Cell.hpp"

struct Value;

struct Cells final {
private:
  std::deque<Cell> cells;
  Value& value; // default value for new cells
  friend struct Cell;
public:
  Cells(Value& value);
  Cell& init;
  long count();
};

#endif
