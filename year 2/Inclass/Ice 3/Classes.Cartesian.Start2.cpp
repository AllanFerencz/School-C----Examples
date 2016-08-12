/** Classes.Cartesian.cpp
 *	
 *	Classes and Objects Example Program for CPRG 3202. In this example, 
 *  we create a new class called CartesianPoint and demonstrate it's use with an array.
 *   
 *	@author		Thom MacDonald
 *	@version	2014.01
 *	@since		7 Mar 2014
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		<video>
*/

#include <iostream>
#include <iomanip> 		// for output formatting
#include <sstream>		// for stringstream
#include <cmath>		// for sqrt()
#include "MyInputValidation.h" // for GetValidDouble()
using namespace std;

// class declaration section
class CartesianPoint
{
  public:
  	/* Constructor: Used to initialize objects
	 *	- always the same name as the class
	 *	- never have a return type
	 *	- called automatically when an obj is instantiated
	 *	- should set values for each member variable
	 */
	 CartesianPoint(): myX(0), myY(0) {}
	 CartesianPoint(int x, int y)  { myX = x; myY = y;}
	 
    /* Accessors: Used to query the state of the object
	 *	- never modifies the object
	 *	- should specify const at the end of the prototype/header
	 */
	   	
	
	// get x, get y 
	int getX() const {return myX;} 
	int getY() const {return myY;}
	// get the distance between this point and a second point
	double getDistanceTo ( const CartesianPoint pointTo)const; 
	// convert the obj to a string.
	string toString() const;
	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/
	void setX(int x) {myX = x;}
	void setY(int y) {myY = y;}
	void setXY(int x, int y) {myX = x; myY = y;}
	
	// set x, set y

											
  private: // private data members for the dimensions of the point
    int myX; // x-axis (horizontal) value
    int myY;  // y-axis (vertical) value
    
};

// main() function
int main()
{
	
	
	CartesianPoint PointA;	
	CartesianPoint PointB;
	
	double distance;
	
	PointB.setXY(myValidation::GetValidInteger(),0);
	PointA.setX(3);
	PointA.setY(4);
	
	distance = PointA.getDistanceTo(PointB);
	
	cout << "The Distance between : " << PointA.getX() << ", " << PointA.getY() << " and "
		 << PointB.getX() << ", " << PointB.getY() << " is " << distance << endl;
	
	cout << "PointA is " << PointA.toString() << endl;
	
	// Declarations
    // the quantity of objects in the array
	// an array of objects
	// temporary input variable
	// temporary input variable
	// to store the distance between two points
	
	// Input loop
	// for each object in the array
	// get the coordinates from the user

		
		// set this point to the user input

	
	// Processing
	// determine the distance between the two points in the array


	// Output 
	// Show the points and the distance

	// done.
	cout << endl << endl;
	return 0;
} // end of main()

// Class defintion section

/** toString Method for CartesianPoint class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string CartesianPoint::toString() const
{
	// declare a stringstream object
	stringstream strOut;
	
	strOut << "(" <<getX() << "," << getY() << ")";
	
	return strOut.str(); 
}

/** getDistanceTo Method for CartesianPoint class
 *	Determines the distance between this point and a second point.
 *	@param	pointTo: CartesianPoint
 *	@return	the distance as a double
 */
 double CartesianPoint::getDistanceTo (const CartesianPoint pointTo) const
 {
 	int xDifference = pointTo.myX - myX;
 	int yDifference = pointTo.myY - myY;
 	
 	return sqrt(xDifference * xDifference + yDifference * yDifference);
 }
