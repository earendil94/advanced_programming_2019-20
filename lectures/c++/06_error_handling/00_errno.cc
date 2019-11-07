#include <cmath>
#include <iostream>

int main() {

  //errno is a macro indicating an error code propagated through the 
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;

  //errno still = 33
  d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;
  
  //Error handling
  errno = 0;

  //We good again
  d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  return 0;
}
