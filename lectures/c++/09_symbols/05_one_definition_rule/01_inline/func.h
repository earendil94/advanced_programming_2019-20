#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>

//The inline is a suggestion to the compiler to not put a jump but copy the function there.
//In c++ inline implies internal linkage. In C you would have to say static inline.
inline void dummy() {
  std::cout << "dummy\n";
}

#endif /* _FUNC_H_ */
