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
  std::size_t size() const { return _size; }

  num& operator[](const std::size_t i) { return elem[i]; }

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

  Vector<double>* pv{&v};

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
