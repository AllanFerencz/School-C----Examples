/** CPRG03-05A.cpp
 *	
 *	Unit 3, Activity 5A Solution for CPRG 3202. In this 
 *	program we examine the difference between auto and 
 *	static variables. 
 *	   
 *	@author		YOUR NAME
 *	@version	2014.01
 *	@since		TODAY'S DATE
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/


#include <iostream>	
using namespace std;

/**	Test function
 *	@param		none.
 *	@return		none.
*/
void Test();  // function prototype


int main()
{
	// DECLARATIONS
	const int NUMBER_OF_CALLS = 5;
	
	// OUTPUT
	cout << "Unit 3, Activity 5" << endl
		 << "==================" << endl;
		 
	// call the Test function in a loop multiple times
	
	for(int loopCount = 1; loopCount <= NUMBER_OF_CALLS; loopCount++)
	{
		// display the current loop number
		cout << "\nLoop #" << loopCount << ": ";
		// call the test function
		Test();
	}
	
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	Test function definition
void Test()
{
	// DECLARATIONS
	static int localVariable = 1;	 // initialize a local variable to 1
	
	// OUTPUT
	// show the variable value of the console
	cout << "Test Variable = " << localVariable << endl;
	
	// PROCESSING
	localVariable++;	 // increment the local variable by 1
}
