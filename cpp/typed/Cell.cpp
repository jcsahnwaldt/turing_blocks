
#include "Cell.hpp"
#include "Cells.hpp"

Cell::Cell(long i, Cells& c) :
  id(i), cells(c), value(&c.value) {}

Cell* Cell::left() {
  if (!_left) {
    _left = &cells.cells.emplace_front(id - 1, cells);
    _left->_right = this;
  }
  return _left;
}

Cell* Cell::right() {
  if (!_right) {
    _right = &cells.cells.emplace_back(id + 1, cells);
    _right->_left = this;
  }
  return _right;
}

std::ostream& operator<<(std::ostream& os, const Cell* cell) {
  os << "cell " << cell->id;
  return os;
}
