
#include "Action.hpp"

#include <iostream>

#include "Val.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Action::Action(const char* n, Val* v, Step* sp, State* st) : Transition::Transition(n, v, sp), state(st) {}

void Action::go() {
  std::cout << "Transition " << ++count << ": "  << name << ": set " << val << ", move " << step << ", goto " << state << std::endl;
  cell->val = val;
  step->cell = cell;
  step->go();
  state->cell = step->cell;
  state->go();
}
