
class Action {

  constructor(name, current, next, value, step, counter) {
    if (new.target === Action) throw new TypeError('class Action is abstract');
    this.name = name; // final
    this.current = current; // final
    this.next = next; // final
    this.value = value; // final
    this.step = step; // final
    this.counter = counter; // final
  }

  doCell(call = true) {
    this.counter.count++;
    console.log(this.toString());
    this.current.cell.value = this.value;
    this.step.action = this;
    if (call) this.step.doMove();
    else return [this.step, 'doMove'];
  }

  toString() {
    return "Action " + this.counter.count + ": "
    + this.name + ": "
    + "set " + this.current.cell + " from " + this.current.cell.value + " to " + this.value + ", "
    + "move " + this.step + ", ";
  }
}

class Goto extends Action {

  constructor(name, current, next, value, step, counter, max = -1) {
    super(name, current, next, value, step, counter);
    this.max = max;
    Object.freeze(this);
  }

  toString() {
    return super.toString() + "goto " + this.next;
  }

  doNext(call = true) {
    if (this.max >= 0 && this.counter.count >= this.max) return;
    if (call) this.next.go();
    else return [this.next, 'go'];
  }
}

class Halt extends Action {

  constructor(name, state, value, step, counter) {
    super(name, state, state, value, step, counter);
    Object.freeze(this);
  }

  toString() {
    return super.toString() + "halt";
  }

  doNext() {
    // halt
  }
}

module.exports = {Goto, Halt};
