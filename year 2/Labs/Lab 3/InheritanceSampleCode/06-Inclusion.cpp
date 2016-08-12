/** 06-Inclusion.cpp
 *
 *	An example of inheritance with inclusion (sub-type) 
 *  polymorphism. Includes an abstract class with a 'pure' virtual
 *  method. 
 *	
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@version	2014.01
 *	@since		2014-10-11
 *	@see		Bronson, G. (2011). Chapter 12 Extending Your Classes. 
 *					In A First Book of C++, Fourth Edition. Course Technology.
 *  @see		http://www.cplusplus.com/doc/tutorial/polymorphism/
*/

#include <iostream>
#include <iomanip>
using namespace std;

/** Abstract Class Cat
 *	- Serves ONLY as a base class for cat-related derived classes.
 *	- Cannot instantiate Cat objects because it contains a 'pure'
 *	  virtual function.	
 */
class Cat
{
	private:
		string myName; // A name for the cat
	public:		
		Cat(string name) : myName(name){}  // Constructor
		string GetName() const {return myName;} // Accessor
		
		/** GetVocalization
		 *  The keyword 'virtual' and the initializer '= 0' make 
		 *  this method a 'pure' virtual function. A class derived
		 *  from Cat MUST implement this method. It is NOT 
		 *  implemented in the Cat class. The inclusion of a pure 
		 *  virtual method makes the class abstract.
		 */
		 virtual string GetVocalization() const = 0; // pure virtual accessor
}; // end of Cat class

/** Classes derived from Cat
 *  The following classes are derived from Cat. They each have their
 *  own constructor which can (in this example, does) call the base 
 *  class constructor. They each override the GetVocalization() method
 *  in a unique way.
 */

// DomesticCat
class DomesticCat : public Cat
{
	public:
		DomesticCat(string name = "") : Cat(name){}
		string GetVocalization() const override { return "Meow!"; }
};

// Tiger
class Tiger : public Cat
{
	public:
		Tiger(string name = "") : Cat(name){}
		string GetVocalization() const override { return "GRRRRR!"; }
};

// Lion
class Lion : public Cat
{
	public:
		Lion(string name = "") : Cat(name){}
		string GetVocalization() const override { return "ROAR!"; }
};

/** Using the Cat class as a parameter.
 *	Since class Cat cannot instantiate objects, the parameter 
 *	cannot be 'by value'. It must be 'by reference' (const or not),
 *	or 'by address' using a pointer (Cat *). 
 *
 *	Any object that is derived directly or indirectly from Cat may
 *  be passed to this function (i.e. DomesticCat, Tiger, Lion). 
 */
inline void WhatDoesTheCatSay(const Cat& anyCat) 
{ 
	// Since GetVocalization() is purely virtual, it determines which
	// version of the method to use by the actual type of object that 
	// was passed.
	cout << endl << anyCat.GetName() << " says " << anyCat.GetVocalization() << endl;  
}

int main()
{
	// Declare an object of each of the classes derived from Cat.
	DomesticCat squeaky("Squeaky");
	Tiger tony("Tony");
	Lion leo("Leo");
	
	// Pass each object to the function
	WhatDoesTheCatSay(squeaky);
	WhatDoesTheCatSay(tony);
	WhatDoesTheCatSay(leo);
	 
	// end of program
	cout << endl << endl;
	return 0;
}
