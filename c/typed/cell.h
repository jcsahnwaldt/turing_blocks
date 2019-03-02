#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>

struct value;
class cells;

class cell final {
private:
  const long id;
  cells& cells;
  cell* _left = nullptr;
  cell* _right = nullptr;
  friend std::ostream& operator<<(std::ostream&, const cell*);
public:
  cell(long id, cells& cells); // should be private, is public for deque.emplace_*()

  value* value; // current value
  cell* left();
  cell* right();
};

std::ostream& operator<<(std::ostream&, const cell*);

#endif
