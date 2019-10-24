#include <iostream>
#include <array>
#include <random>
#include <utility>
#include <sstream>
#include <vector>


//#TODO: Change rows and columns in transpose!
template <std::size_t SIZE>
void transpose(std::array<double,SIZE> &m, const size_t rows, const size_t columns);
template <std::size_t	SIZE>
void printMatrix(std::array<double,SIZE> const &m, int rows, int columns);
void vectorTranspose(std::vector<double> &m, size_t &rows, size_t &columns);
void printMatrixVector(std::vector<double> const &m, const int rows, const int columns);



int main(int argc, char **argv){

	if(argc <= 2){
		std::cerr << "Please, I need rows and columns to wokr!" << '\n';
		exit(-1);
	}

	std::size_t r;
	{
		std::istringstream is{argv[1]};
		is >> r;
	}

	std::size_t c;
	{
		std::istringstream is{argv[2]};
		is >> c;
	}

	constexpr size_t rows = 4;
	constexpr size_t columns = 6;


	std::array<double,rows*columns> m;
	double lower_bound = 0;
	double upper_bound = 10;
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;

	for(int i = 0; i < rows; i++){
		for(int k = 0; k < columns; k++){
			m[ i*columns + k] = unif(re);
		}
	}

	std::cout << "###ARRAY_VERSION###" << '\n';
	std::cout << "Before transpose" << std::endl;


	printMatrix(m,rows,columns);
	transpose(m,rows,columns);

	std::cout << "--------------------" << std::endl;

	std::cout << "After transpose" << std::endl;
	std::cout << "r:" << r << "; c: " << c << '\n';
	printMatrix(m,columns,rows);

	//Vector ri-vectorTranspose

	std::cout << "---------------------" << '\n';
	std::cout << "---------------------" << '\n';
	std::cout << "###VECTOR_VERSION###" << '\n';
	std::vector<double> v;
	for(int i = 0; i < r*c; i++){
		v.push_back(unif(re));
	}

	std::cout << "Before transpose" << std::endl;
	//std::cout << "r:" << r << "; c: " << c << '\n';
	printMatrixVector(v, r, c);
	vectorTranspose(v,r,c);
	std::cout << "--------------------" << std::endl;

	std::cout << "After transpose" << std::endl;
	//std::cout << "r:" << r << "; c: " << c << '\n';
	printMatrixVector(v,r,c);


}

template<std::size_t SIZE>
void transpose(std::array<double,SIZE> &m, const size_t rows, const size_t columns){

	std::array<double,SIZE> trans;

	for( int i = 0; i < columns; i++){
		for( int k = 0; k < rows; k++){
			trans[i*rows + k] = m[k*columns + i];
		}
	}

	m.swap(trans);

}

template<std::size_t SIZE>
void printMatrix(std::array<double,SIZE> const &m, int rows, int columns){

	for(int i = 0; i < rows; i++){
		for(int k = 0; k < columns; k++){
			std::cout << m[i*columns + k] << "  ";
		}

		std::cout << std::endl;
	}
}

void printMatrixVector(std::vector<double> const &m, const int rows, const int columns){
	for(int i = 0; i < rows; i++){
		for(int k = 0; k < columns; k++){
			std::cout << m.at(i*columns + k) << '\t';
		}
		std::cout << std::endl;
	}
}

void vectorTranspose(std::vector<double> &m, size_t &rows, size_t &columns){

	std::vector<double> trans(rows*columns,0);

	for( int i = 0; i < columns; i++){
		for( int k = 0; k < rows; k++){
			trans[i*rows + k] = m[k*columns + i];
		}
	}

	m.swap(trans);

	int temp = rows;
	rows = columns;
	columns = temp;
}
