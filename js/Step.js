
class StepLeft {

  constructor() {
    this.action = null;
    Object.seal(this);
  }

  doMove() {
    this.action.next.cell = this.action.current.cell.left();
    this.action.doNext();
  }

  toString() {
    return "LEFT";
  }
}

class StepRight {

  constructor() {
    this.action = null;
    Object.seal(this);
  }

  doMove() {
    this.action.next.cell = this.action.current.cell.right();
    this.action.doNext();
  }

  toString() {
    return "RIGHT";
  }
}

class StepNone {

  constructor() {
    this.action = null;
    Object.seal(this);
  }

  doMove() {
    this.action.next.cell = this.action.current.cell;
    this.action.doNext();
  }

  toString() {
    return "NONE";
  }
}

module.exports = {StepLeft, StepRight, StepNone};