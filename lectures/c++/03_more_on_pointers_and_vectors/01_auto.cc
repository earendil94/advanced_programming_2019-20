#include <cmath>
#include <iostream>
//This line below is interesting af and pretty self-explanatory
#if __cplusplus > 201103L

template <class T>
void debug(T);

template <class T>
auto init(const std::size_t l) {
  return new T[l]{};
}

#else

template <class T>
T* init(const std::size_t l) {
  return new T[l]{};
}

#endif

int main() {
  auto b = true;          // a bool
  auto ch = 'x';          // a char
  auto i = 123;           // an int
  auto d = 1.2;           // a double
  auto z = std::sqrt(d);  // z has the type of whatever sqrt(d) returns
  auto ui = 0u;           // unsigned int
  auto llui = 0llu;       // long long unsigned int

  for (auto i = 0; i < 7; ++i)
    std::cout << i << std::endl;

  auto pb = &b;  // guess what.. How can I know?

  //Forcing a compile error to see what is actually the type of pb
  //debug(pb);

  //As always with template function, you need to specify between <> the type of data used.
  auto ps = init<double>(11);
  delete[] ps;
  return 0;
}
