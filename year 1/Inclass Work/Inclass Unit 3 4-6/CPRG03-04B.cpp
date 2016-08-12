/** CPRG03-04B.cpp
 *	
 *	Unit 3, Activity 4B Solution for CPRG 3202. In this 
 *	program we examine the difference between local and 
 *	global variables. 
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


/**	someNumber
 *	an global int variable initialized to 88. 
 */

int someNumber = 88;

int main()
{
	// DECLARATIONS
	int someNumber = 99;	 // a local int variable initialized to 99. 
	
	// OUTPUT
	cout << "Unit 3, Activity 4B" << endl
		 << "===================" << endl;
		 
	// show the variable value
	cout << "someNumber == " << someNumber << endl;
	
	// show the global variable value explicitly using the scope resolution operator
	cout << "someNumber == " << ::someNumber << endl;
		

	// done.
	cout << endl << endl;
	return 0;
} // end of main

