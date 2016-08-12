/** StringStream.cpp
 *	
 *	Using stringstream Example for C++ Programming. In this program 
 *  we will build a string using a stringstream, then read from it 
 *  using similar techniques as reading/writting a file.
 *	   
 *	@author		Thom MacDonald
 *	@version	2014.01
 *	@since		24 Feb 2014
 *	@see 		Bronson, G. (2012).  Chapter 9 I/O Streams and Data Files. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
 *  @see		http://www.cplusplus.com/reference/sstream/stringstream/
*/

#include <iostream>
#include <sstream> // for stringstream
#include <iomanip> // for output formatting
using namespace std;

int main()
{
	// DECLARATIONS
	stringstream strStream;		// an stream object to operate on strings
	string description;			// holds the item description read from the stringstream
	double price;				// holds the item price read from the stringstream
	double averagePrice = 0.0; 	// holds the average price;
	int count = 0;				// counts the items.
  	
	cout << "Using stringstream" << endl
		 << "==================" << endl;	 
	
	// Building a string with stringstream
	cout << "First, let's write to the stringstream: " << endl;
	
	// set the output formats
	strStream << fixed << setprecision(2);
	// send data to the stringstream
	strStream << "Mats       " << 39.95 << endl
	          << "Bulbs      " << 3.22 << endl
	          << "Fuses      " << 1.08 << endl
		      << "Chickens   " << 6.00 << endl;
		      
    // output the resulting string
    // note the .str() method
	cout << "The string contains: " << endl << strStream.str() << endl; 
    
    // Reading from a stringstream
    cout << "Next, let's read from the stringstream: " << endl;
    
	// loop using the same technique we would use to read
	// an input file.
	while(strStream >> description >> price)
	{
 	     // output description
		 cout << "Including " << description << "..." << endl;
		 // sum the price and increase the count for the average calculation
		 averagePrice += price;
		 count++;
	}
	// caluclate the average price
	averagePrice /= count;
	
	// final average output
	cout << "The average price is $" << fixed << setprecision(2)
		 << averagePrice << endl;
    
	cout << endl << endl;
	return 0;
} // end of main

