/** CPRG03-04C-File2.cpp
 *	
 *	Unit 3, Activity 4C Solution for CPRG 3202. In this 
 *	program we examine the extern and static storage classes for 
 *	global variables. 
 *	   
 *	@author		Thom MacDonald
 *	@version	2014.01
 *	@since		2 Jan 2014
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
using namespace std;

// GLOBAL DECLARATIONS
int externalGlobalVariable = 3; // regular global variable
extern int globalVariable;	// extends the scope of the
							// global variable declared 
							// in first file. Not a new
							// storage location.

// FUNCTION DEFINITION

void FunctionFromFile2() // Defined in this file, called in the other.
{
	cout << externalGlobalVariable + globalVariable << ": Function from second file" << endl;
}


