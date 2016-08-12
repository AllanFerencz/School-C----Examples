/** CartesianPointTemplate.h
 *	
 *	In this exercise, we will convert CartesianPoint to a class template.
 *   
 *	@author		Allan Ferencz
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Nov 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *  @see		Classes.Cartesian.cpp - Classes and Objects Example Program for CPRG 3202. 
*/

#ifndef _CARTESIAN_TEMPLATE
#define	_CARTESIAN_TEMPLATE

#include <iostream>
#include <sstream>		
#include <cmath>		

using namespace std;

// Class declaration
template <class T>
class CartesianPoint
{
  public:
  	// Constructor: Used to initialize objects
    CartesianPoint(T x = 1, T y = 1) : myX(x), myY(y) {}
	 
	// Accessors: Used to query the state of the object
	T getX() const {return myX;}
	T getY() const {return myY;}
	
	// get the distance between this point and a second point
	double operator-(CartesianPoint pointTo) const;  
 		   								
	operator string() const; // convert the obj to a string.
	
	// Mutators: Used to change the state of the object
	void setX(T x) { myX = x; }
	void setY(T y) { myY = y; }
	void setPoint(T x, T y){ setX(x); setY(y); }
	
	// IO Operator friends (Note: defined inline)
	friend ostream& operator<< (ostream& out, const CartesianPoint& point)
	{
		out << (string) point;  // technically this doesn't even need to be a friend
		return out;
	}
	friend istream& operator>> (istream& in, CartesianPoint& point)
	{
		char deliminator;
		in >> deliminator >> point.myX >> deliminator >> point.myY  >> deliminator;
		return in;
	}

  private: // private data members for the dimensions of the point
    T myX; // x-axis (horizontal) value
    T myY;  // y-axis (vertical) value
    
};

// Class defintion section

/** operator string Method for CartesianPoint template
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
template <class T>
CartesianPoint<T>::operator string() const
{
	// declare a stringstream object
	stringstream strOut; 
	// build the string
	strOut << "(" << myX << ", " << myY << ")";
	// return the string
	return strOut.str();
}

/** operator- Method for CartesianPoint class
 *	Determines the distance between this point and a second point.
 *	@param	pointTo: CartesianPoint
 *	@return	the distance as a double
 */
template <class T>
double CartesianPoint<T>::operator-(CartesianPoint pointTo) const 
{
    T xDelta = pointTo.myX - myX; // difference between x values
    T yDelta = pointTo.myY - myY; // difference between y values
    // return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
} 


/*  Overloading the IO Operators without inlining:

	// Start with declaring a forward reference to the template:
	template <class T>
	class CartesianPoint; // forward reference.

	// Define the IO operators as templates next:
	template <class T>
	ostream& operator<< (ostream& out, const CartesianPoint<T>& point)
	{
		out << (string) point;
		return out;
	}
	
	template <class T>
	istream& operator>> (istream& in, CartesianPoint<T>& point)
	{
		char deliminator;
		in >> deliminator >> point.myX >> deliminator >> point.myY  >> deliminator;
		return in;
	}
	
	// Declare the class template next:
	template <class T>
	class CartesianPoint
	{
	  public:
		...		
		
		// IO Operator friends (Note the '<>')
		friend ostream& operator<< <> (ostream& out, const CartesianPoint<T>& point);
		friend istream& operator>> <> (istream& in, CartesianPoint<T>& point);
		...
	};
*/

#endif
