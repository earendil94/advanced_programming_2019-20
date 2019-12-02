#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc;

  //This is an array of pointers to integer
  int* ap[7];

  //We can cast a pointer to this thing, but...
  void* pv{pi};
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  // Because we don't know the dimension of void* (for a char* is 1, int* is 4...) 
  //void* is mostly used in C where you don't have templates (malloc is an example of function returning a void*
  //Since C is weakly typed you may not cast the result of malloc to a specific type.
  //C++ is actually strongly typed, so you need to explicitly cast the malloc here:
  //double *a = (double *) malloc(sizeof(double)*N); This is a C-style cast.
  //You can also do double *a = static_cast<double *>(malloc...) 


  int* pi2{static_cast<int*>(pv)};

  pv = ppc;
  pv = ap;
  pv = pi;

  //This is the null version in c++: using c++11? Use nullpointer and don't mix it with null
  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;  // error, why?
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr. don't dereference it, you'll get segfault.

  // pi = NULL; // please don't do this

  double* da{new double[5]{}};
  delete[] da;  // dangling pointer
  da = nullptr;

  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  //This works in the same way because if pi is nullpointer than it's address is 0
  if (pi)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  //This is a pointer to function that has a const char* as argument and returns int.
  int (*fp)(const char*);
  
  //They both work.
  fp = func1;
  fp("hello");

  fp = &func2;
  fp("world");

  // fp = func3; // error: wrong signature
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3; //decltype defines a variable called x of the type of whatever is returned by func3
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
