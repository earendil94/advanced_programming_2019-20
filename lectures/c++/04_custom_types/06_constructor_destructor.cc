#include <iostream>
#include <string>

struct Foo {
  int _i;
  double _d;
  std::string _s;

  //When you call new you are calling the constructor of a class, with malloc you are not.Same holds true for delete and free.
  //Inlined function are copied and pasted in the memory. Small function should be inlined. Functions defined inside a class are inlined. The only way to know if a function has been actually inlined by the compiler is to look at the assembly code.
  Foo(const int i, const double d,
      const std::string& s);  // custom constructor

  Foo();  // default constructor

  ~Foo();  // destructor
};

Foo::Foo(const int i, const double d, const std::string& s)
    : _i{i},
      _d{d},
      _s{s}
//You can write variables initialization BEFORE the body of the function in a constructor.
//The region above can be defined only with a constructor. Variables there are not constructed yet. Here you can (and should call constructors of variables of the class). 
//Here you cannot use = to assign values. Also, initialize variables in the same order you have defined them.
//This way with all this giberriesh is the fastest way.
      // _i, _d, _s must be initialized in the same order they have been declared

{
  std::cout << "custom ctor\n";
  // if you want/need you can use _i, _d, _s and change their value
  // with the usual notation +,-,=,*, call a function..
  // don't use {} because this notation is reserved for the
  // construction of the variables and at this point they have already
  // been constructed
}

Foo::Foo() {
  std::cout << "default ctor\n";  // what happens to our member variables?
}

Foo::~Foo() {
  std::cout << "dtor\n";
}

std::ostream& operator<<(std::ostream& os, const Foo& f) {
	//use ostream to make an operator overload of <<
	//The operator overload must be defined outside class definition
  os << f._i << " " << f._d << " " << f._s << std::endl;
  return os;
}

int main() {
  Foo f0;    // call default ctor
  Foo f1{};  // call default ctor
  // Foo f2(); // compiler error

  Foo f2{8, 2.2, "hello"};
  //Foo f2(8,2.2., "hello") is equivalent. First one recommended.
  //std::cout << "f0" This calls the function << on a ostream ref and a string. It returns an ostream reference.
  //This returned value gets then called by another << with the proper f0 class. This then calls our function.
  std::cout << "f0: " << f0 << "f1: " << f1 << "f2: " << f2 << std::endl;

  // the destructor is called when the variable goes out of scope
  //
  // Never call a destructor by hand
  // Anyway, the destructor goes from bottom to top
  return 0;
}
