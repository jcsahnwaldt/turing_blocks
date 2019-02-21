#ifndef STATES_HPP
#define STATES_HPP

#include <array>

class State;

class States final {
private:
  State** const states;
public:
  States(int size);
  States(States&) = delete;
  ~States();
  State* const & operator[](int i) const;
  State*& operator[](int i);
};

#endif
