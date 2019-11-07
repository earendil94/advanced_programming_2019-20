#include <iostream>
#include <vector>

#include "ap_error.h"

class Foo {
 public:
  Foo() { std::cout << "Foo" << std::endl; }
  ~Foo() { std::cout << "~Foo" << std::endl; }
};

class Bar {
 public:
  Bar() { std::cout << "Bar" << std::endl; }
  ~Bar() { std::cout << "~Bar" << std::endl; }
};

class Vector {
  double* elem;

 public:
  Vector(const unsigned int l) : elem{new double[l]} {
    std::cout << "Vector" << std::endl;
  }
  ~Vector() noexcept {
    delete[] elem;
    std::cout << "~Vector" << std::endl;
  }
};

class ManyResources {
  double* ptr;
  Vector v;

 //Use smart pointers (unique or shared). For raw pointers you need to be aware of all the possible leaks.
 public:
  ManyResources() : ptr{nullptr}, v{3} {
    std::cout << "Manyresources" << std::endl;
    try {
      //What if RAM has finished? new returns an exception! 
      ptr = new double[5];  // new(std::nothrow) double[5] could be better
      AP_ERROR(false) << "Error in ManyResources ctor." << std::endl;
    } catch (...) {
      delete[] ptr;  // <----
      throw; //Repass the ball to the upper level. No need to respecify the exception.
    }
  }

  ~ManyResources() noexcept {
    std::cout << "Manyresources" << std::endl;
    delete[] ptr;  // <----
  }
};

int main() {
  Foo f;
  //The pointer is written here and not in the try block because it needs to be deleted if something bad happens inside the try block.
  int* raw_ptr = new int[7];
  try {
    // int * raw_ptr=new int[7]; // wrong because raw_ptr would not be visible
    // inside the catch-clause
    //Since mr will fail in constructor phase, we will catch this exception. 
    ManyResources mr;
    Bar b;

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;

    delete[] raw_ptr;  // <--- try to comment this and run valgrind or use the
                       // sanitize library
    return 1;

  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n" << std::endl;

    delete[] raw_ptr;  // <---
    return 2;
  }

  delete[] raw_ptr;  // <---
  return 0;
}
