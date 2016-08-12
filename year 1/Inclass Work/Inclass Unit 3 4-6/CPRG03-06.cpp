/** CPRG03-06.cpp
 *	
 *	Unit 3, Activity 6 Solution for CPRG 3202. In this 
 *	program we examine the register storage class and the 
 *	time function. 
 *	   
 *	@author		YOUR NAME
 *	@version	2014.01
 *	@since		TODAY'S DATE
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/


#include <iostream>
#include <ctime> 
using namespace std;

int main()
{
	// DECLARATIONS
	const unsigned int VERY_LARGE_NUMBER = 750000000; // a huge number for testing purposes
	time_t startTime = time(NULL);	// a variable to hold the time in seconds.
									// time_t is CURRENTLY the same as int/long.
									// time(NULL) returns the number of seconds 
									// that have passed since midnight 1 Jan 1970 GMT.
	
	cout << "Unit 3, Activity 6" << endl
		 << "==========================" << endl
		 << ctime(&startTime) << endl; // ctime converts the time_t value to a string
		 
	// record the start time
	time(&startTime); // also the same startTime=time(Null);
	
	// display information
	cout << "\nDemonstrating the speed of an \'automatic\' variable." << endl;
	
	// loop a very large number of times using an auto variable as the counter
	for(unsigned int counter = 0; counter <= VERY_LARGE_NUMBER; counter++)
	{
		// execute arbitrary math operations result in no net change to the auto variable
		counter = counter * 2;
		counter = counter / 2;
		counter = counter * 3;
		counter = counter / 3;
	}
	
	// display the resulting time.
	cout << "Done in approximately " << time(NULL) - startTime << " second(s)." << endl;
	
	// record the new start time
	time(&startTime);
	
	// display information
	cout << "\nDemonstrating the speed of a \'register\' variable." << endl;
	
	// loop a very large number of times using a register variable as the counter
	for(register unsigned int fastCounter = 0; fastCounter <= VERY_LARGE_NUMBER; fastCounter++)
	{
		// execute arbitrary math operations result in no net change to the variable
		fastCounter = fastCounter * 2;
		fastCounter = fastCounter / 2;
		fastCounter = fastCounter * 3;
		fastCounter = fastCounter / 3;
	}
	
	// display the resulting time.
	cout << "Done in approximately " <<  time(NULL) - startTime  << " second(s)." << endl;
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

