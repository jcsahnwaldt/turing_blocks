
function go(call = true) {
  this.cell.value.state = this;
  if (call) this.cell.value.doAction();
  else return [this.cell.value, 'doAction'];
}

function toString() {
  return this.name;
}

function State(name) {
  if (new.target) throw new TypeError();
  const block = {
    name,
    toString,
    cell: null,
    go
  };
  return block;
}

State.init = function(block, action0, action1) {
  const actions = {
    action0,
    action1
  };
  Object.assign(block, actions);
  Object.seal(block);
}

module.exports = State;
