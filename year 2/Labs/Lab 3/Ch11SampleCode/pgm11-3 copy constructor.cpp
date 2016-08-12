/* pgm11-3.cpp - Chapter 11 Sample Program

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
    int month;
    int day;
    int year;
  public:
    Date(int = 7, int = 4, int = 2012);   // constructor
    Date(const Date&);   // copy constructor
    void showDate();   // member function to display a date
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}

Date::Date(const Date& olddate)
{
  month = olddate.month;
  day = olddate.day;
  year = olddate.year;
}

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
  Date a(4,1,2011), b(12,18,2012); // use the constructor
  Date c(a);   // use the copy constructor
  Date d = b;  // use the copy constructor

  cout << "\nThe date stored in a is ";
  a.showDate();
  cout << "\nThe date stored in b is ";
  b.showDate();
  cout << "\nThe date stored in c is ";
  c.showDate();
  cout << "\nThe date stored in d is ";
  d.showDate();

  cout << endl << endl;
  system("pause");
  return 0;
}
