"use strict";

const {Goto, Halt} = require("./Action");
const State = require("./State");
const Cell = require("./Cell");
const {Value0, Value1} = require("./Value");
const {StepLeft, StepRight} = require("./Step");

// see http://www.logique.jussieu.fr/~michel/ha.html#tm22
function busy_beaver_2() {
  const ZERO = new Value0();
  const ONE = new Value1();

  const LEFT = new StepLeft();
  const RIGHT = new StepRight();

  // A0  A1  B0  B1
  // 1RB 1LB 1LA 1RH
  // Σ=4, s=6

  const a = new State("A");
  const b = new State("B");

  const counter = {count: 0};
  const a0 = new Goto("A0", a, b, ONE, RIGHT, counter);
  const a1 = new Goto("A1", a, b, ONE, LEFT, counter);
  const b0 = new Goto("B0", b, a, ONE, LEFT, counter);
  const b1 = new Halt("B1", b, ONE, RIGHT, counter);

  a.init(a0, a1);
  b.init(b0, b1);

  Cell.count = 0;
  Cell.defaultValue = ZERO;
  a.cell = new Cell();

  a.go();

  console.log(Cell.count + " cells");
  console.log();
}

// http://www.logique.jussieu.fr/~michel/ha.html#tm42
function busy_beaver_4() {
  const ZERO = new Value0();
  const ONE = new Value1();

  const LEFT = new StepLeft();
  const RIGHT = new StepRight();

  // A0  A1  B0  B1  C0  C1  D0  D1
  // 1RB 1LB 1LA 0LC 1RH 1LD 1RD 0RA
  // Σ=13, s=107

  const a = new State("A");
  const b = new State("B");
  const c = new State("C");
  const d = new State("D");

  const counter = {count: 0};
  const a0 = new Goto("A0", a, b, ONE, RIGHT, counter);
  const a1 = new Goto("A1", a, b, ONE, LEFT, counter);
  const b0 = new Goto("B0", b, a, ONE, LEFT, counter);
  const b1 = new Goto("B1", b, c, ZERO, LEFT, counter);
  const c0 = new Halt("C0", c, ONE, RIGHT, counter);
  const c1 = new Goto("C1", c, d, ONE, LEFT, counter);
  const d0 = new Goto("D0", d, d, ONE, RIGHT, counter);
  const d1 = new Goto("D1", d, a, ZERO, RIGHT, counter);

  a.init(a0, a1);
  b.init(b0, b1);
  c.init(c0, c1);
  d.init(d0, d1);

  Cell.count = 0;
  Cell.defaultValue = ZERO;
  a.cell = new Cell();

  a.go();

  console.log(Cell.count + " cells");
  console.log();
}

function inf() {
  const ZERO = new Value0();
  const ONE = new Value1();

  const LEFT = new StepLeft();
  const RIGHT = new StepRight();

  const a = new State("A");

  const counter = {count: 0};
  const max = 100000;
  const a0 = new Goto("A0", a, a, ONE, RIGHT, counter, max);
  const a1 = new Halt("A1", a, ONE, LEFT, counter); // never reached

  a.init(a0, a1);

  Cell.defaultValue = ZERO;

  counter.count = 0;
  Cell.count = 0;
  a.cell = new Cell();
  let call = [a, 'go'];
  while (call) {
    const target = call[0];
    const method = call[1];
    call = target[method](false);
  }
  console.log(Cell.count + " cells");
  console.log();

  counter.count = 0;
  Cell.count = 0;
  a.cell = new Cell();
  try {
    a.go();
  }
  catch (e) {
    console.log(e);
  }
  console.log(Cell.count + " cells");
  console.log();
}

inf();
busy_beaver_2();
busy_beaver_4();
