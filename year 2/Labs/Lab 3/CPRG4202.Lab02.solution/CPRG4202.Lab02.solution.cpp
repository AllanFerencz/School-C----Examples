/** CPRG4202.Lab02.Solution.cpp
 *	
 *	In this lab you and your lab partner created a new class called WorkTicket. 
 *	Objects of this class could be used in an IT support tracking application to 
 *	store information about client requests for support.
 *   
 *	@author		Thom MacDonald
 *	@version	2014.01
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		CPRG4202.Lab02.Classes.pdf
*/

#include <iostream>		// for cin, cout
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for invalid_argument
#include <sstream>		// for stringstream
#include <cstdlib>		// for system()
#include "MyInputValidation14.h"

using namespace std;
using namespace myValidation14;

class WorkTicket
{
public:

	/***************************************************************************
	*	Default and parameterized constructor(s).  
	*	If parameters are not specified, set the work ticket number to zero, 
	*	the work ticket date to 1/1/2000, and all other attributes to empty 
	*	strings.
	***************************************************************************/

     WorkTicket() : myTicketNumber(0), myClientId(""), myDay (1), myMonth (1), myYear(2014), myDescription ("") { } 
     WorkTicket(int ticketNumber, string clientId, int month, int day, int year, string description);
     
    /***************************************************************************
	*	SetWorkTicket() 
	*	a mutator method to set all the attributes of the object to the 
	*	parameters as long as the parameters are valid. ALL of the parameters 
	*	must be valid in order for ANY of the attributes to change. Validation 
	*	rules are explained for work ticket number and date. Client number 
	*	and Description must be at least one character long. If no problems are 
	*	detected, return TRUE.  Otherwise return FALSE. 
	***************************************************************************/

	 bool SetWorkTicket(int ticketNumber, string clientId, int month, int day, int year, string description);
     
    /***************************************************************************
	*	ShowWorkTicket( )
	*	An accessor method to display all the object's attributes neatly in 
	*	the console window. 
	***************************************************************************/    
      	
	 void ShowWorkTicket() const; // accessor       
	 
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
     
     // Date - Day
	 void SetDay(int day);
     int GetDay() const { return myDay; } 

	 // Date - Month
     void SetMonth(int month);
     int GetMonth() const { return myMonth; } 

	 // Date - Year
     void SetYear(int year);
     int GetYear() const { return myYear; }

	 // Decsription
     void SetDescription(string description) { myDescription = description; }   
     string GetDescription() const { return myDescription; }
 
private:

	/***************************************************************************
	*	Attributes.  An object of class WorkTicket has the following attributes. 
	***************************************************************************/
	
     int myTicketNumber;	// Work Ticket Number - A whole, positive number.
     string myClientId;		// Client ID - The alpha-numeric code assigned to the client.
     
	 // Work Ticket Date - The date the ticket was opened, stored as three integer numbers. 
	 int myDay; 	// day opened
     int myMonth;	// month opened
     int myYear;	// year opened
     
	 string myDescription; // Issue Description - A description of the issue the client is having.
};  // end of WorkTicket class


