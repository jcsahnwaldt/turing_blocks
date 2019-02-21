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

  long counter = 0;
  Goto a0("A0", &a, &b, &ONE, &RIGHT, counter);
  Goto a1("A1", &a, &b, &ONE, &LEFT, counter);
  Goto b0("B0", &b, &a, &ONE, &LEFT, counter);
  Halt b1("B1", &b, &b, &ONE, &RIGHT, counter);

  a.action0 = &a0;
  a.action1 = &a1;
  b.action0 = &b0;
  b.action1 = &b1;

  Cells cells(ZERO);
  a.cell = &cells.init;

  a.go();

  std::cout << cells.count() << " cells" << std::endl;
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

  long counter = 0;
  Goto a0("A0", &a, &b, &ONE, &RIGHT, counter);
  Goto a1("A1", &a, &b, &ONE, &LEFT, counter);
  Goto b0("B0", &b, &a, &ONE, &LEFT, counter);
  Goto b1("B1", &b, &c, &ZERO, &LEFT, counter);
  Halt c0("C0", &c, &c, &ONE, &RIGHT, counter);
  Goto c1("C1", &c, &d, &ONE, &LEFT, counter);
  Goto d0("D0", &d, &d, &ONE, &RIGHT, counter);
  Goto d1("D1", &d, &a, &ZERO, &RIGHT, counter);

  a.action0 = &a0;
  a.action1 = &a1;
  b.action0 = &b0;
  b.action1 = &b1;
  c.action0 = &c0;
  c.action1 = &c1;
  d.action0 = &d0;
  d.action1 = &d1;

  Cells cells(ZERO);
  a.cell = &cells.init;

  a.go();

  std::cout << cells.count() << " cells" << std::endl;
}

void inf() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State a("A");

  long counter = 0;
  const long max = 1000000;
  Goto a0("A0", &a, &a, &ONE, &RIGHT, counter, max);
  Halt a1("A1", &a, &a, &ONE, &LEFT, counter); // never reached

  a.action0 = &a0;
  a.action1 = &a1;

  Cells cells(ZERO);
  a.cell = &cells.init;

  a.go();

  std::cout << cells.count() << " cells" << std::endl;
}

int main() {
  inf();
  std::cout << std::endl;
  busy_beaver_2();
  std::cout << std::endl;
  busy_beaver_4();
  return 0;
}
