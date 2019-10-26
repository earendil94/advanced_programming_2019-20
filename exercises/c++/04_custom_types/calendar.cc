#include <iostream>

enum class month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

class Date{

  private:
      unsigned int _day;
      month _month;
      int _year;
      void add_one_day();

  public:
      Date(unsigned int day, month m, int year);
      ~Date() {}
      unsigned int day() const {return _day;} //This const let the compiler know that this is not gonna change the class
      month get_month() const {return _month;}
      int year() const {return _year;}
      void add_days(const unsigned int n);

};

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool is_leap(const int y);
std::ostream& operator<<(std::ostream& os, const month& m);
std::ostream& operator<<(std::ostream& os, const Date& d);


int main(){

  Date tag{28,month::Feb,1968};
  std::cout << "Tag:" << tag <<  '\n';

  std::cout << "+1 year" << '\n';
  tag.add_days(365);
  std::cout << "Tag:" << tag <<  '\n';


  std::cout << "+1 month" << '\n';
  tag.add_days(31);
  std::cout << "Tag:" << tag <<  '\n';

  Date abend{31,month::Mar,1969};

  std::cout << "Tag == abend: " << (tag==abend) <<  '\n';

  std::cout << "Tag != abend: " << (tag!=abend) <<  '\n';

  std::cout << "Abend: " << abend << '\n';

  std::cout << "Is 1968 a leap year?: " << is_leap(1968) <<  '\n';
}




Date::Date(unsigned int day, month m, int year):
  _day{day},
  _month{m},
  _year{year}
{}

void Date::add_days(const unsigned int n){
  for(int i = 0; i < n; i++)
    add_one_day();
}

void Date::add_one_day(){

  month m = get_month();

  switch (m) {
    case month::Jan: case month::Mar : case month::May : case month::Jul : case month::Aug : case month::Oct:
      if( day() == 31){
        _day = 1;
        _month = static_cast<month> (static_cast<unsigned int>(_month) + 1);
      } else
        _day += 1;
      break;
    case month::Apr : case month::Jun : case month::Sep : case month::Nov:
      if( day() == 30){
        _day = 1;
        _month = static_cast<month>(static_cast<unsigned int>(_month) + 1);
      } else
        _day += 1;
      break;
    case month::Feb:
      if( day() == 28 ){
        _day = 1;
        _month = static_cast<month>(static_cast<unsigned int>(_month) + 1);
      } else
        _day += 1;
      break;
    case month::Dec:
      if( day() ==  31){
        _day = 1;
        _month = static_cast<month>(0);
        _year += 1;
      } else
        _day += 1;
      break;
    default:
      break;
    }
}

bool operator==(const Date& lhs, const Date& rhs){

  if( lhs.day() == rhs.day() && lhs.get_month() == rhs.get_month() && lhs.year() == rhs.year())
    return true;

  return false;
}

bool operator!=(const Date& lhs, const Date& rhs){

  if(!(lhs == rhs))
    return true;

  return false;

}

std::ostream& operator<<(std::ostream& os, const Date& d){
  return std::cout << d.day() << "/" << d.get_month() << "/" << d.year() << '\n';
}

std::ostream& operator<<(std::ostream& os, const month& m){
  return std::cout << static_cast<int>(m) + 1;
}

bool is_leap(const int y){
  if(y%4 == 0 && y%100 != 0)
    return true;

  return false;
}
