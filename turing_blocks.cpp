#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Value.hpp"
#include "Transition.hpp"
#include "Action.hpp"
#include "Halt.hpp"
#include "Step.hpp"

// see http://www.logique.jussieu.fr/~michel/ha.html#tm22
void busy_beaver_2() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");
  State b("B");

  // A0  A1  B0  B1
  // 1RB 1LB 1LA 1RH
  // Σ= 4, s=6

  Action a0("A0", &ONE, &RIGHT, &b);
  Action a1("A1", &ONE, &LEFT, &b);
  Action b0("B0", &ONE, &LEFT, &a);
  Halt b1("B1", &ONE, &RIGHT);

  a.trans0 = &a0;
  a.trans1 = &a1;
  b.trans0 = &b0;
  b.trans1 = &b1;

  Cell::count = 0;
  Transition::count = 0;
  Cell::defaultValue = &ZERO;

  Cell s;
  a.cell = &s;

  a.go();
}

// http://www.logique.jussieu.fr/~michel/ha.html#tm42
void busy_beaver_4() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");
  State b("B");
  State c("C");
  State d("D");

  // A0  A1  B0  B1  C0  C1  D0  D1
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA
  // Σ=13, s=107

  Action a0("A0", &ONE, &RIGHT, &b);
  Action a1("A1", &ONE, &LEFT, &b);
  Action b0("B0", &ONE, &LEFT, &a);
  Action b1("B1", &ZERO, &LEFT, &c);
  Halt c0("C0", &ONE, &RIGHT);
  Action c1("C1", &ONE, &LEFT, &d);
  Action d0("D0", &ONE, &RIGHT, &d);
  Action d1("D1", &ZERO, &RIGHT, &a);

  a.trans0 = &a0;
  a.trans1 = &a1;
  b.trans0 = &b0;
  b.trans1 = &b1;
  c.trans0 = &c0;
  c.trans1 = &c1;
  d.trans0 = &d0;
  d.trans1 = &d1;

  Cell::count = 0;
  Transition::count = 0;
  Cell::defaultValue = &ZERO;

  Cell s;
  a.cell = &s;

  a.go();
}

void inf() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");

  Action a0("A0", &ONE, &RIGHT, &a);
  Action a1("A1", &ONE, &LEFT, &a);

  a.trans0 = &a0;
  a.trans1 = &a1;

  Cell::count = 0;
  Transition::count = 0;
  Cell::defaultValue = &ZERO;

  Cell s;
  a.cell = &s;

  a.go();
}

int main() {
  inf();
  std::cout << std::endl;
  busy_beaver_2();
  std::cout << std::endl;
  busy_beaver_4();
  return 0;
}
