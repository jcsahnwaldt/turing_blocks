#include <iostream>

#include "Cell.hpp"

int Cell::count;
Value* Cell::defaultValue;

Cell::Cell(): Cell(false) {
  _root = true;
  _prev = new Cell(true); // create first left cell
  _prev->_prev = this; // _prev changes its meaning between root cell and first left cell
}

Cell::Cell(bool l): _id(++count), _left(l), value(defaultValue) {
  std::cout << "Cell constructor: " << _id << std::endl;
}

Cell* Cell::left() {
  return _get_or_create(true);
}

Cell* Cell::right() {
  return _get_or_create(false);
}

Cell* Cell::_get_or_create(bool left) {
  if (left != _left) return _prev;
  if (!_next) {
    _next.reset(new Cell(left));
    _next->_prev = this;
  }
  return _next.get();
}

Cell::~Cell() {
  std::cout << "Cell destructor: " << _id << std::endl;
  if (_root) delete _prev;
  while (_next) _next = std::move(_next->_next);
}
