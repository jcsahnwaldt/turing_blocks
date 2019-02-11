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

void Cell::_delete(bool left) {
  Cell* next = left ? _left : _right;
  _left = _right = nullptr;
  delete this;
  if (next) next->_delete(left);
}

Cell::~Cell() {
  std::cout << "Cell destructor: " << id << std::endl;
  if (_left) _left->_delete(true);
  if (_right) _right->_delete(false);
}
