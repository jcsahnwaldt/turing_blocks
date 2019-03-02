
#include "cell.h"
#include "cells.h"

cell::cell(long i, cells& c) :
  id(i), cells(c), value(&c.value) {}

cell* cell::left() {
  if (!_left) {
    _left = &cells.cells.emplace_front(id - 1, cells);
    _left->_right = this;
  }
  return _left;
}

cell* cell::right() {
  if (!_right) {
    _right = &cells.cells.emplace_back(id + 1, cells);
    _right->_left = this;
  }
  return _right;
}

std::ostream& operator<<(std::ostream& os, const cell* cell) {
  os << "cell " << cell->id;
  return os;
}
