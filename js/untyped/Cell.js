
function left() {
  if (! this._left) {
    this._left = Cell(this.id - 1);
    this._left._right = this;
  }
  return this._left;
}

function right() {
  if (! this._right) {
    this._right = Cell(this.id + 1);
    this._right._left = this;
  }
  return this._right;
}

function toString() {
  return "cell " + this.id;
}

function Cell(id = 0) {
  if (new.target) throw new TypeError();
  const block = {
    id,
    value: Cell.defaultValue,
    _left: null,
    _right: null,
    left,
    right,
    toString
  };
  Cell.count++;
  return Object.seal(block);
}

Cell.defaultValue = null;
Cell.count = 0;

module.exports = Cell;
