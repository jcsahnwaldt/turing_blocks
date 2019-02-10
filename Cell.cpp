#include <iostream>

#include "Cell.hpp"

int Cell::count;
Val* Cell::def;

Cell::Cell(): id(++count), val(def) {
  std::cout << "creating cell " << id << std::endl;
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

Cell::~Cell() {
  std::cout << "deleting cell " << id << std::endl;

  Cell* p;

  p = _left;
  while (p) {
    Cell* n = p->_left;
    p->_left = p->_right = nullptr;
    delete p;
    p = n;
  }

  p = _right;
  while (p) {
    Cell* n = p->_right;
    p->_left = p->_right = nullptr;
    delete p;
    p = n;
  }
}
