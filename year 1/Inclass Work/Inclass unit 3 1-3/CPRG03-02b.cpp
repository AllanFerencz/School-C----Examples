/** CPRG03-02a.cpp
 *	
 *	Unit 3, Activity 2A Solution for CPRG 3202. In this 
 *	program we define a function that takes a parameter by value 
 *	and returns a value. 
 *	   
 *	@author		YOUR NAME
 *	@version	2014.01
 *	@since		TODAY'S DATE
 *	@see 		Bronson, G. (2012).  Chapter 6 Modularity Using Functions. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**	ConvertFahrenheitToCelsius function
 *	@param		fahrenheit - The temperature converting from in °F
 *	@return		The converted temperature in °C
*/

inline double ConvertFahrenheitToCelsius(double Fahrenheit){return((Fahrenheit - 32.0) * (5.0 / 9.0));}

int main()
{
	// DECLARATIONS
	const double FAHRENHEIT = 100.0; 		// named constant to represent the °F 
	const char DEGREE_SYMBOL = (char)248; // ASCII degree symbol
	double celsius;			  		// variable to represent the °C temperature	
	
	// PROCESSING 
	
	// function call
	 celsius = ConvertFahrenheitToCelsius(FAHRENHEIT);
	// OUTPUT
	cout << "Unit 3, Activity 2A" << endl
		 << "===================" << endl
		 << fixed << setprecision(1);
		 
	cout << FAHRENHEIT << DEGREE_SYMBOL << "F converts to " 
		<< celsius << DEGREE_SYMBOL << "C." << endl;
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main

//	ConvertFahrenheitToCelsius function definition
