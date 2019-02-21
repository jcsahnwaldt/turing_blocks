#ifndef CELLS_HPP
#define CELLS_HPP

#include <deque>

#include "Cell.hpp"

struct Value;

class Cells final {
private:
  std::deque<Cell> cells;
  Value& value; // default value for new cells
  friend class Cell;
public:
  Cells(Value& value);
  Cell& init;
  long count();
};

#endif
