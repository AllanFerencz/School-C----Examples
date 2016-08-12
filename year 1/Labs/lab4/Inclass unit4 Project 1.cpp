/*  Name: Allan
	Program Name: Unit4InClassProject1
	Date:2014-02-12
	Description:	
	*/

#include <iostream> // for cin and cout
#include "MyInputValidation.h"
#include <iomanip>



int main()
{
double celsiusTempatures[7];
double fahrenheitTempatures[7];
const double MIN_INPUT = -90.0;		// minimum value
const double MAX_INPUT = 60.0;		// maximum value
const string DAYS [7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saterday"};

double toFahrenheit(double celsius);

cout << "Please enter the tempature for each day of the week.\n\n";

	for (int count = 0; count <= 6; count++)
	{
	cout << "Please enter the Tempature for " << DAYS[count] << "\n";
	celsiusTempatures[count] = myValidation::GetValidDouble(MIN_INPUT,MAX_INPUT);
	}

	for (int count = 0; count <= 6; count++)
	{
	fahrenheitTempatures[count] = toFahrenheit(celsiusTempatures[count]);	
	}

	system("cls");
	cout << "\n  THIS WEEK'S TEMPATURE REPORT\n";
	cout << "====================================\n";
	
	for (int count = 0; count <= 6; count++)
	{
	cout << setw(10) << DAYS [count] << setw(10) << celsiusTempatures[count] << (char)248<<"C" << setw(10) << fahrenheitTempatures[count]<< (char)248<<"F" << "\n";
	}

	
}

double toFahrenheit(double celsius)
{
	return (celsius * 9/5 + 32);
}
