
#include "Action.hpp"

#include <iostream>

#include "Val.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Action::Action(Val* v, Step* sp, State* st) : val(v), step(sp), state(st) {}

Action::~Action() {
  std::cout << "deleting Action" << std::endl; 
}

void Action::go() {
  std::cout << "action " << ++count << ": set " << val << ", move " << step << ", goto " << state << std::endl;
  cell->val = val;
  step->cell = cell;
  step->go();
  state->cell = step->cell;
  state->go();
}
