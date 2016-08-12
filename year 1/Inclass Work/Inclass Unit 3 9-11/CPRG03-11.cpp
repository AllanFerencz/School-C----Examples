/** CPRG03-11.cpp
 *	
 *	Unit 3, Activity 11 Solution for CPRG 3202. In this activity, we will 
 *	create a re-useable library for our input validation functions.
 *	   
 *	@author		Thom MacDonald
  *	@author		Allan Ferencz
 *	@version	2014.02
 *	@since		11 Feb 2014
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include "MyInputValidation.h"

using namespace std;

int main()
{
	// DECLARATIONS
    const int MIN_INPUT = 0;		// minimum value
    const int MAX_INPUT = 100;		// maximum value
	int inputValue;		 		    // hold the input from the user
	
	cout << "Unit 3, Activity 11" << endl
		 << "===================" << endl;
	
	// INPUT
	// Prompt for input
	cout << "Please enter a WHOLE number: ";
	
	// Get the input using our function
	inputValue = myValidation::GetValidInteger(MIN_INPUT, MAX_INPUT);
	 
	// OUTPUT
	// Display the value entered
	cout << "\nCongratulations on entering the value " << inputValue << "!";
    
	// done.
	cout << endl << endl;
	return 0;
} // end of main
