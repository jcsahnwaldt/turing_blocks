
function leftMove(call = true) {
  this.action.next.cell = this.action.current.cell.left();
  if (call) this.action.doNext();
  else return [this.action, 'doNext'];
}

function leftString() {
  return "LEFT";
}

function StepLeft() {
  if (new.target) throw new TypeError();
  const block = {
    action: null,
    doMove: leftMove,
    toString: leftString
  };
  return Object.seal(block);
}

function rightMove(call = true) {
  this.action.next.cell = this.action.current.cell.right();
  if (call) this.action.doNext();
  else return [this.action, 'doNext'];
}

function rightString() {
  return "RIGHT";
}

function StepRight() {
  if (new.target) throw new TypeError();
  const block = {
    action: null,
    doMove: rightMove,
    toString: rightString
  };
  return Object.seal(block);
}

function noneMove(call = true) {
  this.action.next.cell = this.action.current.cell;
  if (call) this.action.doNext();
  else return [this.action, 'doNext'];
}

function noneString() {
  return "NONE";
}

function StepNone() {
  if (new.target) throw new TypeError();
  const block = {
    action: null,
    doMove: noneMove,
    toString: noneString
  };
  return Object.seal(block);
}

module.exports = {StepLeft, StepRight, StepNone};