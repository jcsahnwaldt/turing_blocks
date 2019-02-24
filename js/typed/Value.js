
class Value0 {

  constructor() {
    this.state = null;
    Object.seal(this);
  }

  doAction(call = true) {
    if (call) this.state.action0.doCell();
    else return [this.state.action0, 'doCell'];
  }

  toString() {
    return "ZERO";
  }
}

class Value1 {

  constructor() {
    this.state = null;
    Object.seal(this);
  }

  doAction(call = true) {
    if (call) this.state.action1.doCell();
    else return [this.state.action1, 'doCell'];
  }

  toString() {
    return "ONE";
  }
}

module.exports = {Value0, Value1};
