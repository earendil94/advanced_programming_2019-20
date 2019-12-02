#include <iostream>

int main(){

	int repetitions;
	std::string line;
	std::string prev_line;
	prev_line = "";
	repetitions = 1;

	while(std::getline(std::cin,line)){

		if( line == prev_line ){
			repetitions++;
			continue;
		}
		else if (prev_line == ""){
			prev_line = line;
			continue;
		}
		else{
			std::cout << repetitions << " " << prev_line << std::endl;
			repetitions = 1;
			prev_line = line;
		}
	}

	std::cout << repetitions << " " << prev_line << std::endl;
}
