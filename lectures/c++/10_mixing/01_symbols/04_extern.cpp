#include <iostream>
//This is externed as a cblock. For example you can't do function overloading in here
//C symbols are easy to interpret. C++ symbols are hard
extern "C"{
  void hello(){
    std::cout << "Hello, World" << std::endl;
  }
}

int main(){
  hello();
}
