#include "class_c_interface.h"
#include "class.hpp"

//This is marvellous: we actually write C functions that call C++ functions
//It has a C-header and a C++ implementation -> must compile with a C++ compiler.
extern "C" {
//Before we can use Foo * we need to do a static cast, because in C that is a void *
//If your class is templated, I am afraid you need to un-template your class in C.
Foo_c create_foo(int b) {
  return new Foo(b);
}
void free_foo(Foo_c f) {
  delete static_cast<Foo*>(f);
}
void print_foo(Foo_c f) {
  static_cast<Foo*>(f)->print();
}
void set_a(Foo_c f, int v) {
  static_cast<Foo*>(f)->get_a() = v;
};
int get_a(Foo_c f) {
  return static_cast<Foo*>(f)->get_a();
}
}
