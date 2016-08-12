/** CPRG03-01.cpp
 *	
 *	Unit 3, Activity 1 Solution for CPRG 3202. In this 
 *	program we define a function that returns nothing and has 
 *	no parameters. 
 *	   
 *	@author		Allan Ferencz
 *	@version	2014.01
 *	@since		2014-01-28
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
using namespace std;

/** Hellow function
*	This function displays a simple message to the console window
*	@param		none
*	@return		none
*/

void Hello(); // function prototype



int main()
{
	cout << "Unit 3, Activity 1" << endl
		 << "==================" << endl;

	Hello(); // function call
		
	cout << endl << endl;
	return 0;
} // end of main

//	Hello function definition
void Hello() // function header
{	
			// function body
	cout << "\nHello world!" << endl; // output message
}			// end of function










