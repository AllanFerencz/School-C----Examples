/** CPRG4202.ICE6.Generics.cpp
 *	
 *	In this exercise, we will convert CartesianPoint to a class template.
 *  
 *	@author		Allan Ferencz
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Nov 2014
 *	@see		CartesianPointTemplate.h
*/

#include <iostream>
#include <iomanip>
#include "CartesianPointTemplate.h"
using namespace std;

// main() function
int main()
{
	// Declarations
	const int QTY = 2; // the quantity of objects in the array
	CartesianPoint<int> pointArray[QTY]; // an array of points 
	double distance; // the distance between two points as a double
	
	// Input loop
	// for each object in the array
	for(int point = 0; point < QTY; point++)
	{
		// get the coordinates from the user
		cout << "\nEnter coordinates of point # " << (point + 1) << ": " << endl;
		cin >> pointArray[point];
	}
	
	// Processing
	// determine the distance between the two points in the array
	distance = pointArray[0] - pointArray[1];

	// Output 
	// Show the points and the distance
	cout << fixed << setprecision(1); // formatting
	cout << "\nThe distance between " << pointArray[0]
		 << " and " << pointArray[1] << " is " 
		 << distance << ". " << endl;
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main()

