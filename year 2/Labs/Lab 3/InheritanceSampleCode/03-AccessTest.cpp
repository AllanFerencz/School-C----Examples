/** 03-AccessTest.cpp
 *
 *	A simple test of base member access.
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

class MyBaseClass  // A very simple base class
{
  public:
    MyBaseClass() : myPrivateValue(3), myProtectedValue(2), myPublicValue(1) {} // Constructor
    int myPublicValue;
  private: 
    int myPrivateValue;
  protected:
  	int myProtectedValue;
};

/**	Dervived Class Access Specifier
 *				 		  		        Base Class
 *	     Dervived Class 		public		protected	private
 *	    Access Specifier:		members		members		members
 *	   ===================		======		=========	=======
 *	   : public					public		protected	inaccessible
 *	   : private				private		private		inaccessible
 *	   : protected				protected	protected	inaccessible
 */

class MyDerivedClass : public MyBaseClass // try switching between public, private, and protected
{
	public:
		void ShowValues() const;
};

void MyDerivedClass::ShowValues() const
{
	// Access base class members from derived class method:
	cout << "\nIn a MyDerivedClass method: " << endl;
//	cout << "\tmyPrivateValue:    " << myPrivateValue << endl; 
//	cout << "\tmyProtectedValue:  " << myProtectedValue << endl;
//	cout << "\tmyPublicValue:     " << myPublicValue << endl;
	cout << endl;
}

int main()
{
 	MyDerivedClass testObject;
	
	testObject.ShowValues(); // call method
	
	cout << "\nIn main() function: " << endl;
//	cout << "\tmyPrivateValue:    " << testObject.myPrivateValue << endl;
//	cout << "\tmyProtectedValue:  " << testObject.myProtectedValue << endl;
//	cout << "\tmyPublicValue:     " << testObject.myPublicValue << endl;
	
	
	cout << endl << endl;
 	return 0;
}
