
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
  init_value_0(&ZERO);
  value_t ONE;
  init_value_1(&ONE);

  step_t LEFT;
  init_step_left(&LEFT);
  step_t RIGHT;
  init_step_right(&RIGHT);

  // A0  A1  B0  B1
  // 1RB 1LB 1LA 1RH
  // Σ=4, s=6

  state_t a, b;

  action_count = 0;
  action_count_max = 0;
  action_t a0, a1, b0, b1;
  init_goto(&a0, "A0", &a, &b, &ONE, &RIGHT);
  init_goto(&a1, "A1", &a, &b, &ONE, &LEFT);
  init_goto(&b0, "B0", &b, &a, &ONE, &LEFT);
  init_halt(&b1, "B1", &b, &ONE, &RIGHT);

  init_state(&a, "A", &a0, &a1);
  init_state(&b, "B", &b0, &b1);

  cell_count = 0;
  cell_default_value = &ZERO;
  cell_t cell;
  init_cell(&cell, 0);
  a.cell = &cell;

  CALL(&a, go);

  destroy_cell(&cell);

  printf("%lu cells\n", cell_count);
}

// http://www.logique.jussieu.fr/~michel/ha.html#tm42
void busy_beaver_4() {
  value_t ZERO;
  init_value_0(&ZERO);
  value_t ONE;
  init_value_1(&ONE);

  step_t LEFT;
  init_step_left(&LEFT);
  step_t RIGHT;
  init_step_right(&RIGHT);

  // A0  A1  B0  B1  C0  C1  D0  D1
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA
  // Σ=13, s=107

  state_t a, b, c, d;

  action_count = 0;
  action_count_max = 0;
  action_t a0, a1, b0, b1, c0, c1, d0, d1;
  init_goto(&a0, "A0", &a, &b, &ONE, &RIGHT);
  init_goto(&a1, "A1", &a, &b, &ONE, &LEFT);
  init_goto(&b0, "B0", &b, &a, &ONE, &LEFT);
  init_goto(&b1, "B1", &b, &c, &ZERO, &LEFT);
  init_halt(&c0, "C0", &c, &ONE, &RIGHT);
  init_goto(&c1, "C1", &c, &d, &ONE, &LEFT);
  init_goto(&d0, "D0", &d, &d, &ONE, &RIGHT);
  init_goto(&d1, "D1", &d, &a, &ZERO, &RIGHT);

  init_state(&a, "A", &a0, &a1);
  init_state(&b, "B", &b0, &b1);
  init_state(&c, "C", &c0, &c1);
  init_state(&d, "D", &d0, &d1);

  cell_count = 0;
  cell_default_value = &ZERO;
  cell_t cell;
  init_cell(&cell, 0);
  a.cell = &cell;

  CALL(&a, go);

  destroy_cell(&cell);

  printf("%lu cells\n", cell_count);
}

void inf() {
  value_t ZERO;
  init_value_0(&ZERO);
  value_t ONE;
  init_value_1(&ONE);

  step_t LEFT;
  init_step_left(&LEFT);
  step_t RIGHT;
  init_step_right(&RIGHT);

  state_t a;

  action_count = 0;
  action_count_max = 1000000;
  action_t a0, a1;
  init_goto(&a0, "A0", &a, &a, &ONE, &RIGHT);
  init_halt(&a1, "A1", &a, &ONE, &LEFT); // never reached

  init_state(&a, "A", &a0, &a1);

  cell_count = 0;
  cell_default_value = &ZERO;
  cell_t cell;
  init_cell(&cell, 0);
  a.cell = &cell;

  CALL(&a, go);

  destroy_cell(&cell);

  printf("%lu cells\n", cell_count);
}

int main() {
  inf();
  printf("\n");
  busy_beaver_2();
  printf("\n");
  busy_beaver_4();
  return 0;
}
