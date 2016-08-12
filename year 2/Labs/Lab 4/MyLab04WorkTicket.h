/** MyLab04Workticket.h
 *	
 *	A solution to Lab 2/3 using the MyDate class. Use this header for Lab 4.
 *   
 *	@author		Thom MacDonald + Julien Ouimet and Allan Ferencz
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		CPRG4202.Lab02.Classes.pdf
 *	@see		CPRG4202.Lab03.AddingFunctionality.pdf
 *	@see		CPRG4202.Lab04.Inheritance.pdf
 *	@see		MyDateV3.h
*/

#ifndef _WORKTICKET
#define _WORKTICKET

#include <iostream>		// for cin, cout
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for invalid_argument
#include <sstream>		// for stringstream
#include "MyDateV3.h" 	// version 2014.03

using namespace std;

class WorkTicket
{
   public:

	/***************************************************************************
	*	Default and parameterized constructor(s).  
	*	If parameters are not specified, set the work ticket number to zero, 
	*	the work ticket date to 1/1/2000, and all other attributes to empty 
	*	strings.
	***************************************************************************/

     WorkTicket() : myTicketNumber(0), myClientId(""), myDate(1, 1, 2014), myDescription ("") { } 
     WorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description);
     
	/***************************************************************************
	*	 Copy constructor 
	*	 Initializes a new WorkTicket object based on an existing WorkTicket 
	*	 object. 
	***************************************************************************/
     WorkTicket(const WorkTicket& original);
     
    /***************************************************************************
	*	SetWorkTicket() 
	*	a mutator method to set all the attributes of the object to the 
	*	parameters as long as the parameters are valid. ALL of the parameters 
	*	must be valid in order for ANY of the attributes to change. Validation 
	*	rules are explained for work ticket number and date. Client number 
	*	and Description must be at least one character long. If no problems are 
	*	detected, return TRUE.  Otherwise return FALSE. 
	***************************************************************************/

	 bool SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description);
     
    /***************************************************************************
	*	ShowWorkTicket( )
	*	An accessor method to display all the object's attributes neatly in 
	*	the console window. 
	***************************************************************************/    
      	
	 virtual void ShowWorkTicket() const; // accessor       
	 
	/***************************************************************************
	*	Attribute Sets/Gets.  
	*	Include a set (mutator) and get (accessor) method for each attribute. 
	***************************************************************************/
     
	 // Ticket Number     
     void SetTicketNumber(int ticketNumber); 
     int GetTicketNumber() const {return myTicketNumber;}
     
     // Client ID
	 void SetClientId(string clientId) {myClientId = clientId;}
     string GetClientId() const { return myClientId;}
     
	 // Decsription
     void SetDescription(string description) { myDescription = description; }   
     string GetDescription() const { return myDescription; }
     
     // Date
     void SetDate(int day, int month, int year);
 	 const MyDate& GetDate() const { return myDate; }

	/***************************************************************************
	*	Operators (LAB 3).  
	*	Include a set (mutator) and get (accessor) method for each attribute. 
	***************************************************************************/
 	 WorkTicket& operator=(const WorkTicket& original); // Assignment
	 operator string () const;	// (string)
	 bool operator==(const WorkTicket& original); // Equality
	 friend ostream& operator<<(ostream& out, const WorkTicket& ticket); // Output
	 friend istream& operator>>(istream& in, WorkTicket& ticket); // Input
 	
   protected:

	/***************************************************************************
	*	Private Attributes.  An object of class WorkTicket has the following 
	*		private attributes. 
	***************************************************************************/
	
     int myTicketNumber;	// Work Ticket Number - A whole, positive number.
     string myClientId;		// Client ID - The alpha-numeric code assigned to the client.
	 MyDate myDate; 		// Work Ticket Date - the date the workticket was created     
	 string myDescription;  // Issue Description - A description of the issue the client is having.
};  // end of WorkTicket class



//**************************************************************************************************************************************************************************************
//NEW CLASS DERIVED FROM WORKTICKET
//**************************************************************************************************************************************************************************************
class ExtendedWorkTicket : public WorkTicket
{
	public:
		
		//CONSTRUCTOR
		ExtendedWorkTicket(bool ticketStatus = "true", int ticketNumber = 1, string clientId = "", int day = 1, int month = 1, int year = 2014, string description = "") : myTicketStatus(ticketStatus), WorkTicket(ticketNumber, clientId, day, month, year, description) { } 
	
	
		//TICKET STATUS ACCESSOR
		bool IsOpen() const {return myTicketStatus;}
		 
		 			
		//OVERLOAD SETWORKTICKET
	 	bool SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description, bool ticketStatus);
	 	 	
	 	
	 	//OVERIDE SHOWWORKTICKET
	 	virtual void ShowWorkTicket() const; 
	 	
	 
	 	//STATUS DISPLAY
	 	string StatusDisplay() const;
	 	 
	 	 
	 	//MUTATOR
	 	void CloseTicket() {myTicketStatus = false;}
	 	
	 	
	 	//OVERLOAD <<
	 	friend ostream& operator<<(ostream&, const ExtendedWorkTicket&);	//out operator prototype
		 	
	private:
		
		bool myTicketStatus;		//if ticket is open or closed	
};

