/** CPRG03-08A.cpp
 *	
 *	Unit 3, Activity 8A Solution for CPRG 3202. In this activity, we will 
 *	examine the rand and srand functions.
 *	   
 *	@author		YOUR NAME
 *	@version	2014.01
 *	@since		TODAY'S DATE
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>	
#include <cstdlib> // for srand(), rand(), RAND_MAX
#include <ctime> // for time(), ctime(), time_t

using namespace std;

int main()
{
	// DECLARATIONS
	const unsigned int QUANTITY = 10; 	// the quantity of random numbers we wish to produce
	const unsigned int MIN_VALUE = 2;
	const unsigned int MAX_VALUE = 12;
	
	time_t startTime = time(NULL);		// a variable to hold the current time.
	int randomValue;					// a variable to hold a random value
	
	srand(time(NULL)); // 'seed' the random number algorithm
	
	cout << "Unit 3, Activity 8" << endl
		 << "==========================" << endl
		 << ctime(&startTime) << endl; // ctime converts the time_t value to a string
		
	cout << "\nThe maximum pseudo-random that can be generated is " << RAND_MAX << "." << endl;
	cout << "\nGenerating " << QUANTITY << " random numbers:\n" << endl;
	
	for(int loopCount = 0; loopCount < QUANTITY; loopCount++)
	{
		randomValue = ( MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1));
		cout << randomValue << endl;
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main


