
class State {
  constructor(name) {
    this.name = name; // final
    this.action0 = null; // final after call to init()
    this.action1 = null; // final after call to init()
    this.cell = null; // not final
    Object.seal(this);
  }

  init(action0, action1) {
    this.action0 = action0; // final
    this.action1 = action1; // final
    // TODO: make final
  }

  go() {
    this.cell.value.state = this;
    this.cell.value.doAction();
  }

  toString() {
    return this.name;
  }
}

module.exports = State;
