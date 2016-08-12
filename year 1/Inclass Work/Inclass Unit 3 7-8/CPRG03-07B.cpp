/** CPRG03-07A.cpp
 *	
 *	Unit 3, Activity 7A Solution for CPRG 3202. In this activity, we will 
 *	write two functions to examine function overloading. The first will 
 *	return the absolute value of an int argument. The second will return 
 *	the abs value of a double argument. Both functions will be called 
 *  AbsoluteValue.
 *	   
 *	@author		YOUR NAME
 *	@version	2014.01
 *	@since		TODAY'S DATE
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/
#include <iostream>	
#include <iomanip>	// for output formatting

using namespace std;

/**	AbsoluteValue(int) function
 *	@param		int initialValue - The value to convert
 *	@return		the absolute value of initialValue
*/
template <class T>
T AbsoluteValue(T initialValue);	 // function prototype


int main()
{
	// DECLARATIONS
		
	int wholeNumber = -4;					
	float roughNumber = -4.12F;				
	double realNumber = -4.12345;
	
	cout << "Unit 3, Activity 7B" << endl
		 << "===================" << endl;
		
	// PROCESSING / OUTPUT
	
	
	cout << "Whole Number: " << AbsoluteValue(wholeNumber) << endl;
	cout << "Rough Number: " << AbsoluteValue(roughNumber) << endl;
	cout << " Real Number: " << AbsoluteValue(realNumber) << endl;
	
			
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	AbsoluteValue(T) function definition
template <class T>
T AbsoluteValue(T initialValue)
{
	// Declare and initialize absoluteValue to initialValue
	T absoluteValue = initialValue;
	
	// if absoluteValue is negative
	if(absoluteValue < 0)
		// make it positive
		absoluteValue *= -1;
	// return the absolute value
	return absoluteValue;
}

