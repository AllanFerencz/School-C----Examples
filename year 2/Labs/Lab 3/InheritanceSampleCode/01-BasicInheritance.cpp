/** 01-BasicInheritance.cpp
 *
 *	A very simple example of basic inheritance with adhoc polymorphism
 *	(i.e. method overloading)
 *
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@version	2014.01
 *	@since		2014-10-11
 *	@see		Bronson, G. (2011). Chapter 12 Extending Your Classes. 
 *					In A First Book of C++, Fourth Edition. Course Technology.
 *  @see		http://www.cplusplus.com/doc/tutorial/inheritance/
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class MyDate  // A simple version of the MyDate class
{
	protected: // Note the change from private
		int myMonth;
		int myDay;
		int myYear;
	public:
		// default constructor
		MyDate():myMonth(7), myDay(1), myYear(2000){} 
		
		// shows the date as a formatted string (dd/mm/yy)
		void ShowDate() const;
};

class IsoDate : public MyDate // A simple version of IsoDate, inherits MyDate
{
	public:
		// shows the date as a formatted string (yyyy-mm-dd)
		void ShowDate() const; // override the base class version
};

int main()
{
	MyDate date;
	IsoDate isoDate;
	
	cout << "\nMyDate::ShowDate() results in:  ";
	date.ShowDate();
	
	cout << "\nIsoDate::ShowDate() results in: ";
	isoDate.ShowDate();
	
	
	cout << endl << endl;
	return 0;
}

// MyClass:: ShowDate()
void MyDate::ShowDate() const
{
	cout << setfill('0')
         << setw(2) << myDay << '/'
         << setw(2) << myMonth << '/'
         << setw(2) << myYear % 100 << setfill(' ');

}
// IsoClass:: ShowDate()
void IsoDate::ShowDate() const
{
    cout << setfill('0')
         << setw(4) << myYear << '-'
         << setw(2) << myMonth << '-'
         << setw(2) << myDay << setfill(' ');;
}


