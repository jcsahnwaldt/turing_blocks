
#include "States.hpp"

States::States(int size) :
  states(new State*[size]) {}

States::~States() {
  delete[] states;
}

State* const & States::operator[](int i) const {
  return states[i];
}

State*& States::operator[](int i) {
  return states[i];
}
