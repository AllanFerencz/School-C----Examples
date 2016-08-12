/** 07-MoreInclusion.cpp
 *
 *	Another example of inheritance with inclusion (sub-type) 
 *  polymorphism. Using an abstract class pointer, we can have
 *  one identifier refer to different types of objects at different
 *  times as long as the type is related to the abstract class.
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

/** GrumpyCat (New!)
 *	This class is derived from Domestic Cat rather than Cat directly.
 */
class GrumpyCat : public DomesticCat
{
	public:
		GrumpyCat() : DomesticCat("Tardar Sauce"){}
		string GetVocalization() const override { return "Mrwaah!"; }
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
	try
	{
	     Cat* pCat;  // can point to any object of a class dervived from Cat
	     char choice; // user input
	     
	     // prompt
		 cout << "\nWhich do you prefer? \'T\'igers, \'L\'ions, or \'D\'omestic cats: ";
	     // get user input
		 cin >> choice;
	     
	     // determine what type of object we want to use
	     switch(choice)
	     {
	     	case 'T': case 't':
	     		cout << "\nTiger it is!\n";
	     		pCat = new Tiger("Tony");
	     		break;
	     	case 'L': case 'l':
	     		cout << "\nLion it is!\n"; 
	     		pCat = new Lion("Leo");
	     		break;
	     	case 'D': case 'd':
	     		cout << "\nDomestic cat it is!\n"; 
	     		pCat = new DomesticCat("Squeaky");
	     		break;
     		default:
     			cout << "\nI did not recognize your choice. I will assume you are grumpy.\n";
     			pCat = new GrumpyCat();
	     }
		 
		 // pass to the output function
	     WhatDoesTheCatSay(*pCat);
	     // free memory
		 delete pCat;
	}
	catch(bad_alloc ba)
	{
		cerr << ba.what() << endl; // could not allocate at runtime
	}
	 
	// end of program
	cout << endl << endl;
	return 0;
}
