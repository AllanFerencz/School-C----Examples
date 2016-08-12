/* tm_io.cpp - Chapter 11 Sample Program

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
    Date(int = 7, int = 1, int = 2012); // constructor
    void setDate(int, int, int); // mutator - member method to copy a date
    void showDate() const;       // accessor - member method to display a date
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date &);
    
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}
void Date::setDate(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}
void Date::showDate() const
{
    cout << "The date is ";
    cout << setfill('0')
         << setw(2) << month << '/'
         << setw(2) << day << '/'
         << setw(2) << year % 100; // extract the last 2 year digits
    cout << endl;

  return;
}

ostream& operator<<(ostream &out, const Date& theDate)
{
    out << setfill('0')
         << setw(2) << theDate.month << '/'
         << setw(2) << theDate.day << '/'
         << setw(2) << theDate.year % 100; // extract the last 2 year digits
    out << endl;
    return out;          
}

istream& operator>>(istream &in, Date& theDate)
{
    cout << "\nMonth: ";
    in >> theDate.month;
    cout << "\nDay: ";
    in >> theDate.day;
    cout << "\nYear: ";
    in >> theDate.year;
    return in;     
         
}


int main()
{
  Date aDate;
  Date anotherDate(4, 1, 2000);

  cin >> aDate;
  
  cout << endl << aDate << endl << anotherDate;
  
  cout << endl << endl;
  system("pause");
  return 0;
}
