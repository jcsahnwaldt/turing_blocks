
class Value0 {

  constructor() {
    this.state = null;
    Object.seal(this);
  }

  doAction() {
    this.state.action0.doCell();
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

  doAction() {
    this.state.action1.doCell();
  }

  toString() {
    return "ONE";
  }
}

module.exports = {Value0, Value1};
