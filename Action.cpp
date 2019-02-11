
#include "Action.hpp"

#include <iostream>

#include "Value.hpp"
#include "Step.hpp"
#include "State.hpp"
#include "Cell.hpp"

Action::Action(const char* n, Value* v, Step* sp, State* st) : Transition::Transition(n, v, sp), state(st) {}

void Action::go() {
  std::cout << "Transition " << ++count << ": "  << name << ": set " << value << ", move " << step << ", goto " << state << std::endl;
  cell->value = value;
  step->cell = cell;
  step->go();
  state->cell = step->cell;
  state->go();
}
