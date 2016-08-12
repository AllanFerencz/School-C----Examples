/** IsoDate_Test.cpp - Testing the IsoDate Class 
 *	
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@author		
 *	@version	2014.01
 *	@since		2014-10-11
  *	@see		IsoDate.h 
 *	@see		MyDateV3.h (version 2014.03)
 *	@see		http://en.wikipedia.org/wiki/ISO_8601		
*/

#include <iostream> 	// for console I/O
#include <stdexcept>	// for standard exceptions
#include "IsoDate.h"	

int main()
{
	cout << "\n******************************************************" << endl;
 	cout << "                      IsoDate" << endl;
	cout << "            " << (string) MyDate::Today() << endl;
	cout << "******************************************************" << endl << endl;
	
	
	try
	{
		IsoDate today = MyDate::Today();	// IsoDate(MyDate) constructor
		IsoDate canadaDay(MyDate::Today().getYear(), 7, 1); // IsoDate(int, int, int) constructor
		IsoDate userBirthDate; // IsoDate() default constructor
		long daysSinceBirth = 0L;
		int yearsOld = 0;
		bool needInput = true;
		
		// INPUT
		do
		{
			try
			{
				cout << "\nPlease enter the date you were born (yyyy-mm-dd): ";
				cin >> userBirthDate;
				needInput = false;
			}
			catch (exception& anException)
			{
				cout << anException.what() << endl;
			}
		} while(needInput);

		// PROCESSING
		
		// If Canada Day is in the past
		if(canadaDay < today)	// operator< from MyDate was inherited
		{
			// Make it NEXT Canada Day by adding 1 to the year
			canadaDay.setYear(canadaDay.getYear() + 1); // getYear from MyDate was inherited
		}
		
		// Calculate days since birth
		daysSinceBirth = today - userBirthDate; // new operator- in MyDate class version 2014.03
		
		// Calculate years since birth
		// Subtract the years...
		yearsOld =  today.getYear() - userBirthDate.getYear();
		// If this year's birthday is in the future
		if(IsoDate(today.getYear(), userBirthDate.getMonth(), userBirthDate.getDay()) > today)
			yearsOld--; // subtract one year
		
		
		// OUTPUT
		cout << "\nToday is " << (string) today 
			 << "\nNext Canada Day is " << canadaDay
			 << "\n\nYou were born " << userBirthDate 
			 << "\nThat makes you " << yearsOld << " years old. " 
			 << "\nYou have been around for " << daysSinceBirth << " days!" << endl;
		
	}
	catch(const exception& anException)
	{
		cout << anException.what() << endl;
	}

	return 0;
}
