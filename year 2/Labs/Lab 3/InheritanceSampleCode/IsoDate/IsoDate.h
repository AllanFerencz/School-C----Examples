/** IsoDate.h - Deriving a new class from the MyDate Class 
 *	
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@author		
 *	@version	2014.01
 *	@since		2014-10-11
 *	@see		MyDate.h (version 2014.03)
 *	@see		http://en.wikipedia.org/wiki/ISO_8601		
*/

#ifndef _ISO_DATE_H

#define _ISO_DATE_H

#include <iostream> 	// for console I/O
#include <stdexcept>	// for standard exceptions
#include "MyDateV3.h"	// version 2014.03

using namespace std;

class IsoDate : public MyDate
{
	public:
	
		/***************************************************************************
		*	CONSTRUCTORS
		***************************************************************************/
	
		/** Default Constructor
		 *	Invokes default constructor for MyDate which initializes the 
		 *  year, month, and day fields to 2000, 1, and 1.
		 */
		IsoDate():MyDate() {}
		
		/** Parametrized (int, int, int) Constructor
		 *	Sets the year, month and day fields to parameters.
		 *	@param year (int) - the year to set to
		 *	@param month (int) - the month to set to
		 *	@param day (int) - the day to set to
		 */
		IsoDate(int year, int month, int day):MyDate(day, month, year){} // invokes MyDate(int, int, int) constructor
		
		/** Parametrized (const MyDate&) Constructor
		 *	Sets the year, month and day fields from a MyDate object. Also used to 
		 *  convert a MyDate to an IsoDate.
		 *	@param myDate (MyDate) - the MyDate object to convert
		 */
		IsoDate(const MyDate& myDate):MyDate(myDate) {}  // invokes copy constructor for MyDate

		/***************************************************************************
		*	PUBLIC MUTATORS
		***************************************************************************/
		/** setDate()
		 *	Sets the day/month/year fields to parameters.
		 *	@param day (int) - the day to set to
		 *	@param month (int) - the month to set to
		 *	@param year (int) - the year to set to
		 */
		void setDate(int year, int month, int day) override { setYear(year); setMonth(month); setDay(day); }
		/***************************************************************************
		*	OPERATORS
		***************************************************************************/
		/** operator (string) (Typecast)
		 *	Typecasts this date as a string.
		 *	@return (string) - the date stored formatted as a Long Date
		 */		
		virtual operator string() const override;  // should override MyDate::operator string()

		/** operator << (Insertion/Output)
		 *	Inserts a date into an ostream
		 *  @param  out (ostream by ref) - the output stream to insert into
		 *  @param  theDate (const IsoDate by ref) - the date to insert
		 *	@return (ostream by ref) - supports daisy-chaining
		 */
		friend ostream& operator<<(ostream& out, const IsoDate& theDate);
		
		/** operator >> (Extraction/Input)
		 *	Extracts a date from an istream
		 *  @param  in (istream by ref) - the input stream to extract from
		 *  @param  theDate (IsoDate by ref) - stores the extracted date
		 *	@return (istream by ref) - supports daisy-chaining
		 */
		friend istream& operator>>(istream& in, IsoDate& theDate);
	
};

// operator << (Insertion/Output)
ostream& operator<<(ostream& out, const IsoDate& theDate)
{
    // output the date in the format yyyy/mm/dd
	out << (string) theDate;
    return out;  // return the output stream
}

// operator >> (Extraction/Input)
istream& operator>>(istream& in, IsoDate& theDate)
{
    int day;  // temp day
    int month; // temp month
    int year; // temp year

    in >> year; // get year
    in.ignore(); // ignore the '-'
    in >> month; // get month
    in.ignore(); // ignore the '-'
    in >> day; // get day
    
    // store the date
    theDate.setDate(year, month, day); // using IsoDate version
    
    return in; // return the input stream
}

// IsoDate::operator string definition		
IsoDate::operator string() const
{
	stringstream dateString; // string stream to build the formatted date string
	
	// build the date string in the format yyyy/mm/dd
	dateString << setfill('0')
         << setw(4) << getYear() << '-'
         << setw(2) << getMonth() << '-'
         << setw(2) << getDay();
	return dateString.str();
}
#endif
