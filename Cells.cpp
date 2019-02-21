#include <iostream>

#include "Cells.hpp"

Cells::Cells(Value& v) :
  value(v), init(cells.emplace_front(0, *this)) {}

long Cells::count() {
  return cells.size();
}
