#include <iomanip>
#include <iostream>

void print_ma(int m[][5], int dim1);  // ugly and not flexible
// void print_ma(int m[][], int dim1, int dim2); // error second
// dimension must be
// knwon at compile time

void print_ma(int* p, int row, int col);  // the only possible solution

int main() {
  int ma[6][5];  // matrix: 6 rows, 5 columns each

  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 5; ++j)
      ma[i][j] = 10 * i + j;

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << std::setw(3) << ma[i][j];
    std::cout << std::endl;
  }

  //The matrix is still represented linearly! So basically it is an array of dimension nxm
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << &ma[i][j] << " ";
    std::cout << std::endl;
  }

  // int *pma {ma}; 		// error
  // int *pma[5] {ma};		// error
  // This way you are actually telling the compiler what he already knows, but this way we can actually use function properly defined on int*
  int* p{reinterpret_cast<int*>(ma)};
  // int* p {&ma[0][0]};

  // print_ma(ma, 6, 5); 	// error
  print_ma(p, 6, 5);

  auto d_ma = new int[6 * 5]{};

  std::cout << std::endl;

  print_ma(d_ma, 6, 5);
  delete[] d_ma;

  return 0;
}

//You can also see in p[i*col + j] how he's accessing to the array elements.
void print_ma(int* p, int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j)
      std::cout << std::setw(2) << p[i * col + j] << " ";
    std::cout << std::endl;
  }
}
