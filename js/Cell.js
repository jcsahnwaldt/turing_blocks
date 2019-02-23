
class Cell {

  constructor(id = 0) {
    this.id = id; // final
    this.value = Cell.defaultValue;
    this._left = null;
    this._right = null;
    Cell.count++;
    Object.seal(this);
  }

  left() {
    if (! this._left) {
      this._left = new Cell(this.id - 1);
      this._left._right = this;
    }
    return this._left;
  }
  
  right() {
    if (! this._right) {
      this._right = new Cell(this.id + 1);
      this._right._left = this;
    }
    return this._right;
  }

  toString() {
    return "cell " + this.id;
  }
}

Cell.defaultValue = null;
Cell.count = 0;

module.exports = Cell;
