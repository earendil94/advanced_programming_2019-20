#include <iostream>

void getPrimes(std::size_t n);

int main(){

	int n = 100;
	getPrimes(n);
}

void getPrimes(std::size_t n){

	int size = 2;
	
	int *primes{new int[size]};
	int position = 0;

	primes[position] == 2;
	position++;

	for( int i = 3; i < n; i++){
		for(int k = 2; k < i; k++){
			if( i%k == 0){
				break;
			}
			else if( i%k != 0 && k == i-1){
			       primes[position] = i;
				position++;	
		       	       break;
			}
		}

		
		if( position == size){
			size++;
			int *newPrimes{ new int[size]};
			for(int z = 0; z < size-1; z++)
				newPrimes[z] = primes[z];

			delete primes;
			primes = newPrimes;
		}	
	}
	
	for(int i = 0; i < position; i++)
		std::cout << primes[i] << std::endl; 	
}
