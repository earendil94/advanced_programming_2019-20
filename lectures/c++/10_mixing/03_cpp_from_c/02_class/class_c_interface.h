#ifndef _CLASS_C_INTERFACE_H_
#define _CLASS_C_INTERFACE_H_

//We don't have classes, so we define a pointer to void instead
typedef void* Foo_c;

//This ifdef instruction to the pre-processor is crucial.
//Since this header is both included by our cpp and our c code, we need to specify these symbols
//In order to let the compiler know when to call extern on this interface and when not.
//Of course the macro activates only in the case you are calling c++.
#ifdef __cplusplus
extern "C" {
#endif

Foo_c create_foo(int b);
void free_foo(Foo_c);
void print_foo(Foo_c);
void set_a(Foo_c, int v);
int get_a(Foo_c);

#ifdef __cplusplus
}
#endif

#endif /* _CLASS_C_INTERFACE_H_ */
