#include <array>
#include <iostream>

// template <class T, std::size_t N>
// struct array;

int main() {
  std::array<int, 4> a{1, 2, 3, 4};
  std::array<int, 4> b{a};  // I can copy element-wise from another std::array
                            // this is not possible with plain built-in arrays
  b = a;

  //From c++11 this java-like syntax is available.
  for (auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  a[0] = 0;  // same subscripting operator without bound checking

  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (const auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  //Here is actually modifying the array a because it has passed a reference to it.
  for (auto& x : a)
    x *= 10;

  for (auto i = 0u; i < a.size(); ++i)
    std::cout << "a[" << i << "] = " << a[i] << std::endl;

  b.at(90);  // bound checking at run-time

  return 0;
}
