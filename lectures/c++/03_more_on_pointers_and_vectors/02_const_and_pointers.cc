#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  //const is a declaration of intent. 
  //1) If something must not change, then you are asking the compiler to double check that this is actually the case
  //2) Compiler will actually perform an optimization of your code

  // In this case you are pointing to an const int. You cannot change what the pointer is pointing to (i.e. the int)
  const int* pc{&a};
  // *pc = 7; 	// error
  a = 15;  // I can obviously change a

  //This time instead we cannot change you want the compiler to warn you if you are trying to change the memory address of the pointer.
  int* const cp{&a};
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc{&a};

  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l};
  for (; a != end; ++a)
    std::cout << *a << std::endl;
}
