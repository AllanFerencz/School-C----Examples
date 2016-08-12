/* pgm11-1.cpp - Chapter 11 Sample Program

   Modified by: T. MacDonald, Aug 2012
   For: CPRG 4202 - C++ Programming II
   Reference:
   Bronson, G. (2011). A First Book of C++, Fourth Edition. Course Technology.
*/

#include <iostream>
using namespace std;

// class declaration section
class Date
{
  private:
    int month;
    int day;
    int year;
  public:
    Date(int = 7, int = 4, int = 2012);  // constructor
    bool operator==(Date&);  // prototype for the operator== function
};

// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}

bool Date::operator==(Date& date2)
{
  if(day == date2.day && month == date2.month && year == date2.year)
    return true;
  else
    return false;
}

int main()
{
  Date a(4,1,2012), b(12,18,2010), c(4,1,2012); // declare 3 objects

  if (a == b)
    cout << "Dates a and b are the same." << endl;
  else
    cout << "Dates a and b are not the same." << endl;
  if (a == c)
    cout << "Dates a and c are the same." << endl;
  else
    cout << "Dates a and c are not the same." << endl;
 
  cout << endl << endl;
  system("pause");
  return 0;
}
