
#include "Halt.hpp"

#include <iostream>

Halt::~Halt() {
  std::cout << "deleting Halt" << std::endl; 
}

void Halt::go() {
  std::cout << "action " << ++count << ": HALT" << std::endl;
}
