/** CPRG06-01.cpp
 *	
 *	Guided Activity:
 *	We will complete a simple program that will attempt to open a text file 
 *	for reading (input), and check to see if the attempt was successful.
  *  Add the code for the following:
 * 	- Attempt to open the file named "prices.dat"
 * 	- Check for an unsuccessful open
 * 	- Close the file
 *	   
 *	@author		YOUR NAME
 *	@version	2014.01
 *	@since		TODAY'S DATE
 *	@see 		Bronson, G. (2012).  Chapter 9 I/O Streams and Data Files. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/


#include <iostream>
#include <fstream>	// needed for ifstream class
using namespace std;


int main()
{
	// DECLARATIONS
	ifstream inFile;		// an ifstream object to connect to the file
  	int returnValue = 0; 	// holds the return value for main()
	
	// INPUT
	cout << "Unit 6, Activity 1" << endl
		 << "==================" << endl;

    // **Attempt to open the file named "prices.dat"
    inFile.open("prices.dat");	
	// **Check for an unsuccessful open
	if(inFile.fail())
	{
		// Inform the user of the problem
		cout << "\nThe file was not successfully opened"
			 << "\n Please check that the file currently exists."
			 << endl;
			 
		// Set main() return value to 1
        returnValue = 1; // '1' indicating the program did not 
        			     // execute successfully
	}
	// Otherwise, the file is open.
	else
	{
	 	cout << "\nThe file has been successfully opened for reading."
			 << endl;
		// statements to read data from the file are placed here
		
		
		// **close the file
		inFile.close();
		// easy to forget!
	}
	
	cout << endl << endl;
	return returnValue;
} // end of main
