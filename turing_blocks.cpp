#include <iostream>

#include "State.hpp"
#include "Cell.hpp"
#include "Val.hpp"
#include "Trans.hpp"
#include "Action.hpp"
#include "Halt.hpp"
#include "Step.hpp"

void bb2() {
  Val0 ZERO;
  Val1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");
  State b("B");

  Action a0(&ONE, &RIGHT, &b);
  Action a1(&ONE, &LEFT, &b);
  Action b0(&ONE, &LEFT, &a);
  Halt b1;

  a.trans0 = &a0;
  a.trans1 = &a1;
  b.trans0 = &b0;
  b.trans1 = &b1;

  Cell::count = 0;
  Trans::count = 0;
  Cell::def = &ZERO;

  Cell s;
  a.cell = &s;

  a.go();
}

void bb4() {
  Val0 ZERO;
  Val1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");
  State b("B");
  State c("C");
  State d("D");

  // A0  A1  B0  B1  C0  C1  D0  D1  sigma s
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA 13    107

  Action a0(&ONE, &RIGHT, &b);
  Action a1(&ONE, &LEFT, &b);
  Action b0(&ONE, &LEFT, &a);
  Action b1(&ZERO, &LEFT, &c);
  Halt c0;
  Action c1(&ONE, &LEFT, &d);
  Action d0(&ONE, &RIGHT, &d);
  Action d1(&ZERO, &RIGHT, &a);

  a.trans0 = &a0;
  a.trans1 = &a1;
  b.trans0 = &b0;
  b.trans1 = &b1;
  c.trans0 = &c0;
  c.trans1 = &c1;
  d.trans0 = &d0;
  d.trans1 = &d1;

  Cell::count = 0;
  Trans::count = 0;
  Cell::def = &ZERO;

  Cell s;
  a.cell = &s;

  a.go();
}

int main() {
  bb2();
  std::cout << std::endl;
  bb4();
  return 0;
}