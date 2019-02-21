
#include "Action.hpp"

Action::Action(const char* n, Value* v, Step* s) : name(n), value(v), step(s) {
}

int Action::count;
int Action::maxCount;
