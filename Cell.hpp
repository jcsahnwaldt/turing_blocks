#ifndef CELL_HPP
#define CELL_HPP

// TODO: find a better way to detect which class needs to be our friend?
#ifdef __clang__
  // works for clang 7.0.1 and Apple clang version 9.1.0
  #define DEQUE_ALLOCATOR std::allocator
#else
  // works for GCC 8.2.0
  #define DEQUE_ALLOCATOR __gnu_cxx::new_allocator
#endif

#include <memory>
#include <iostream>

struct Value;
class Cells;

class Cell final {
private:
  const long id;
  Cells& cells;
  Cell* _left = nullptr;
  Cell* _right = nullptr;
  Cell(long id, Cells& cells);
  friend class DEQUE_ALLOCATOR<Cell>; // for deque.emplace_*()
  friend std::ostream& operator<<(std::ostream&, const Cell*);
public:
  Value* value; // current value
  Cell* left();
  Cell* right();
};

std::ostream& operator<<(std::ostream&, const Cell*);

#endif
