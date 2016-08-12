/*  Name: Allan
	Program Name: Unit4InClassProject1
	Date:2014-02-12
	Description:	
	*/

#include <iostream> // for cin and cout
#include "MyInputValidation.h"
#include <iomanip>
using namespace std;


void temperatureReport(double *temperatures, int Days);

double toFahrenheit(double celsius);


int main()
{
double returnValue;

const double MIN_INPUT = -90.0;		// minimum value
const double MAX_INPUT = 60.0;		// maximum value

int numberOfDays;
double *ptrCelsiusTempatures = NULL;
double *startPosition = NULL;




cout << "Please enter an amount of days of rainfall\n";
numberOfDays = myValidation::GetValidDouble(1,365);



ptrCelsiusTempatures = new double [numberOfDays];


if(ptrCelsiusTempatures)
{
	



	cout << "Please enter the tempature for "<< (numberOfDays )<< " Number of Days\n\n";

	for (int count = 0; count <= (numberOfDays-1); count++)
	{
	cout << "Please enter the Tempature for day" << count  << "\n";
	ptrCelsiusTempatures[count] = myValidation::GetValidDouble(MIN_INPUT,MAX_INPUT);
	}
	

	system("cls");
	cout << "\n  THIS WEEK'S TEMPATURE REPORT\n";
	cout << "====================================\n";
	temperatureReport(ptrCelsiusTempatures, numberOfDays);
	

	
}
	else
	{
	cerr << "\nRUNTIME ERROR: The program failed to allocate " << numberOfDays;
	returnValue = -1;
	}

	delete [] ptrCelsiusTempatures;
	return returnValue;
}

void temperatureReport(double *temperatures, int Days)
{
	double *ptrStart = temperatures;
	int count = 1;
	while (temperatures < ptrStart + Days)
	{
		
	cout << "Day " << setw(10) << count++ <<" " << setw(10) << *temperatures << (char)248<<"C" << setw(10) << toFahrenheit(*temperatures)  << (char)248<<"F" << "\n";
	
	temperatures++;

	//For Testing	cout <<startPosition + numberOfDays << "         " << ptrCelsiusTempatures << "   ";
	}
	
}


double toFahrenheit(double celsius)
{
	return (celsius * 9/5 + 32);
}
