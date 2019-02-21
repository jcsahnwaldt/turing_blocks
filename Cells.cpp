#include <iostream>

#include "Cells.hpp"

Cells::Cells(Value& d): defaultValue(d), root(cells.emplace_front(0, *this)) {
}
