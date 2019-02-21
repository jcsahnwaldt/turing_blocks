
#include "Action.hpp"

Action::Action(const char* n, Value* v, Step* s, long& c, long m) :
  name(n), value(v), step(s), count(c), max(m) {}
