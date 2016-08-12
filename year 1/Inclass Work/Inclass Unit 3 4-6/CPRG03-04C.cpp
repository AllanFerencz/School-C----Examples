/** CPRG03-04C.cpp
 *	
 *	Unit 3, Activity 4C Solution for CPRG 3202. In this 
 *	program we examine the extern and static storage classes for 
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
#include "CPRG03-04C-File2.cpp"
using namespace std;

// GLOBAL DECLARATIONS
int globalVariable = 1;	// regular global variable
static int staticGlobalVariable = 2; // static global variable
									 // - cannot be extended beyond
									 //   this file.

// FUNCTION PROTOTYPES

void GlobalExample();
void StaticGlobalExample();
void ExternalGlobalExample();

int main()
{
	cout << "Unit 3, Activity 4C" << endl
		 << "===================" << endl;
	
	// FUNCTION CALLS
	GlobalExample();
	StaticGlobalExample();
	ExternalGlobalExample();
	FunctionFromFile2(); // Function defined in second file
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main


// FUNCTION DEFINITIONS
void GlobalExample()
{
	// No problem accessing a global declared in this file
	cout << globalVariable << ": Global" << endl;
}

void StaticGlobalExample()
{
	// No problem accessing a static global declared in this file
	cout << staticGlobalVariable << ": Static Global" << endl;
}


void ExternalGlobalExample()
{
	extern int externalGlobalVariable; // extends the scope of the
									   // global variable declared 
									   // in second file. Not a new
									   // storage location.
									   
	cout << externalGlobalVariable << ": External Global" << endl;
}



