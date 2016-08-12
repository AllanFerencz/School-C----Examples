/** 08-MultipleInhertance.cpp
 *
 *	A simple example of a class that inherits from more than one base class.
 *	
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@version	2014.01
 *	@since		2014-10-11
 *  @see		http://www.cplusplus.com/doc/tutorial/inheritance/
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// Product class
class Product
{
	private:
		double myPrice;	// the sales price of the product
	public:		
		Product(double price) : myPrice(price){}  // Constructor
		double GetPrice() const {return myPrice;} // Accessor
		string GetPriceString() const; // Accessor
}; // end of Product class

// Beverage class
class Beverage
{
	private:
		int mySize; // the size of the beverage in ml
	public:		
		Beverage(int size) : mySize(size){}  // Constructor
		int GetSize() const {return mySize;} // Accessor
		string GetSizeString() const; // Accessor
}; // end of Beverage class

/**	CupOfCoffee class
 *	A cup of coffee is both a product and a beverage. Specify 
 *  multiple base classes seperated by commas.
 */
class CupOfCoffee : public Beverage, public Product
{
	private:
		string myRoast;
		string myBeanType;
	public:
		CupOfCoffee(string roast, string beanType, double price, int size) :
			myRoast(roast), myBeanType(beanType), Product(price), Beverage(size) {}
		operator string();
};

int main()
{
	// Create two cups of coffee
	CupOfCoffee morningJoe("Dark", "Arabica", 1.75, 563);
	CupOfCoffee donutShop("Medium", "Columbian", 1.60, 425);
	
	// Display them on the screen
	cout << (string) morningJoe << endl
		 << (string) donutShop << endl;
	 
	// end of program
	cout << endl << endl;
	return 0;
}

// Beverage::GetSizeString definition
string Beverage::GetSizeString() const
{
	stringstream sizeString;
	sizeString << mySize << "ml"; 
    return sizeString.str();
}

// Product::GetSPriceString definition
string Product::GetPriceString() const
{
	stringstream priceString;
	priceString << fixed << setprecision(2) << "S" << myPrice; 
    return priceString.str();
}

// CupOfCoffee::operator string definition
CupOfCoffee::operator string()
{
	stringstream coffeeString;
	coffeeString << myRoast << " Roast " << myBeanType << " " 
				 << GetSizeString() << " - " << GetPriceString();
    return coffeeString.str();
}

