/* pgm11-8.cpp - Chapter 11 Sample Program

   Modified by: T. MacDonald, Aug 2012
   For: CPRG 4202 - C++ Programming II
   Reference:
   Bronson, G. (2011). A First Book of C++, Fourth Edition. Course Technology.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// forward declaration of class Intdate
class Intdate;

// class declaration section for Date
class Date
{
  private:
    int month, day, year;
  public:
    Date(int = 7, int = 4, int = 2012);  // constructor
    operator Intdate();  // conversion operator from Date to Intdate
    void showDate();
};

// class declaration section for Intdate
class Intdate
{
  private:
    long yyyymmdd;
  public:
    Intdate(long = 0);    // constructor
    operator Date();  // conversion operator from Intdate to Date
    void showint();
};

// class implementation section for Date
Date::Date(int mm, int dd, int yyyy)  // constructor
{
  month = mm;
  day = dd;
  year = yyyy;
}

// conversion operator function converting from Date to Intdate class
Date::operator Intdate()   // must return an Intdate object
{
  long temp;
  temp = year * 10000 + month * 100 + day;
  return(Intdate(temp));
}

// member function to display a Date
void Date::showDate()
{
  cout << setfill('0')
        << setw(2) << month << '/'
        << setw(2) << day << '/'
        << setw(2) << year % 100;
  return;
}

// class implementation section for Intdate
Intdate::Intdate(long ymd)  // constructor
{
  yyyymmdd = ymd;
}

// conversion operator function converting from Intdate to Date class
Intdate::operator Date()   // must return a Date object
{
  int mo, da, yr;
  yr = int(yyyymmdd/10000.0);
  mo = int((yyyymmdd - yr * 10000.0)/100.0);
  da = int(yyyymmdd - yr * 10000.0 - mo * 100.0);
  return(Date(mo,da,yr));
}

// member function to display an Intdate
void Intdate::showint()
{
  cout << yyyymmdd;
  return;
}

int main()
{
  Date a(4,1,2011), b;      // declare two Date objects
  Intdate c(20121215L), d;  // declare two Intdate objects
  b = Date(c);      // cast c into a Date object
  d = Intdate(a);   // cast a into an Intdate object

  cout << " a's date is ";
  a.showDate();
  cout << "\n   as an Intdate object this date is ";
  d.showint();

  cout << "\n c's date is ";
  c.showint();
  cout << "\n   as a Date object this date is ";
  b.showDate();
  
  cout << endl << endl;
  system("pause");
  return 0;
}
