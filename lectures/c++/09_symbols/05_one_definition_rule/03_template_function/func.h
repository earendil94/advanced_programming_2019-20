#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>

//Templates are fine to keep into headers.
template <class T = double>
void dummy() {
  T t{};
  std::cout << t << ": dummy\n";
}

#endif /* _FUNC_H_ */
