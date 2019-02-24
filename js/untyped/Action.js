
function doCell(call = true) {
  this.counter.count++;
  console.log(this.toString());
  this.current.cell.value = this.value;
  this.step.action = this;
  if (call) this.step.doMove();
  else return [this.step, 'doMove'];
};

function actionString() {
  return "Action " + this.counter.count + ": "
  + this.name + ": "
  + "set " + this.current.cell + " from " + this.current.cell.value + " to " + this.value + ", "
  + "move " + this.step + ", ";
};

function gotoNext(call = true) {
  if (this.max >= 0 && this.counter.count >= this.max) return;
  if (call) this.next.go();
  else return [this.next, 'go'];
};

function gotoString() {
  return actionString.call(this) + "goto " + this.next;
}

function Goto(name, current, next, value, step, counter, max = -1) {
  if (new.target) throw new TypeError();
  const block = {
    name, counter, max,
    toString: gotoString,
    current,
    next,
    value,
    step,
    doCell,
    doNext: gotoNext
  };
  return Object.freeze(block);
}

function haltString() {
  return actionString.call(this) + "halt";
}

function halt() {
  // halt
}

function Halt(name, state, value, step, counter) {
  if (new.target) throw new TypeError();
  const block = {
    name, counter,
    toString: haltString,
    current: state,
    next: state,
    value,
    step,
    doCell,
    doNext: halt
  };
  return Object.freeze(block);
}

module.exports = {Goto, Halt};
