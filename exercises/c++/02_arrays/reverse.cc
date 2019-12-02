#include <iostream>

template <typename T>
T* allocateArray(std::size_t sz);

template <typename T>
void printArray(const T a[], std::size_t sz);

int main(){
	
	std::size_t s;
	std::cout << "Give me the size of the array" << std::endl;
	std::cin >> s;
	int *ar{allocateArray<int>(s)};
	printArray(ar,s);

	delete ar;
}

template <typename T>
T* allocateArray(std::size_t sz){
	
	T* ar{new T[sz]};
	
	for(int i = 0; i < sz; i++)
	{
		std::cout << "Give me either a double or an int please" << std::endl;
		std::cin >> ar[i];
	}

	return ar;
}

template <typename T>
void printArray(const T a[], std::size_t sz){

	for(int i = sz-1; i >= 0; i--){

		std::cout << a[i] << std::endl;
	}
}
