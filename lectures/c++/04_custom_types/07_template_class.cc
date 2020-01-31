#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  // automatically release the acquired memory
  // RAII: Resource acquisition is initialization. The resource you acquire get released in the distructor.
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  // This const??
  std::size_t size() const { return _size; } //I recon the const here might signal that the vector
  //on which we are calling the size function is actually const. As in the first function below.

  //Trying the non-const version
  //std::size_t size() { return _size; } 
  //passing ‘const Vector<double>’ as ‘this’ argument discards qualifiers
  //So the "middle const" is actually necessary in case you call this function on a const vector!

  num& operator[](const std::size_t i) { return elem[i]; } 
  //This does not return a const and we get angry
  //But we need this if we use v[i] as lvalue, which we can!

  //What about this?
  //const num& operator[](const std::size_t i) { return elem[i]; }
  //Can't define this and the one before at the same time 

  // try to comment this line and recompile
  const num& operator[](const std::size_t i) const { return elem[i]; }
};

//This const Vector<T> ... means that the compiler, when evaluating v[i], will search for a function with a const Vector in the argument.
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v}; //A pointer to a vector

  //Operator overloading with pointers is something tricky. ACHTUNG!
  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name

  std::cout << *pv << std::endl;

  //Operator overloading with references is perfectly fine tho.
  Vector<double>& rv{v};

  rv[5] = 555;

  std::cout << v << std::endl;

  return 0;
}
