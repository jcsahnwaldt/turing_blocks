
#include <stddef.h>
#include <iostream>

class block_ptr final {
public:
  void** p;
  friend std::ostream& operator<<(std::ostream&, block_ptr&);
public:
  block_ptr(size_t size) :
    p(new void*[size]) {}

  ~block_ptr() {
    delete[] p;
  }

  block_ptr& operator[](size_t index) {
    return (block_ptr&)p[index];
  }

  void operator=(const block_ptr& that) {
    p = that.p;
  }

  void operator=(void f(block_ptr&)) {
    p = (void**)f;
  }

  void operator()(size_t index) {
    ((void (*)(block_ptr&))p[index])(*this);
  }

};

std::ostream& operator<<(std::ostream& os, block_ptr& p) {
  os << &p << "->" << p.p;
  return os;
}

void foo(block_ptr& b) {
  std::cout << "foo(" << b << ")" << std::endl;
}

int main(void) {
  block_ptr b(2);
  block_ptr c(2);
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
  std::cout << "b.p[0] " << b.p[0] << std::endl;
  std::cout << "c.p[1] " << c.p[1] << std::endl;
  return 0;
}
