#include <iostream>
#include <vector>

#include "State.h"
#include "cells.h"
#include "cell.h"
#include "Value.h"
#include "action.h"
#include "goto.h"
#include "halt.h"
#include "Step.h"

// see http://www.logique.jussieu.fr/~michel/ha.html#tm22
void busy_beaver_2() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  std::vector<State> s;
  s.reserve(2);

  // A0  A1  B0  B1
  // 1RB 1LB 1LA 1RH
  // Σ=4, s=6

  long counter = 0;
  goto a0("A0", s[0], s[1], ONE, RIGHT, counter);
  goto a1("A1", s[0], s[1], ONE, LEFT, counter);
  goto b0("B0", s[1], s[0], ONE, LEFT, counter);
  halt b1("B1", s[1], ONE, RIGHT, counter);

  s.emplace_back("A", a0, a1);
  s.emplace_back("B", b0, b1);

  cells cells(ZERO);
  s[0].cell = &cells.init;

  s[0].go();

  std::cout << cells.count() << " cells" << std::endl;
}

// http://www.logique.jussieu.fr/~michel/ha.html#tm42
void busy_beaver_4() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  std::vector<State> s;
  s.reserve(4);

  // A0  A1  B0  B1  C0  C1  D0  D1
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA
  // Σ=13, s=107

  long counter = 0;
  goto a0("A0", s[0], s[1], ONE, RIGHT, counter);
  goto a1("A1", s[0], s[1], ONE, LEFT, counter);
  goto b0("B0", s[1], s[0], ONE, LEFT, counter);
  goto b1("B1", s[1], s[2], ZERO, LEFT, counter);
  halt c0("C0", s[2], ONE, RIGHT, counter);
  goto c1("C1", s[2], s[3], ONE, LEFT, counter);
  goto d0("D0", s[3], s[3], ONE, RIGHT, counter);
  goto d1("D1", s[3], s[0], ZERO, RIGHT, counter);

  s.emplace_back("A", a0, a1);
  s.emplace_back("B", b0, b1);
  s.emplace_back("C", c0, c1);
  s.emplace_back("D", d0, d1);

  cells cells(ZERO);
  s[0].cell = &cells.init;

  s[0].go();

  std::cout << cells.count() << " cells" << std::endl;
}

void inf() {
  Value0 ZERO;
  Value1 ONE;

  StepLeft LEFT;
  StepRight RIGHT;

  std::vector<State> s;
  s.reserve(1);

  long counter = 0;
  const long max = 1000000;
  goto a0("A0", s[0], s[0], ONE, RIGHT, counter, max);
  halt a1("A1", s[0], ONE, LEFT, counter); // never reached

  s.emplace_back("A", a0, a1);

  cells cells(ZERO);
  s[0].cell = &cells.init;

  s[0].go();

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
