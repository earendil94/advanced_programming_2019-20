#include <iostream>
#include <algorithm>
#include <vector>

double myAverage(std::vector<double> const &v);
double myMedian(std::vector<double> &v);

int main(){

  double temp;
  std::vector<double> temperatures;


  while (std::cin >> temp ) {
    temperatures.push_back(temp);
  }

  std::cout << "The average of our vector is: " << myAverage(temperatures) << '\n';
  std::cout << "The median of our vector is: " << myMedian(temperatures) << '\n';

}

double myAverage(std::vector<double> const &v){

  double av {0};

  for (double i : v) {
    av += v[i];
  }

  return av/v.size();

}

double myMedian(std::vector<double> &v){

  std::sort(v.begin(),v.end());

  int medium_point = v.size()/2;

  return v[medium_point];

}