int main()
{
	/***************************************************************************
     *	Program Requirements:
	 *	The purpose of the main() function in this program is to demonstrate 
	 *	each of the features of the WorkTicket class.  
	 *	
	 *	Create an array of at least three WorkTicket objects.
	 *	Use an input loop to allow the user to enter the work ticket information.  
	 *	The input loop should call the SetWorkTicket( ) method. 
	 *	Then use an output loop to display each of the work tickets in the array.
	***************************************************************************/

	 // DECLARATIONS
	 const int NUMBER_OF_TICKETS = 3;
	 WorkTicket tickets[NUMBER_OF_TICKETS]; //	an array of at least three WorkTicket objects.
	 
	 int ticketNumber;	 // temporary input variable
	 string clientId;	 // temporary input variable
	 int day;			 // temporary input variable
	 int month;			 // temporary input variable
	 int year;			 // temporary input variable
	 string description; // temporary input variable
	 
	 // INPUT
	 for(int index = 0; index < NUMBER_OF_TICKETS; index++)
	 {
	 	 // prompt for user input for each attribute and
	 	 // store in the corresponding temp variable
		  cout << "\nWorkTicket [" << index << "]: " << endl;
		  ticketNumber = GetValidInt("Enter ticket number: ");
		  
		  fflush(stdin); 
		  cout << "Enter client ID: ";
		  getline(cin, clientId);
	 	  
		  day = GetValidInt("Enter day number: ");
	 	  month = GetValidInt("Enter month number: ");
	 	  year = GetValidInt("Enter year number: ");
	 	  
		  fflush(stdin);
		  cout << "Enter issue decription: ";
	 	  getline(cin, description);
	 	  
	 	 //	The input loop should call the SetWorkTicket( ) method.  
	 	 // if setting the work ticket to the temp variables works: 
	 	 if(tickets[index].SetWorkTicket(ticketNumber, clientId, month, day, year, description))
	 	 {
	 	 	cout << "\nSuccess! WorkTicket[" << index << "] is set." << endl;
	 	 }
	 	 else
	 	 {
	 	 	cout << "\nInput Error! WorkTicket[" << index << "] will remain unchanged." << endl;
	 	 }
	 }
	 
	 // Use an output loop to display each of the work tickets in the array.
	 cout << "\n\nWorkTicket Array Contents" << endl
	 	  << "=========================" << endl;
	 for(int index = 0; index < NUMBER_OF_TICKETS; index++)
	 {
	 	tickets[index].ShowWorkTicket();
	 }
	 
    
     cout << endl << endl;

     return 0;
}
// WorkTicket::Parameterized Constructor definition
WorkTicket::WorkTicket(int ticketNumber, string clientId, int month, int day, int year, string description)
{
	 // Set each data member with appropriate validation:
	 SetTicketNumber(ticketNumber);
	 SetClientId(clientId);
	 SetMonth(month);
	 SetDay(day);
	 SetYear(year);
	 SetDescription(description);
}


// WorkTicket::SetTicket definition
bool WorkTicket::SetWorkTicket(int ticketNumber, string clientId, int month, int day, int year, string description)
{
     const int MAX_DAY = 31;
     const int MAX_MONTH = 12;
     const int MIN_YEAR = 2000;
     const int MAX_YEAR = 2099;
     bool valid = true; // flag for if parameters are valid
     
     // check numeric parameters
     if(ticketNumber < 0 || month < 1 || month > MAX_MONTH || 
        day < 1 || day > MAX_DAY || 
        year < MIN_YEAR || year > MAX_YEAR)
          valid = false;
     // check string parameters     
     else if (clientId.length() < 1 || description.length() < 1)
          valid = false;
     else // all parameters are valid
     {    
         // set atributes to parameter values
         myTicketNumber = ticketNumber;
         myClientId = clientId;
         myDay = day;
         myMonth = month;
         myYear = year;
         myDescription = description;
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
          << "\nDate:          " << setw(2) << setfill('0') << myMonth
          << "/" << setw(2) << setfill('0') << myDay
          << "/" << myYear
          << "\nIssue:         " << myDescription << endl;
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
	{
		throw invalid_argument("Argument value out of range.");
	}
}

// WorkTicket::SetDay definition
void WorkTicket::SetDay(int day)
{
	const int MIN_VALID = 1;
	const int MAX_VALID = 31;
	if(day >= MIN_VALID && day <= MAX_VALID)
	{
		myDay = day;
	}
	else
	{
		throw invalid_argument("Argument value out of range.");
	}
}

// WorkTicket::SetMonth definition
void WorkTicket::SetMonth(int month)
{
	const int MIN_VALID = 1;
	const int MAX_VALID = 12;
	if(month >= MIN_VALID && month <= MAX_VALID)
	{
		myMonth = month;
	}
	else
	{
		throw invalid_argument("Argument value out of range.");
	}
}

// WorkTicket::SetYear definition
void WorkTicket::SetYear(int year)
{
	const int MIN_VALID = 2000;
	const int MAX_VALID = 2099;
	if(year >= MIN_VALID && year <= MAX_VALID)
	{
		myYear = year;
	}
	else
	{
		throw invalid_argument("Argument value out of range.");
	}
}