/***************************************************************************
*	 LAB 2 Method Definitions
*	 - Parameterized Constructor
*	 - SetWorkTicket()
*	 - ShowWorkTicket()
*	 - SetTicketNumber()
*	 - SetDate() 
***************************************************************************/

// WorkTicket::Parameterized Constructor definition
WorkTicket::WorkTicket(int ticketNumber, string clientId, int month, int day, int year, string description)
{
	 // Set each data member with appropriate validation:
	 SetTicketNumber(ticketNumber);
	 SetClientId(clientId);
	 SetDescription(description);
	 SetDate(day, month, year);
}

// WorkTicket::SetTicket definition
bool WorkTicket::SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description)
{
	 MyDate workingDate;
     const int MIN_YEAR = 2000;
     const int MAX_YEAR = 2099;
     bool valid = true; // flag for if parameters are valid
     
     // check numeric parameters
     if(ticketNumber < 0 || year < MIN_YEAR || year > MAX_YEAR)
          valid = false;
     // check string parameters     
     else if (clientId.length() < 1 || description.length() < 1)
          valid = false;         
     else
	 {
		 try
		 {
			 // sets the date (may throw an exception even if rules are met)
			 workingDate.setDate(day, month, year);     
         }
         catch(...)
         {
         	 valid = false;
         }
	 }     
              
     if(valid) // all parameters are valid
     {    
		 // set the workticket date         
		 myDate = workingDate;
		 
		 // set atributes to parameter values
         myTicketNumber = ticketNumber;
         myClientId = clientId;
         myDescription = description;
     }
     // return true or false based on parameter validity
     return valid;
}

//**************************************************************************************************************************************************************************************
// ExtendedWorkTicket::SetWorkTicket definition
//**************************************************************************************************************************************************************************************
bool ExtendedWorkTicket::SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description, bool ticketStatus)
{	
	bool valid = false;
	
	//if SetWorkTicket is valid...
	if(WorkTicket::SetWorkTicket(ticketNumber, clientId, day, month, year, description))
	{
		//assign ticketStatus
		myTicketStatus = ticketStatus;
		valid = true;
	} 	
	// return true or false based on parameter validity
	return valid;
}


// WorkTicket::ShowTicket definition
void WorkTicket::ShowWorkTicket() const
{
     // display the attributes of the object neatly to the console
     cout << "\nWork Ticket #: " << myTicketNumber
          << "\nClient ID:     " << myClientId
          << "\nDate:          " << myDate
          << "\nIssue:         " << myDescription << endl;
}


//**************************************************************************************************************************************************************************************
// ExtendedWorkTicket::ShowWorkTicket definition
//**************************************************************************************************************************************************************************************
void ExtendedWorkTicket::ShowWorkTicket() const
{
	//calls base class ShowWorkTicket
  	WorkTicket::ShowWorkTicket(); 
  	//add new line when outputing ExtendedWorkTicket object
	cout << "Ticket:        " << StatusDisplay() << endl;
}

//STATUS DISPLAY
string ExtendedWorkTicket::StatusDisplay() const
{
	string status = "CLOSED";
	
	if (myTicketStatus == true)
	{
		status = "OPEN";
	}
	
	return status;
}


// WorkTicket::SetTicketNumber definition
void WorkTicket::SetTicketNumber(int ticketNumber)
{
	// If a work ticket number is set to a zero or a negative number, 
	// an invalid_argument exception should be thrown, with an 
	// appropriate message.
	if(ticketNumber > 0)
	{
		myTicketNumber = ticketNumber;
	}
	else
	{
		throw invalid_argument("Ticket number must be greater than zero. ");
	}
}

// WorkTicket::ShowTicket definition
void WorkTicket::SetDate(int day, int month, int year)
{
	//  An invalid_argument exception should be thrown, with an 
	//  appropriate message if the day, month, or year is set out of range.
	
	const int MIN_YEAR = 2000;
    const int MAX_YEAR = 2099;
	if(year >= MIN_YEAR && year <= MAX_YEAR) // unique year requirements 
	{
		myDate.setDate(day, month, year); // day and month validated in the method
	}
	else
	{
		stringstream errorString;
		errorString << "Year must be between " << MIN_YEAR << " and " << MAX_YEAR << ". ";
		throw invalid_argument(errorString.str());
	}	
}

