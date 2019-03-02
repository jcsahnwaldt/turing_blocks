#ifndef VALUE_H
#define VALUE_H

typedef struct state_t state_t;

typedef struct value_t value_t;
struct value_t {
  const char* name;
  state_t* state;
  void (*do_action)(value_t*);
};

void init_value_0(value_t*);
void init_value_1(value_t*);

#endif
