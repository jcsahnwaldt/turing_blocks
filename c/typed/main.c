
#include "state.h"
#include "cell.h"
#include "value.h"
#include "action.h"
#include "step.h"

#include <stdio.h>
#include "method.h"

// see http://www.logique.jussieu.fr/~michel/ha.html#tm22
void busy_beaver_2() {
  value_t ZERO;
  value_init_0(&ZERO);
  value_t ONE;
  value_init_1(&ONE);

  step_t LEFT;
  step_init_left(&LEFT);
  step_t RIGHT;
  step_init_right(&RIGHT);

  // A0  A1  B0  B1
  // 1RB 1LB 1LA 1RH
  // Σ=4, s=6

  state_t a, b;

  long actions = 0;
  action_t a0, a1, b0, b1;
  goto_init(&a0, "A0", &a, &b, &ONE, &RIGHT, &actions, -1);
  goto_init(&a1, "A1", &a, &b, &ONE, &LEFT, &actions, -1);
  goto_init(&b0, "B0", &b, &a, &ONE, &LEFT, &actions, -1);
  halt_init(&b1, "B1", &b, &ONE, &RIGHT, &actions);

  state_init(&a, "A", &a0, &a1);
  state_init(&b, "B", &b0, &b1);

  long cells = 0;
  cell_t cell;
  cell_init(&cell, 0, &ZERO, &cells);
  a.cell = &cell;

  CALL(&a, go);

  printf("%ld cells\n", cells);
}

// http://www.logique.jussieu.fr/~michel/ha.html#tm42
void busy_beaver_4() {
  value_t ZERO;
  value_init_0(&ZERO);
  value_t ONE;
  value_init_1(&ONE);

  step_t LEFT;
  step_init_left(&LEFT);
  step_t RIGHT;
  step_init_right(&RIGHT);

  // A0  A1  B0  B1  C0  C1  D0  D1
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA
  // Σ=13, s=107

  state_t a, b, c, d;

  long actions = 0;
  action_t a0, a1, b0, b1, c0, c1, d0, d1;
  goto_init(&a0, "A0", &a, &b, &ONE, &RIGHT, &actions, -1);
  goto_init(&a1, "A1", &a, &b, &ONE, &LEFT, &actions, -1);
  goto_init(&b0, "B0", &b, &a, &ONE, &LEFT, &actions, -1);
  goto_init(&b1, "B1", &b, &c, &ZERO, &LEFT, &actions, -1);
  halt_init(&c0, "C0", &c, &ONE, &RIGHT, &actions);
  goto_init(&c1, "C1", &c, &d, &ONE, &LEFT, &actions, -1);
  goto_init(&d0, "D0", &d, &d, &ONE, &RIGHT, &actions, -1);
  goto_init(&d1, "D1", &d, &a, &ZERO, &RIGHT, &actions, -1);

  state_init(&a, "A", &a0, &a1);
  state_init(&b, "B", &b0, &b1);
  state_init(&c, "C", &c0, &c1);
  state_init(&d, "D", &d0, &d1);

  long cells = 0;
  cell_t cell;
  cell_init(&cell, 0, &ZERO, &cells);
  a.cell = &cell;

  CALL(&a, go);

  printf("%ld cells\n", cells);
}

void inf() {
  value_t ZERO;
  value_init_0(&ZERO);
  value_t ONE;
  value_init_1(&ONE);

  step_t LEFT;
  step_init_left(&LEFT);
  step_t RIGHT;
  step_init_right(&RIGHT);

  state_t a;

  long actions = 0;
  const long max = 1000000;
  action_t a0, a1;
  goto_init(&a0, "A0", &a, &a, &ONE, &RIGHT, &actions, max);
  halt_init(&a1, "A1", &a, &ONE, &LEFT, &actions); // never reached

  state_init(&a, "A", &a0, &a1);

  long cells = 0;
  cell_t cell;
  cell_init(&cell, 0, &ZERO, &cells);
  a.cell = &cell;

  CALL(&a, go);

  printf("%ld cells\n", cells);
}

int main() {
  inf();
  printf("\n");
  busy_beaver_2();
  printf("\n");
  busy_beaver_4();
  return 0;
}
