A Turing machine implementation without branches or proper function calls. Only assignments and goto are allowed. It's a "dynamic" kind of goto though: jump to a piece of code found under a certain symbol within a certain object. And since different objects can contain the same symbols, we have polymorphism.

Jumps are emulated by methods without parameter or return values. The compiler transforms calls to such functions to plain jumps by tail-call optimization.
