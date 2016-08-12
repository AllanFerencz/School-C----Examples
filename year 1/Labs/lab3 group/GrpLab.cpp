/** CPRG03-08A.cpp
 *	
 *	Unit 3, Activity 8A Solution for CPRG 3202. In this activity, we will 
 *	examine the rand and srand functions.
 *	   
 *	@author		Alex Plant, Allan ferenzc, Justin Walker
 *	@since		2014-02-06
*/

#include <iostream>	
#include <math.h>
#include <iomanip>

using namespace std;


double rightTriangle( double sideA, double sideB);

int main()
{
	// DECLARATIONS
	double sideA;
	double sideB;
	
	//processes
	//asks the user to enter the first side of the triangle
	cout << "Please enter the first side of your triangle" << endl << "================================================" << endl;
	//checks that the user has entered a number
	while(!(cin >> sideA))
	{
		cin.clear();
        cin.ignore(3, '\n');
		cout << "Number please" << endl;
	}
	//asks the user to enter the second side of the triangle
	cout << "Please enter the second side of your triangle" << endl << "===============================================" << endl;
	//checks that the user has entered a number
	while(!(cin >> sideB))
	{
		cin.clear();
        cin.ignore(3, '\n');
		cout << "Number please" << endl;
	}
	//outputs the length of the hypotonuse
	cout << setprecision(3) << "The hypotonuse of your triangle is " << rightTriangle(sideA,sideB) << endl;
	
	// done.
	return 0;
} // end of main
//function that calculates the hypotonuse
double rightTriangle( double sideA, double sideB)
{
	double hypotonuse;
	hypotonuse = sqrt((sideA * sideA) + (sideB * sideB)); 
	return hypotonuse;
}
