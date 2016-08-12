/*  Name: Allan
	Program Name: DisBetween2Cordinates
	Date:2014-01-18
	Description: This program is to have the user enter 2 different cordinates and 
				 have it output the distance between them.
*/

#include <iostream> // for cin and cout
#include <cmath> // for sqrt
using namespace std; // std means standard


int main()
{

int xOne; // holds the first x coordinate
int xTwo;// holds the second x coordinate
int yOne;// holds the first y coordinate
int yTwo;// holds the second y coordinate
float result; // holds the distance

	
cout << "Please enter x and y of point one"; // asks user for 2 points
cin >> xOne >> yOne; // gets users numbers for first point

cout << "Please enter x and y of point two"; // asks user for 2 points
cin >> xTwo >> yTwo; // gets user numbers for second point

result =sqrt(((xTwo - xOne) * (xTwo - xOne)) + ((yTwo + yOne) * (yTwo + yOne))); //calculates the distance

cout << "The distance is " << result;
return 0;
}
