#include <iostream>

//This one instead is necessary in order to let your compiler understand that I want 
//The following function to be compiled with C symbols.
extern "C" {
void hello_from_cpp() {
  std::cout << "hello from cpp\n";
}
}
