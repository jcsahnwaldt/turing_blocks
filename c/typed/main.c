
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

  long actions = 0;
  action_t a0, a1, b0, b1;
  init_goto(&a0, "A0", &a, &b, &ONE, &RIGHT, &actions, -1);
  init_goto(&a1, "A1", &a, &b, &ONE, &LEFT, &actions, -1);
  init_goto(&b0, "B0", &b, &a, &ONE, &LEFT, &actions, -1);
  init_halt(&b1, "B1", &b, &ONE, &RIGHT, &actions);

  init_state(&a, "A", &a0, &a1);
  init_state(&b, "B", &b0, &b1);

  long cells = 0;
  cell_t cell;
  init_cell(&cell, 0, &ZERO, &cells);
  a.cell = &cell;

  CALL(&a, go);

  destroy_cell(&cell);

  printf("%ld cells\n", cells);
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

  long actions = 0;
  action_t a0, a1, b0, b1, c0, c1, d0, d1;
  init_goto(&a0, "A0", &a, &b, &ONE, &RIGHT, &actions, -1);
  init_goto(&a1, "A1", &a, &b, &ONE, &LEFT, &actions, -1);
  init_goto(&b0, "B0", &b, &a, &ONE, &LEFT, &actions, -1);
  init_goto(&b1, "B1", &b, &c, &ZERO, &LEFT, &actions, -1);
  init_halt(&c0, "C0", &c, &ONE, &RIGHT, &actions);
  init_goto(&c1, "C1", &c, &d, &ONE, &LEFT, &actions, -1);
  init_goto(&d0, "D0", &d, &d, &ONE, &RIGHT, &actions, -1);
  init_goto(&d1, "D1", &d, &a, &ZERO, &RIGHT, &actions, -1);

  init_state(&a, "A", &a0, &a1);
  init_state(&b, "B", &b0, &b1);
  init_state(&c, "C", &c0, &c1);
  init_state(&d, "D", &d0, &d1);

  long cells = 0;
  cell_t cell;
  init_cell(&cell, 0, &ZERO, &cells);
  a.cell = &cell;

  CALL(&a, go);

  destroy_cell(&cell);

  printf("%ld cells\n", cells);
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

  long actions = 0;
  const long max = 1000000;
  action_t a0, a1;
  init_goto(&a0, "A0", &a, &a, &ONE, &RIGHT, &actions, max);
  init_halt(&a1, "A1", &a, &ONE, &LEFT, &actions); // never reached

  init_state(&a, "A", &a0, &a1);

  long cells = 0;
  cell_t cell;
  init_cell(&cell, 0, &ZERO, &cells);
  a.cell = &cell;

  CALL(&a, go);

  destroy_cell(&cell);

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
