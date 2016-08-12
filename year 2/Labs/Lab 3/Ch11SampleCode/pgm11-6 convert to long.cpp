/* pgm11-6.cpp - Chapter 11 Sample Program

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
    Date(int = 7, int = 4, int = 2012);    // constructor
    operator long();     // conversion operator prototype
    void showDate();
};

// class implementation section
Date::Date(int mm, int dd, int yyyy) // constructor
{
  month = mm;
  day = dd;
  year = yyyy;
}

// conversion operator definition for converting a Date to a long int
Date::operator long()   // must return a long, as its name implies
{
  long yyyymmdd;
  yyyymmdd = year * 10000 + month * 100 + day;
  return(yyyymmdd);
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
  Date a(4,1,2012);  // declare and initialize one object of type Date
  long b;            // declare an object of type long

  b = long(a);       // call the conversion function

  cout << "a's date is ";
  a.showDate();
  cout << "\nThis date, as a long integer, is " << b << endl;
  
  cout << endl << endl;
  system("pause");
  return 0;
}
