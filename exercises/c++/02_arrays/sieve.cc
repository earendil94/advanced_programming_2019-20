#include <iostream>

void sieve(std::size_t dim);
int next(int* ar, unsigned int dim, int i);

int main(){
	
	sieve(100);

}

void sieve(std::size_t dim){

	int* primes {new int[dim]};

	primes[0] = 0;
	primes[1] = 0;

	for(unsigned int i = 2; i<dim; i++)
		primes[i] = 1;

	for( unsigned int i = 2; i < dim; i = next(primes,dim,i)){
		for(unsigned int k = i; i*k < dim; k++)
			primes[i*k] = 0;
	}
	
	for(unsigned int i = 0; i < dim; i++)
		if( primes[i] == 1)
			std::cout << i << std::endl;

	delete [] primes;
}

int next(int *ar, unsigned int dim, int i){

	for(unsigned int k = i+1; k < dim; k++)
		if( ar[k] == 1)
			return k;

	return dim;
}

