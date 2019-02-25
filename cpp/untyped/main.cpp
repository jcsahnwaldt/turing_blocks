
#include <stddef.h>
#include <iostream>

struct Block final {
  Block* slots[4];

  Block*& slot(size_t index) {
    return slots[index];
  }
};

int main(void) {
  Block* b = new Block();
  Block* c = new Block();
  b->slot(0) = c;
  b->slot(0)->slot(1) = b->slot(0);
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << b->slot(0) << std::endl;
  std::cout << b->slots[0] << std::endl;
  std::cout << c->slots[1] << std::endl;
  delete c;
  delete b;
  return 0;
}