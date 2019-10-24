#include <iostream>

enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

//This is bad programming, dec below would be ambiguous
using namespace std;

//To finally avoid our std:: stuff
using std::cout;
using std::endl;

int main() {
  cout << nov << endl;
  // cout << dec << endl;

  return 0;
}
