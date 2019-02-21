#include <iostream>

#include "State.hpp"
#include "Cells.hpp"
#include "Cell.hpp"
#include "Value.hpp"
#include "Action.hpp"
#include "Goto.hpp"
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
  // Σ=4, s=6

  Goto a0("A0", &ONE, &RIGHT, &b);
  Goto a1("A1", &ONE, &LEFT, &b);
  Goto b0("B0", &ONE, &LEFT, &a);
  Halt b1("B1", &ONE, &RIGHT);

  a.action0 = &a0;
  a.action1 = &a1;
  b.action0 = &b0;
  b.action1 = &b1;

  Action::count = 0;
  Action::maxCount = 0;

  Cells cells(ZERO);
  a.cell = &cells.root;

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

  Goto a0("A0", &ONE, &RIGHT, &b);
  Goto a1("A1", &ONE, &LEFT, &b);
  Goto b0("B0", &ONE, &LEFT, &a);
  Goto b1("B1", &ZERO, &LEFT, &c);
  Halt c0("C0", &ONE, &RIGHT);
  Goto c1("C1", &ONE, &LEFT, &d);
  Goto d0("D0", &ONE, &RIGHT, &d);
  Goto d1("D1", &ZERO, &RIGHT, &a);

  a.action0 = &a0;
  a.action1 = &a1;
  b.action0 = &b0;
  b.action1 = &b1;
  c.action0 = &c0;
  c.action1 = &c1;
  d.action0 = &d0;
  d.action1 = &d1;

  Action::count = 0;
  Action::maxCount = 0;

  Cells cells(ZERO);
  a.cell = &cells.root;

  a.go();
}

void inf() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");

  Goto a0("A0", &ONE, &LEFT, &a);
  Goto a1("A1", &ONE, &LEFT, &a);

  a.action0 = &a0;
  a.action1 = &a1;

  Action::count = 0;
  Action::maxCount = 1000000;

  Cells cells(ZERO);
  a.cell = &cells.root;

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