/***************************************************************************
*	 LAB 3 Method Definitions
*	 - Copy Constructor
*	 - operator string()
*	 - operator==()
*	 - operator=()
*	 - operator>>() 
*	 - operator<<() 
***************************************************************************/

// WorkTicket::Copy Constructor definition (Lab 3)
WorkTicket::WorkTicket(const WorkTicket& original)
{
     /*  A copy constructor that initializes a new WorkTicket object based 
         on an existing WorkTicket object. For testing purposes, include the 
         statement:
         cout << "\nA WorkTicket object was COPIED.\n";
     */
     myTicketNumber = original.myTicketNumber;
     myClientId = original.myClientId;
     myDate = original.myDate;
     myDescription = original.myDescription;
     
     //cout << "\nA WorkTicket object was COPIED.\n";
} 

// WorkTicket::Assignment operator (=) definition (Lab 3)
WorkTicket& WorkTicket::operator=(const WorkTicket& original)
{
     /*  Overload the assignment (=) operator to assign all of the attributes 
         of one WorkTicket object to another (member-wise assignment).  For 
         testing purposes, include the statement:
         cout << "\nA WorkTicket object was ASSIGNED.\n";
     */

     myTicketNumber = original.myTicketNumber;
     myClientId = original.myClientId;
     myDate = original.myDate;
     myDescription = original.myDescription;
     
     //cout << "\nA WorkTicket object was ASSIGNED.\n";
     return *this;     
} 

// WorkTicket:: string typecast operator (Lab 3)
WorkTicket::operator string () const
{
     /*  A conversion operator that converts a WorkTicket object to a string 
         in the following format: Work Ticket # Number - Client ID (Date): Description; e.g.:
         "Work Ticket # 2 - ABC123 (10/3/2012): User cannot locate \'any\' key"
     */
     
     stringstream strStream;
     strStream << "Work Ticket # " << myTicketNumber 
	 		   << " - " << myClientId 
			   << " (" << myDate << "): " 
			   <<  myDescription;
     return strStream.str();

} 

// WorkTicket equality operator (Lab 3)
bool WorkTicket::operator==(const WorkTicket& original)
{
     /* Overload the equality ('==') operator  to compare a WorkTicket object 
        to another WorkTicket object using a member-wise comparison. Return 
        true if all the attributes of both objects are the same; false if they 
        are not all the same. 
     */
     
     return myTicketNumber == original.myTicketNumber &&
         myClientId == original.myClientId &&
         myDate == original.myDate &&
         myDescription == original.myDescription;
} // end of WorkTicket equality operator

// Overloaded input operator
ostream& operator<<(ostream& out, const WorkTicket& ticket)
{
     /* Overload the '<<' operator relative to the class to displays all the 
        object's attributes neatly on the console or to any ostream. This will 
        duplicate the functionality of the ShowWorkTicket() method however keep 
        the original method intact for legacy reasons. */
     
     out << "\n\nWork Ticket #: " << ticket.myTicketNumber
         << "\nClient ID:     " << ticket.myClientId
         << "\nDate:          " << ticket.myDate
         << "\nIssue:         " << ticket.myDescription << endl;
     return out;       
} // end of overloaded input operator'


//**************************************************************************************************************************************************************************************
// Overloaded input operator for new class
//**************************************************************************************************************************************************************************************
ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
	out << (WorkTicket)ticket;
    out << "Ticket:        " << ticket.StatusDisplay();
       
     return out;       
}

// Overloaded output operator
istream& operator>>(istream& in, WorkTicket& ticket)
{
     /* Overload the '>>' operator relative to the class to allow the user 
        to enter all of the attributes of a WorkTicket object from the console 
        or any istream. Include validation.
     */
     
	 int ticketNumber;	 // temporary input variable
	 string clientId;	 // temporary input variable
	 MyDate date;		 // temporary input variable
	 string description; // temporary input variable
 	 
	 try
	 {
	 	 // prompt for user input for each attribute and store in the 
		 // corresponding temp variable
		 cout << "\nWorkTicket #: ";
		 in >> ticketNumber;
		 fflush(stdin); 
		 
		 cout << "Client ID: ";
		 getline(in, clientId);
		 
		 cout << "Date (dd/mm/yyyy): ";
		 in >> date;
		 fflush(stdin);
		 
		 cout << "Issue: ";
		 getline(in, description);
		 
		 ticket.SetWorkTicket(ticketNumber, clientId, date.getDay(), date.getMonth(), date.getYear(), description);
	 }
	 catch(const out_of_range& oor)
	 {
	 	 in.setstate(ios::failbit); // set .fail() to true
	 	 throw oor; // re-throw the exception
	 }
	 catch(const invalid_argument& invalid)
	 {
	 	 in.setstate(ios::failbit); // set .fail() to true
	 	 throw invalid; // re-throw the exception
	 }
     
     return in;    
} // end of overloaded output operator 
#endif

