/** StaticBinding.cpp
 *
 *	Overriding a base method using an overloaded derived method does
 * 	not always work the way you might want. In this demo, calling 
 *	ShowDate() from either the MyDate class or the IsoDate class 
 *  produces the same result; the date in dd/mm/yy format. It does 
 *  this despite IsoDate overloading (string) to put the date in 
 *  yyyy-mm-dd format.
 *
 *	Function Binding. By default, the matching of a method call to the 
 *	method actually called is determined at compile time. This is called
 *  "static binding". The compiler first encounters the call to (string)
 *  in the base class .ShowDate() method and determines then that it 
 *  should always call the version of (string) in the base class 
 *  (i.e. MyDate::operator string), regardless of what kind of object 
 *  called .ShowDate()
 *
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@version	2014.01
 *	@since		2014-10-11
 *	@see		Bronson, G. (2011). Chapter 12 Extending Your Classes. 
 *					In A First Book of C++, Fourth Edition. Course Technology.
 *	@see		Program Listing 12-2 (pgm12-2.cpp)
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class MyDate  // A simple version of the MyDate class
{
	protected:
		int myMonth;
		int myDay;
		int myYear;
	public:
		// default constructor
		MyDate():myMonth(7), myDay(1), myYear(2000){} 
		
		// Shows the date on the console in a format
		void ShowDate() const { cout << (string) *(this) << endl;} 
		
		// converts the date to a formatted string (dd/mm/yy)
		operator string() const; 
};

class IsoDate : public MyDate // A simple version of IsoDate
{
	public:
		// converts the date to a formatted string (yyyy-mm-dd)
		operator string() const; // override the base class version
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

// MyClass:: operator string
MyDate::operator string() const
{
    stringstream dateString; 	
	// build the date string in the format dd/mm/yy
	dateString << setfill('0')
         << setw(2) << myDay << '/'
         << setw(2) << myMonth << '/'
         << setw(2) << myYear % 100;
	return dateString.str();
}
// IsoClass:: operator string
IsoDate::operator string() const
{
    stringstream dateString; 	
	// build the date string in the format yyyy/mm/dd
	dateString << setfill('0')
         << setw(4) << myYear << '-'
         << setw(2) << myMonth << '-'
         << setw(2) << myDay;
	return dateString.str();
}


