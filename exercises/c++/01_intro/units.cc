#include <iostream>

void convert(double &v, std::string &u);

int main(){

	std::string unit;
	double measure;

	std::cout << "Give me a number and its unit of measure" << std::endl;
	std::cin >> measure >> unit;

	std::cout << "------------------" << std::endl;
	std::cout << "Your value is: " << measure << " " << unit << std::endl;

	convert(measure, unit);

	std::cout << "Your value is: " << measure << " " << unit << std::endl;

}

void convert(double &v, std::string &u){

	if( u == "inches"){
		u = "m";
		v = v*0.0254;
	}

}
