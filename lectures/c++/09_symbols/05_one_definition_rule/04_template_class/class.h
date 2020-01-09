#ifndef __class__
#define __class__

#include <iostream>

template <class T = double>
struct A {
  T a;
  A();
};

//It is also fine to have multiple definitions of a templated function of a templated class!
template <class T>
A<T>::A() {
  std::cout << "A ctor\n";
}

#endif
