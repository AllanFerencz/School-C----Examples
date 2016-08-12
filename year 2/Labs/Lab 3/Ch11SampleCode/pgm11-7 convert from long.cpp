/* pgm11-7.cpp - Chapter 11 Sample Program

   Modified by: T. MacDonald, Aug 2012
   For: CPRG 4202 - C++ Programming II
   Reference:
   Bronson, G. (2011). A First Book of C++, Fourth Edition. Course Technology.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// class declaration section
class Date
{
  private:
    int month, day, year;
  public:
    Date(int = 7, int = 4, int = 2012);  // constructor
    // constructor for converting from long to Date
    Date(long);
    void showDate();
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)  // constructor
{
  month = mm;
  day = dd;
  year = yyyy;
}

// constructor for converting from long to Date
Date::Date(long findate)
{
  year = int(findate/10000.0);
  month = int((findate - year * 10000.0)/100.0);
  day = int(findate - year * 10000.0 - month * 100.0);
}

// member function to display a date
void Date::showDate()
{
  cout << setfill('0')
       << setw(2) << month << '/'
       << setw(2) << day << '/'
       << setw(2) << year % 100;
  return;
}

int main()
{
  Date a;   // initialized by the default constructor
  Date b(20061225L);  // initialize with a long integer
  Date c(4,1,2007);   // initialize with the specified values

  cout << "Dates a, b, and c are ";
  a.showDate();
  cout << ", ";
  b.showDate();
  cout << ", and ";
  c.showDate();
  cout << ".\n";

  a = Date(20150103L);  // convert a long to a Date

  cout << "Date a is now ";
  a.showDate();
  cout << ".\n";

  cout << endl << endl;
  system("pause");
  return 0;
}
