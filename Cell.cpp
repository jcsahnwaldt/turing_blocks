#include <iostream>

#include "Cell.hpp"

int Cell::count;
Value* Cell::defaultValue;

Cell::Cell(): id(++count), value(defaultValue) {
  std::cout << "Cell constructor: " << id << std::endl;
}

Cell* Cell::left() {
  return _get_or_create(true);
}

Cell* Cell::right() {
  return _get_or_create(false);
}

Cell* Cell::_get_or_create(bool left) {
  Cell* p = left ? _left : _right;
  if (!p) {
    p = new Cell();
    (left ? p->_right : p->_left) = this;
    (left ? _left : _right) = p;
  }
  return p;
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
