/* pgm11-4.cpp - Chapter 11 Sample Program

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
    Date(int = 7, int = 4, int = 2012);    // constructor
    Date operator=(const Date &);  // assignment operator prototype
    void showDate();        // member method to display a date
};

// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}

//The new assignment operator returns an object of type Date
Date Date::operator=(const Date& newdate)
{
  day = newdate.day;        // assign the day
  month = newdate.month;    // assign the month
  year = newdate.year;      // assign the year

  return *this;
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
  Date a(4,1,1999), b(14,18,2012), c(1,1,2014); // declare three objects

  cout << "Before assignment a's date value is ";
  a.showDate();
  cout << "\nBefore assignment b's date value is ";
  b.showDate();
  cout << "\nBefore assignment c's date value is ";
  c.showDate();

  a = b = c;    // multiple assignment

  cout << "\n\nAfter assignment a's date value is ";
  a.showDate();
  cout << "\nAfter assignment b's date value is ";
  b.showDate();
  cout << "\nAfter assignment c's date value is ";
  c.showDate();

  cout << endl << endl;
  system("pause");
  return 0;
}
