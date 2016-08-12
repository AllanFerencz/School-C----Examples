/** CPRG04A-IP01.Solution.cpp
 *	
 *	Unit 4A, In-Class Project 1 for CPRG 3202. In this in-class project we 
 *	created a console C++ program that had the user enter Celsius temperature 
 *  readings for each day of the week and then display a report showing both 
 *  the Celsius and Fahrenheit temperatures for each day entered. This program
 *  required the use of arrays.
 *	   
 *	@author		Thom MacDonald
 *	@version	2014.01
 *	@since		5 Jan 2014
 *	@see 		Bronson, G. (2012).  Chapter 7 Arrays. 
 *					In A First Book of C++ (4th ed.). 
 *					Boston, MA: Course Technology.
*/

#include <iostream>
//#include <iomanip>
#include "MyInputValidation.h" // from Unit 3, Lesson 4
using namespace std;

/**	ConvertFahrenheitToCelsius function
 *	@param		celsius - The temperature converting from in °C
 *	@return		The converted temperature in °F
*/
inline double ConvertCelsiusToFahrenheit(double celsius) {return celsius * 1.8 + 32.0;}

/**	DayName function
 *	@param		dayNumber - the day number (1-7)
 *	@return		the corresponding name of the day as a string 
 				(e.g. "Sunday", "Monday", etc), or an error message if 
 				invalid.
*/
string DayName(int dayNumber);

/**	TemperatureReport function template
 *	@param		temperatures[] - an array of temperature values
 *	@param		DAYS - an int const representing the number of days in 
 *					   the array; defaults to 7
 *	@return		None.
*/
template <class T>
void TemperatureReport(T temperatures[], const int DAYS = 7);

int main()
{
    const int DAYS = 7;           // the number of days to process
    const double LOWEST = -90.0;  // lowest valid temperature C
    const double HIGHEST = 60.0;  // highest valid temperature C
    
	// an array to hold the temperature data
    double weeklyCelsiusTemperatures[DAYS] = {0.0};
        
     // Prompt and store temperatures
    cout << "\nTEMPERATURE REPORTER" << endl
         << "====================" << endl
         << "Please enter the temperature for each day of the week." << endl;
    
    for(int day = 0; day < DAYS; day++) // input loop
    {
    	cout << "Celsius temperature for " << DayName(day + 1) << ": "; // prompt
        weeklyCelsiusTemperatures[day] = myValidation::GetValidDouble(LOWEST, HIGHEST);
    } // end of input loop
    
    TemperatureReport(weeklyCelsiusTemperatures, DAYS);

    cout << endl << endl;
    return 0; // end of program
} // end of main()

//	DayName function
string DayName(int dayNumber)
{
	const int FIRST_DAY_INDEX = 1;	// index of the first day string in the array
	const int LAST_DAY_INDEX = 7;	// index of the last day string in the array
	
	const string DAY_NAMES[LAST_DAY_INDEX + 1] = // an array of strings constants
	{	
		"Error: Invalid Day", 
		"Sunday", 
		"Monday", 
		"Tuesday", 
		"Wednesday", 
		"Thursday", 
		"Friday", 
		"Saturday"
	};
	
	// if the day number is out of range...
	if(dayNumber < FIRST_DAY_INDEX || dayNumber > LAST_DAY_INDEX)
	{
		dayNumber = 0; // set day number to the index of the error message
	}
	// return the string at index day number
	return DAY_NAMES[dayNumber];
}


//	TemperatureReport function template
template <class T>
void TemperatureReport(T temperatures[], const int DAYS = 7)
{
    const char DEGREES = (char) 248; // the degree symbol

    // Output Report
    cout << fixed << setprecision(2) << endl << endl
         << "   THIS WEEK'S TEMPERATURE REPORT" << endl
         << "   ==============================" << endl << endl;
    
    for(int day = 0; day < DAYS; day++) // output loop
    {
         cout << setw(10) << DayName(day + 1) 
              << setw(10) << ConvertCelsiusToFahrenheit(temperatures[day]) << DEGREES << "F"
              << setw(10) << temperatures[day] << DEGREES << "C" << endl;
    } // end of output loop
}
