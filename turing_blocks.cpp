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

  State* ss[] = {
    new State("A"),
    new State("B")
  };

  // A0  A1  B0  B1
  // 1RB 1LB 1LA 1RH
  // Σ=4, s=6

  long counter = 0;
  Goto a0("A0", ss, 0, 1, &ONE, &RIGHT, counter);
  Goto a1("A1", ss, 0, 1, &ONE, &LEFT, counter);
  Goto b0("B0", ss, 1, 0, &ONE, &LEFT, counter);
  Halt b1("B1", ss, 1, &ONE, &RIGHT, counter);

  ss[0]->action0 = &a0;
  ss[0]->action1 = &a1;
  ss[1]->action0 = &b0;
  ss[1]->action1 = &b1;

  Cells cells(ZERO);
  ss[0]->cell = &cells.init;

  ss[0]->go();

  std::cout << cells.count() << " cells" << std::endl;

  for (State* s: ss) delete s;
}

// http://www.logique.jussieu.fr/~michel/ha.html#tm42
void busy_beaver_4() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State* ss[] = {
    new State("A"),
    new State("B"),
    new State("C"),
    new State("D")
  };

  // A0  A1  B0  B1  C0  C1  D0  D1
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA
  // Σ=13, s=107

  long counter = 0;
  Goto a0("A0", ss, 0, 1, &ONE, &RIGHT, counter);
  Goto a1("A1", ss, 0, 1, &ONE, &LEFT, counter);
  Goto b0("B0", ss, 1, 0, &ONE, &LEFT, counter);
  Goto b1("B1", ss, 1, 2, &ZERO, &LEFT, counter);
  Halt c0("C0", ss, 2, &ONE, &RIGHT, counter);
  Goto c1("C1", ss, 2, 3, &ONE, &LEFT, counter);
  Goto d0("D0", ss, 3, 3, &ONE, &RIGHT, counter);
  Goto d1("D1", ss, 3, 0, &ZERO, &RIGHT, counter);

  ss[0]->action0 = &a0;
  ss[0]->action1 = &a1;
  ss[1]->action0 = &b0;
  ss[1]->action1 = &b1;
  ss[2]->action0 = &c0;
  ss[2]->action1 = &c1;
  ss[3]->action0 = &d0;
  ss[3]->action1 = &d1;

  Cells cells(ZERO);
  ss[0]->cell = &cells.init;

  ss[0]->go();

  std::cout << cells.count() << " cells" << std::endl;

  for (State* s: ss) delete s;
}

void inf() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  State* ss[] = {
    new State("A")
  };

  long counter = 0;
  const long max = 1000000;
  Goto a0("A0", ss, 0, 0, &ONE, &RIGHT, counter, max);
  Halt a1("A1", ss, 0, &ONE, &LEFT, counter); // never reached

  ss[0]->action0 = &a0;
  ss[0]->action1 = &a1;

  Cells cells(ZERO);
  ss[0]->cell = &cells.init;

  ss[0]->go();

  std::cout << cells.count() << " cells" << std::endl;

  for (State* s: ss) delete s;
}

int main() {
  inf();
  std::cout << std::endl;
  busy_beaver_2();
  std::cout << std::endl;
  busy_beaver_4();
  return 0;
}
