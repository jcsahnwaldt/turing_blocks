
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

  doCell() {
    this.counter.count++;
    console.log(this.toString());
    this.current.cell.value = this.value;
    this.step.action = this;
    this.step.doMove();
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
    Object.seal(this);
  }

  toString() {
    return super.toString() + "goto " + this.next;
  }

  doNext() {
    if (this.max >= 0 && this.counter.count >= this.max) return;
    this.next.go();
  }
}

class Halt extends Action {

  constructor(name, state, value, step, counter) {
    super(name, state, state, value, step, counter);
    Object.seal(this);
  }

  toString() {
    return super.toString() + "halt";
  }

  doNext() {
    // halt
  }
}

module.exports = {Goto, Halt};
