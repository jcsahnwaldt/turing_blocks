#ifndef HALT_H
#define HALT_H

#include "action.h"

class halt final : public action {
protected:
  void print() override;
public:
  halt(const char* name, state& state, value& value, step& step, long& count);
  void do_cell() override;
  void do_next() override;
};

#endif
