/** CPRG03-03.cpp
 *	
 *	Unit 3, Activity 2C Solution for CPRG 3202. In this 
 *	program we define a function that takes a parameters by value 
 *	and by reference. 
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
#include <cctype> 	// for toupper()
using namespace std;

/**	ConvertTemperature function
 *	@param		fromTemperature - The temperature converting from
 *	@param		fromScale - The scale converting from
 *	@param		& toTemperature - Reference to the temperature converting to
 *	@param		& toScale - Reference to the scale converting to
 *	@return		true if the fromScale was valid (i.e. the conversion 
 *					was possible), otherwise false.
*/

bool ConvertTemperature(double fromTemperature, char fromScale, double& toTemperature, char& toScale);

int main()
{
	// DECLARATIONS
	const char DEGREE_SYMBOL = (char)248; // ASCII degree symbol
	double inTemperature;			// variable to represent the temperature input
	double outTemperature;			// variable to represent the temperature to output
	char inScale;					// variable to represent the scale input
	char outScale;					// variable to represent the scale to output
	bool validScale;				// variable to represent if the input scale is valid
	
	cout << "Unit 3, Activity 3" << endl
		 << "==================" << endl
		 << fixed << setprecision(1);


	// INPUT
	
	// prompt for the input temperature and scale
	cout << "\nPlease enter the tempertaure to convert from. "
		 << "\n(Value followed by \'C\' or \'F\')\n: ";
	
	// get the input temperature and scale
	cin >> inTemperature >> inScale;
	
	// PROCESSING
	validScale = ConvertTemperature(inTemperature,inScale,outTemperature,outScale);
	
	// OUTPUT
	if(validScale) // Did the conversion work?
	{
		// output the converted temperature message.
		cout << endl << inTemperature << DEGREE_SYMBOL << inScale << " converts to " 
			 << outTemperature << DEGREE_SYMBOL << outScale << "." << endl;
		
	}
	else
	{
		// output an error message
		cout << "\nConversion was not successful. \'" << inScale 
			 << "\' is not a valid scale." << endl;
	}
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	ConvertTemperature function definition
bool ConvertTemperature(double fromTemperature, char fromScale, double& toTemperature, char& toScale)
{
		// function definition
		bool validScale; 
		validScale = true;
		
		if (fromScale == 'f' || fromScale == 'F') 
		{
		toTemperature = ((fromTemperature - 32.0) * (5.0 / 9.0));
		toScale = 'C';	
		}
		
		else if (fromScale == 'c' || fromScale == 'C') 
		{
		fromTemperature = (fromTemperature * 9 / 5 + 32);
		toScale = 'F';
		}
		else
		{		
		validScale = false;
		}
		
		return validScale;		
}
