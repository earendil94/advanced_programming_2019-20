#include "timer.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

timer<> t;

template <typename I>
void set_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type; 
  //put typename if you actually want a type
  //Otherwise you get a static variable
  std::set<value_type> set{first, last};
  t.stop();
}

template <typename I>
void vector_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  std::vector<value_type> v{first, last};
  std::sort(v.begin(), v.end());
  auto it = std::unique(v.begin(), v.end()); //returns an iterator to the last unique element
  t.stop();
  (void) std::distance(first, it);
}

using namespace std::chrono;
int main() {
  using value_type = int;
  //n <<= 1 is basically multiplying by 2 (shift 1 bit to the left)
  //n is less than 1 << 25 (aka 1 shifted 25 times, aka 2^25)
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    std::vector<value_type> v(n);
    std::iota(v.begin(), v.end(), value_type(-1024)); //This is filling the vector with n+1, n+2, n+3,...
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i) {
      v[i] = int{v[i]} & 1023; //basically every number is going back to [0,1023]
    }
    std::cout << std::setw(15) << n << "\t";
    // set_timed(n,v.begin(),v.end());
    vector_timed(n, v.begin(), v.end());
  }
}
