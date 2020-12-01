#include <iostream>

struct Base {
  Base() { std::cout << "Base\n"; }
  ~Base() { std::cout << "~Base\n"; }
};

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; }

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p; //These destroys only base class, derived class will cause a memory leak

  return 0;
}
