/** 02-Inheritance.cpp
 *
 *	Another simple example of basic inheritance with adhoc polymorphism
 *	(i.e. method overloading)
 *
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@version	2014.01
 *	@since		2014-10-11
 *	@see		Bronson, G. (2011). Chapter 12 Extending Your Classes. 
 *					In A First Book of C++, Fourth Edition. Course Technology.
 *	@see		Program Listing 12-1 (pgm12-1.cpp)
 *  @see		http://www.cplusplus.com/doc/tutorial/inheritance/
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


/**	Base Class Member Access Specifier
 *				 		  		 	     Base Class
 *	   		Access from: 			public	protected	private
 *	   	  		 					members	members		members
 *	   =========================	======	=========	=======
 *	   The same class or friend:	yes		yes			yes
 *	   A derived class method:		yes		yes			no
 *	   Anywhere else:				yes		no			no
 */
class Circle  // A very simple base class
{
	public:
		Circle(double radius = 1.0) : myRadius(radius) {} // Constructor
		double Area() const { return(PI * myRadius * myRadius);} // Accessor
	
	protected: // Note: protected vs. private
		double myRadius;  
		static const double PI;
};
// Circle::PI definition
const double Circle::PI = 2.0 * asin(1.0);

class Cylinder : public Circle // Cylinder is derived from Circle
{
	public:           
		// add a constructor
		Cylinder(double radius = 1.0, double length = 1.0) : Circle(radius), myLength(length) {}
		// override Circle::Area 
		double Area() const; 
	protected:
		// add one data member
		double myLength;  
};

// class implementation section for Cylinder
double Cylinder::Area() const  // calculates surface area
{
	double area; // holds the surface area of the cylinder
	
	// Get the area of the top and bottom of the cylinder
	area = Circle::Area() * 2; // note the base function call
	// Add the area of the side: length x circumference (PI * diameter)
	area += myLength * PI * myRadius * 2;
	return area;
}

// Global, non-member function with a Circle parameter
inline void ShowArea(Circle shape){cout << "\nIn ShowArea(), area is " << shape.Area() << endl;}

int main()
{
	// DECLARATIONS
	
	// create two Circle objects
	Circle circle1;
	Circle circle2(2.0);  
	// create one Cylinder object
	Cylinder cylinder1(2.0, 4.0);   
	
	// Output as initialized:
	cout << fixed << setprecision(2)
	   << "  SHAPE     AREA" << endl
	   << "========= ========" << endl
	   << "circle1    " << setw(6) << circle1.Area() << endl
	   << "circle2    " << setw(6) << circle2.Area() << endl
	   << "cylinder1  " << setw(6) << cylinder1.Area() << endl; //adoc polymorphism
	
	// assign a Cylinder to a Circle and output Area()
	cout << "\nAssigning cylinder1 to circle1..." << endl;
	circle1 = cylinder1;  
	cout << "The area of circle1 is now: " << circle1.Area() << endl;
	
	// Pass a Cylinder object to a Circle parameter 
	cout << "\nPassing cylinder1 to ShowArea() by value...";
	ShowArea(cylinder1); 
	
	// End program
	cout << endl << endl;
	return 0;
}
