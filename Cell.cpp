#include <iostream>

#include "Cell.hpp"

int Cell::count;
Value* Cell::defaultValue;

Cell::Cell(): id(++count), value(defaultValue) {
  std::cout << "Cell constructor: " << id << std::endl;
}

Cell* Cell::left() {
  if (!_left) {
    _left = new Cell();
    _left->_right = this;
  }
  return _left;
}

Cell* Cell::right() {
  if (!_right) {
    _right = new Cell();
    _right->_left = this;
  }
  return _right;
}

void Cell::_delete_all(Cell* p, bool left) {
  while (p) {
    Cell* n = left ? p->_left : p->_right;
    p->_left = p->_right = nullptr;
    delete p;
    p = n;
  }
}

Cell::~Cell() {
  std::cout << "Cell destructor: " << id << std::endl;
  _delete_all(_left, true);
  _delete_all(_right, false);
}
