/** CPRG03-09.cpp
 *	
 *	Unit 3, Activity 9 Solution for CPRG 3202. In this activity, we will 
 *	validate user input in a 'for' loop.
 *	   	   
 *	@author		Allan
 *	@version	2014.01
 *	@since		Feb
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <cstdio> 	
#include <cstdlib>
#include <iomanip>
using namespace std;	

/**	ClearInputBuffer function
 *	Clears the input buffer and resets the fail state of an istream object. 
 *
 *	@param		in (istream object by ref) - the object to clear & reset; defaults to cin.
 *	@return		none.
*/
void ClearInputBuffer(istream &in = cin); // function prototype

int main()
{
	// DECLARATIONS
	const int LIMIT = 5; // number of inputs to get
	int inputValue;		 // hold the input from the user
	int total = 0;		 // accumulates the total of the input from the user
	double average;		 // holds the average of the input from the user
	
	cout << "Unit 3, Activity 9" << endl
		 << "===================" << endl;
	
	// INPUT
	// A simple 'for' loop with numeric validation.
	cout << "\nPlease enter " << LIMIT << " numbers: " << endl;
	
	for (int counter = 1; counter <= LIMIT; counter++)
	{	 
		cout << "Enter #" << counter << ": "; // prompt 
		cin >> inputValue; // attempt to get the value
	
		// if cin.fail() is TRUE 	
		if(cin.fail())
		{
			ClearInputBuffer();	// reset cin and clear the input buffer.
			cout << "Only numeric values please. Try again: " ; // re-prompt
			counter--;// decrease counter so that it stays on the same number
		}
		// otherwise
		else
		{
			// the value was valid. Add it to the total.
			total += inputValue;
		}
		
	} // end of for loop

	// PROCESSING
	// calculate the average from the total
	average = (double) total / LIMIT;
	
	// OUTPUT
	// display the average to two decimal places
	cout << fixed << setprecision(2) << "\nThe average of the numbers entered is: " 
		 << average << endl; // output the results

	// done.
	cout << endl << endl;
	return 0;
} // end of main


// ClearInputBuffer function definition
void ClearInputBuffer(istream &in) 
{
	
	char characterFromBuffer; // a char variable to hold input from the buffer
	// if the in object has failed...
	if(in.fail())
  	{
		in.clear(); // clear the fail state of the object
		characterFromBuffer = in.get(); // attempt to read a character 
	  	// while the character read is not new-line or not end-of-file
	  	while (characterFromBuffer != '\n' && characterFromBuffer != EOF) 
	  	{
		  	// therefore something was read from the buffer
		  	// attempt to read another character
			characterFromBuffer = in.get();
		} // end of while
	}// end of if	

} // end of ClearInputBuffer
