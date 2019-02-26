
#include <stddef.h>
#include <iostream>

class slot final {
public:
  void** t;
  friend std::ostream& operator<<(std::ostream&, slot&);
public:
  typedef void (method)(slot);

  void alloc(size_t size) {
    t = new void*[size];
  }

  void free() {
    delete[] t;
  }

  slot& operator[](size_t index) {
    return (slot&)t[index];
  }

  void operator=(const slot& that) {
    t = that.t;
  }

  void operator=(method *f) {
    t = (void**)f;
  }

  void operator()(size_t index) {
    method* f = (method*)t[index];
    f(*this);
  }

};

std::ostream& operator<<(std::ostream& os, slot& s) {
  os << &s << "->" << s.t;
  return os;
}

void foo(slot s) {
  std::cout << "foo(" << s << ")" << std::endl;
}

int main(void) {
  slot b;
  b.alloc(2);
  slot c;
  c.alloc(2);
  b[0] = c;
  b[0][1] = b[0];
  b[1] = foo;
  b(1);
  std::cout << "&b " << &b << std::endl;
  std::cout << "b " << b << std::endl;
  std::cout << "c " << c << std::endl;
  std::cout << "b[0] " << b[0] << std::endl;
  std::cout << "b[1] " << b[1] << std::endl;
  std::cout << "foo " << (void*)foo << std::endl;
  std::cout << "b.t[0] " << b.t[0] << std::endl;
  std::cout << "c.t[1] " << c.t[1] << std::endl;
  c.free();
  b.free();
  return 0;
}
