#include "constants.h"
#include <iostream>

//It is the linker job to find the definition of the function defined here below
double area_circle(const double);
double golden_ratio(const double);
//It is a global variable defined in a different compilation unit: not in a different header
//If you extern, the linker will warn you that there are two global variables with the same name
extern int circle_counter; 

int main() {
  std::cout << area_circle(1) << std::endl;
  std::cout << area_circle(2) << std::endl;

  std::cout << golden_ratio(1) << std::endl;

  std::cout << circle_counter << std::endl;
  std::cout << "[main] pi = " << pi << std::endl;

  return 0;
}
