/** CPRG03-04A.cpp
 *	
 *	Unit 3, Activity 4A Solution for CPRG 3202. In this 
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

/**	LocalScopeTest function
 *	@param		none.
 *	@return		none.
*/
void LocalScopeTest();


/**	globalNumber
 *	an int variable available to all functions defined after this declaration. 
 */
int globalNumber;

int main()
{
	// DECLARATIONS
		
	int localNumber; // an int variable only available in the block it is declared in.
	
	// PROCESSING
	// set the local variable to 88 and the global variable to 888
	localNumber = 88;
	globalNumber = 888;
		
	// OUTPUT
	cout << "Unit 3, Activity 4A" << endl
		 << "===================" << endl;
		 
	// show the variable values
	cout << "\nIn main():" << endl
		 << "localNumber is: " << localNumber << endl
		 << "globalNumber is: " << globalNumber << endl;
		 		
		// call the function
	LocalScopeTest();
	// show the variable values again	 
		cout << "\nIn main():" << endl
		 << "localNumber is: " << localNumber << endl
		 << "globalNumber is: " << globalNumber << endl;		
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	LocalScopeTest function definition
void LocalScopeTest()
{
	// DECLARATIONS
	int localNumber;	// an int variable only available in the block it is declared in.
	
	// PROCESSING
	// set the local variable to 99 and the global variable to 999
	localNumber = 99;
	globalNumber = 999;
	
	// OUTPUT
	// show the variable values
	cout << "\nIn LocalScopeTest():" << endl
		 << "localNumber is: " << localNumber << endl
		 << "globalNumber is: " << globalNumber << endl;
		 
}
