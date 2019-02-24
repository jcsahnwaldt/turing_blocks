
function value0Action(call = true) {
  if (call) this.state.action0.doCell();
  else return [this.state.action0, 'doCell'];
}

function value0String() {
  return "ZERO";
}

function Value0() {
  if (new.target) throw new TypeError();
  const block = {
    toString: value0String,
    state: null,
    doAction: value0Action,
  };
  return Object.seal(block);
}

function value1Action(call = true) {
  if (call) this.state.action1.doCell();
  else return [this.state.action1, 'doCell'];
}

function value1String() {
  return "ONE";
}

function Value1() {
  if (new.target) throw new TypeError();
  const block = {
    toString: value1String,
    state: null,
    doAction: value1Action,
  };
  return Object.seal(block);
}

module.exports = {Value0, Value1};
