#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>

struct Value;
class Cells;

class Cell final {
private:
  const long id;
  Cells& cells;
  Cell* _left = nullptr;
  Cell* _right = nullptr;
  friend std::ostream& operator<<(std::ostream&, const Cell*);
public:
  Cell(long id, Cells& cells); // should be private, is public for deque.emplace_*()

  Value* value; // current value
  Cell* left();
  Cell* right();
};

std::ostream& operator<<(std::ostream&, const Cell*);

#endif
