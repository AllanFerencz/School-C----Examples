/*  Name: Allan
	Program Name: Unit4InClassProject1
	Date:2014-02-12
	Description:	
	*/

#include <iostream> // for cin and cout
#include "MyInputValidation.h"
#include <iomanip>
#include <vector> // needed for vectors

using namespace std;


void temperatureReport(const vector<double> &temperatures, int Days);

double toFahrenheit(double celsius);


int main()
{
double returnValue;

const double MIN_INPUT = -90.0;		// minimum value
const double MAX_INPUT = 60.0;		// maximum value

double input;
int numberOfDays;


cout << "Please enter an amount of days to convert\n";
numberOfDays = myValidation::GetValidDouble(1,365);



vector<double> ptrCelsiusTempatures;


//if(ptrCelsiusTempatures)// wont work not sure how to fix
//{
	



	cout << "Please enter the tempature for "<< (numberOfDays )<< " Days\n\n";

	for (int count = 0; count <= (numberOfDays-1); count++)
	{
	cout << "Please enter the Tempature for day: " << count + 1 << "\n";
	
	input = myValidation::GetValidDouble(MIN_INPUT,MAX_INPUT);
	
	ptrCelsiusTempatures.push_back(input);


	}
	
	

	system("cls");
	cout << "\n  THIS WEEK'S TEMPATURE REPORT\n";
	cout << "====================================\n";
	temperatureReport(ptrCelsiusTempatures, numberOfDays);
	
}
//	else
//	{
//	cerr << "\nRUNTIME ERROR: The program failed to allocate " << numberOfDays;
//	returnValue = -1;
//	}
//
//	delete [] ptrCelsiusTempatures;
//	return returnValue;


void temperatureReport(const vector<double> &temperatures, int Days)
{
	int index =0;
	//double *ptrStart = temperatures;
	while (index < temperatures.size())
	{
		 
	cout << "Day " << setw(10) << index + 1 <<" " << setw(10) << temperatures.at(index) << (char)248<<"C" << setw(10) << toFahrenheit(temperatures.at(index)) << (char)248<<"F" << "\n";
	
	index++;

	//For Testing	cout <<startPosition + numberOfDays << "         " << ptrCelsiusTempatures << "   ";
	}
	
}


double toFahrenheit(double celsius)
{
	return (celsius * 9/5 + 32);
}
