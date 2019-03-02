#ifndef VALUE_H
#define VALUE_H

struct state_t;

typedef struct value_t {
  state* state_t;
  virtual void do_action() = 0;
} value_t;

struct value0 final : value {
  void do_action() override;
};

struct value1 final : value {
  void do_action() override;
};

#endif
