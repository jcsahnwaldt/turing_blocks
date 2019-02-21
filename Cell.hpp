#ifndef CELL_HPP
#define CELL_HPP

#include <memory>

struct Value;
struct Cells;

struct Cell final {
private:
  const long id;
  Cells& cells;
  Cell* _left = nullptr;
  Cell* _right = nullptr;
  Cell(long id, Cells& cells);
  friend class std::allocator<Cell>; // for deque.emplace_*()
public:
  Value* value; // current value
  Cell* left();
  Cell* right();
};

#endif
