#include <iostream>

#include "Cell.hpp"

int Cell::count;
Val* Cell::def;

Cell::Cell(): id(++count), val(def) {
  std::cout << "creating cell " << id << std::endl;
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

void Cell::_delete(Cell* p, bool left) {
  while (p) {
    Cell* n = left ? p->_left : p->_right;
    p->_left = p->_right = nullptr;
    delete p;
    p = n;
  }
}

Cell::~Cell() {
  std::cout << "deleting cell " << id << std::endl;
  _delete(_left, true);
  _delete(_right, false);
}