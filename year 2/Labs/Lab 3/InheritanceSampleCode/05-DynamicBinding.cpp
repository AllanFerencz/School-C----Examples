/** DynamicBinding.cpp
 *
 *	Function Binding. Dynamic binding causes the matching of method call 
 *  to the method version actually called to be determined at run-time 
 *	rather than compile-time. Dynamic binding is achieved using virtual 
 *	methods. A virtual method will base the decision of which version of 
 *	a method to call at run-time, based on the object making the call.
 *
 *	Since (string) is 'virtual', .ShowDate() will call version of (string)
 *	that matches the object type .ShowDate() was called from.
 *
 *	'override' is a C++ 11 addition. Dynamic binding works without using 
 *	it, but if you specify 'override' in the derived class and the base 
 *	class version is not virtual, it will generate a compile error. This 
 * 	is good for debugging/error-checking purposes.
 *
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@version	2014.01
 *	@since		2014-10-11
 *	@see		Bronson, G. (2011). Chapter 12 Extending Your Classes. 
 *					In A First Book of C++, Fourth Edition. Course Technology.
 *	@see		Program Listing 12-3 (pgm12-3.cpp)		
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
		virtual operator string() const; // virtual
};

class IsoDate : public MyDate // A simple version of IsoDate
{
	public:
		// converts the date to a formatted string (yyyy-mm-dd)
		operator string() const override; // override the base class version
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


