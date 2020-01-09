#ifndef __constants__
#define __constants__

constexpr double pi{3.14159265358};
const double phi{1.6180339887};

//static in front of a global symbol means internal linkage.
//Each compilation unit has its own copy of the variable!
//Instead, the circle variable on circle is really global. And we need to use extern
//In c++, const implies static. In C no. If you want to have variables shared in multiple compilation units,
//write static const phi in C.
//With constexpr we are requiring the computation to be done at compile time.
//In template meta-programming we are required to use constexpr to define real constants.

//With nm -C xos.o 
//We can see the symbols underlying the binary file of xos. 

//Function overloading can be implemented because the symbols also have the parameter type of the function 
//in their name.
//Lower case symbol means internal linkage.

#endif
