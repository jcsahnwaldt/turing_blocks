
class StepLeft {

  constructor() {
    this.action = null;
    Object.seal(this);
  }

  doMove(call = true) {
    this.action.next.cell = this.action.current.cell.left();
    if (call) this.action.doNext();
    else return [this.action, 'doNext'];
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

  doMove(call = true) {
    this.action.next.cell = this.action.current.cell.right();
    if (call) this.action.doNext();
    else return [this.action, 'doNext'];
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

  doMove(call = true) {
    this.action.next.cell = this.action.current.cell;
    if (call) this.action.doNext();
    else return [this.action, 'doNext'];
  }

  toString() {
    return "NONE";
  }
}

module.exports = {StepLeft, StepRight, StepNone};