#ifndef __class__
#define __class__

#include <iostream>

//A struct/class declaration can be repeated in many compilation units. Linker does not complain.
struct A {
  int a;
  A() { std::cout << "A ctor\n"; }
};

// A::A() { std::cout << "A ctor\n"; } // why not? The definition of a function can't tho!

#endif
