/** WorkTicketLab3.cpp
 *	
 *	created a WorkTicket class to hold issues 
 *  clients have along with general information that goes along with them.
 *  Program askes the user for a client ID and Client Issue. That repeats 3 times
 *  then displays that to the user.
 *   
 *	@author		Allan Ferencz, Dilpreet Singh
 *	@since		12 Oct 2014
*/

#include <ctime>
#include <iostream>
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for out_of_range
#include <sstream>		// for stringstream
#include <cstdlib>		// for system()
//#include "MyInputValidation.h" // for GetValidDouble()
using namespace std;
	
//*****************************************************************************************
// 			CLASS WorkingTicket
//*****************************************************************************************

class WorkingTicket // Class declaration section
{
	public:
		
		//*****************************************
		// 			constructors
		//*****************************************
		
		// Default constructor
		//Ticket number is 0
		//Client ID is ""
		//Date Created is 1/1/2000
		//Client Issue is ""	
		WorkingTicket(): workTicketNumber(0), clientID(), dayCreated(1), 
						  monthCreated(1), yearCreated(2000), clietIssue() {}	
		// Parameterized constructor
		WorkingTicket (int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
						int tempMonthCreated, int tempYearCreated, string tempClietIssue);					
		//Copy Constructor
		WorkingTicket(const WorkingTicket&);
		
		//*****************************************
		// 			Accessors
		//*****************************************
		
		string showWorkTicket() const; //Displays the ticket information to the console window
	
		int GetTicketNumber() const {return workTicketNumber;} // returns Ticket number
	    int GetDay() const { return dayCreated; } // returns day created
	    int GetMonth() const { return monthCreated;} // returns month created
	    int GetYear() const { return yearCreated; } // returns year created
	    string GetDescription() const { return clietIssue; } // returns the clients error message 
	    string GetClientId() const { return clientID;} // returns the Clients Id
		
		//*****************************************
		// 			Mutators
		//*****************************************
	
		void setWorkTicketNumber(int tempWorkTicketNumber); //Sets the workTicketNumber value 
		void setClientID(string tempClientID); //Sets the clientID value 
		void setDayCreated(int tempDayCreated); //Sets the dayCreated value 
		void setMonthCreated(int tempMonthCreated); //Sets the monthCreated value 
		void setYearCreated(int tempYearCreated); //Sets the yearCreated value 
		void setClientIssue(string tempClientIssue); //Sets the clietIssue value 
		
		// Sets every value of the WorkTicket Class
		bool setWorkTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
						int tempMonthCreated, int tempYearCreated, string tempClietIssue);	
		
		//*****************************************
		// 			Operators
		//*****************************************  
		
		// overloading the compare operator to actually check each value and see if they are the same.
		bool operator==(const WorkingTicket& compare) const
		{
			return (workTicketNumber == compare.workTicketNumber &&
		 		dayCreated == compare.dayCreated && 
				monthCreated == compare.monthCreated &&
		 		yearCreated == compare.yearCreated && 
		   		clietIssue == compare.clietIssue && 
		   		clientID == compare.clientID); 
		}
		
		// over loading the equal operator so that the tickets don't hold the same memory address.		
		WorkingTicket& operator=(const WorkingTicket &);
		
		// Overloading display operator so that the information in displayed correctly 
		friend ostream& operator<<(ostream&, const WorkingTicket&);
		// overloading the in put operator so that the user can know what to input.
		friend istream& operator>>(istream&, WorkingTicket &);
		// overloading the string operator to format the information in a condenced form.
		operator string() const;
	
	private:
		int workTicketNumber; // value must be positive and above 1 to represent the ticket number
		int dayCreated; // value must be between 1 and 31 to represent the Day Created
		int monthCreated; // value must be between 1 and 12 to represent the Month Created
		int yearCreated; // value must be between 2000 and 2099 to represent the year Created	
		string clietIssue; // contents must not be empty and holds the Clients issue
		string clientID; // contents must not be empty and holds the Clients id	

		static const string MONTHS[];
};
//*****************************************************************************************
// 			Static Members
//*****************************************************************************************

const string WorkingTicket::MONTHS[] = { "Not used","January", "February", "March", "April", "May", "June",	"July", "August", "September", "October", "November", "December"};
	
//*****************************************************************************************
// 			MAIN
//*****************************************************************************************

int main()
{
	//*****************************************
	// 			Declaration
	//*****************************************  
		
	const int MAX_NUMBER_OF_TICKETS = 3; // the maximum amount of tickets that can be made 
	
	int count = 0; // counts what position in the array is currently being stored in
	
	int ticketnumber; // holds the ticket number
	int day; // holds the day the ticket is being made
	int month; // holds the month the ticket is being made
	int year; //  holds the year the ticket is being made
	string clientID; // holds the ID of the client
	string clientIssue; // holds the issue the client is having
	
	WorkingTicket tickets[MAX_NUMBER_OF_TICKETS]; // array that holds the tickets information   	 

	// information header
	cout << "Working Ticket Class Demo" << endl
		 << "=========================" << endl;

	//*****************************************
	// 			Input
	//*****************************************  
		
	
	while(count < MAX_NUMBER_OF_TICKETS) // runs till the tickets have been filled
	{
		try
		{
			cin >> tickets[count];

			system ("CLS"); //clears the screen
			
			// information header
			cout << "Working Ticket Class Demo" << endl
			 	 << "=========================" << endl;
				
			count++;// after user successfully enters in a corrent workingticket variable then moves on to ned array possition
		}
		catch(const exception& ex) // catches an error within the .setWorkTicket meathod call
		{
			system ("CLS"); //clears the screen
			cout << "Working Ticket Class Demo" << endl
			 	 << "=========================" << endl;
			 	 
			cerr << ex.what(); // display the exception message.
			cout << endl << "Please enter a new ticket" << endl;		
		}	
	}

	count = 0; // reset array placement as we move to the output stage

	//*****************************************
	// 			Output
	//*****************************************  

	while(count < MAX_NUMBER_OF_TICKETS) // runs till the tickets have been displayed
	{		
		system ("CLS");	// clears all the previous user input to not clutter the screen
		
		// information header
		cout << "Working Ticket Class Demo" << endl // display message to user
	 		 << "=========================\n" << endl; // display message to user
		
		cout << (string) tickets[count] << endl; // calls to the showWorkingTicket to display to the user	
		cout << ""<< endl; //outputs a blank line to the command propmt to split up text for readablility
		system("pause"); // waits for for user to move on to the next ticket
		count++; // moves on to the next place in the array
	}

	//*****************************************
	// 			Testing
	//*****************************************  

	cout << endl << "Testing if Ticket 1 is equal to ticket 2." << endl; // message to user 
	
	if(tickets[1] == tickets[2])	// checks if the 2 tickets are the same
	{
		cout <<  "Tickets are the same." << endl; // display to user
	}
	else
	{
		cout << "Tickets are not the same." << endl; // display to user
	}
	
	//TESTING
	//
	WorkingTicket a(tickets[1]);
	tickets[1] = tickets[2];
	
	cout << tickets[2] << endl;	
}
//*****************************************************************************************
// 			Constructors
//*****************************************************************************************

/** Parameterized Constructor for WorkingTicket class
 *  @param	 tempWorkTicketNumber: int (a number equal to or above 1)
 *  @param	 tempClientID: string (an alpha numeric code, must not be empty)
 *  @param	 tempDayCreated: int (a number between 1 and 31)
 *  @param	 tempMonthCreated: int (a number between 1 and 12)
 *  @param	 tempYearCreated: int (a number between 2000 and 2099)
 *  @param	 tempClietIssue: string (must not be empty)
*/
WorkingTicket::WorkingTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue)
{
	setWorkTicket(tempWorkTicketNumber,tempClientID,tempDayCreated,tempMonthCreated,tempYearCreated,tempClietIssue);
}

//Copy constructor
WorkingTicket::WorkingTicket(const WorkingTicket& oldTicket)
{
	workTicketNumber = oldTicket.workTicketNumber; 	// value must be positive and above 1 to represent the ticket number
	dayCreated = oldTicket.dayCreated; 				// value must be between 1 and 31 to represent the Day Created
	monthCreated = oldTicket.monthCreated; 			// value must be between 1 and 12 to represent the Month Created
	yearCreated = oldTicket.yearCreated; 			// value must be between 2000 and 2099 to represent the year Created	
	clietIssue = oldTicket.clietIssue;				// contents must not be empty and holds the Clients issue
	clientID = oldTicket.clientID; 					// contents must not be empty and holds the Clients id	

	cout << "\nA WorkTicket object was COPIED. \n";	
}
//*****************************************************************************************
// 			Mutators
//*****************************************************************************************

/** setWorkTicketNumber Method for WorkingTicket class
 *	Sets the Ticket number of the working ticket object.
 *  @param	tempWorkTicketNumber: int  (a number equal to or above 1)
 *	@throws	out_of_range exception if the param is invalid
 */
void WorkingTicket::setWorkTicketNumber(int tempWorkTicketNumber)
{
	const int MIN_WORK_TICKET = 1; 		// Lowest possible work ticket number
	
	if(tempWorkTicketNumber < MIN_WORK_TICKET) 	
	{
		stringstream strOut;
			
			strOut << "Work ticket argument: " << tempWorkTicketNumber << endl
				   <<" Is out of range. Work ticket must be above " << endl
				   << MIN_WORK_TICKET << ". " << endl;
			throw out_of_range(strOut.str());
	}
	else
	{
		workTicketNumber = tempWorkTicketNumber;
	}		
}

/** setClientID Method for WorkingTicket class
 *	Sets the Client Id of the working ticket object.
 *  @param	tempClientID: string  ( can't be empty)
 *	@throws	out_of_range exception if the param is invalid
 */
void WorkingTicket::setClientID(string tempClientID)
{
	if(tempClientID.empty())
	{
		stringstream strOut;
		
			strOut << "Client ID was left blank" << endl 
				   << "Cliet ID must not be empty." << endl;
			throw out_of_range(strOut.str());		
	}
	else
	{
		clientID = tempClientID;
	}
}

/** setClientIssue Method for WorkingTicket class
 *	Sets the Client Issue of the working ticket object.
 *  @param	tempClietIssue: string  ( can't be empty)
 *	@throws	out_of_range exception if the param is invalid
 */
void WorkingTicket::setClientIssue(string tempClietIssue)
{
	if(tempClietIssue.empty())
	{
		stringstream strOut;

			strOut << "Client Issue was left blank" << endl 
				   << "Cliet Issue must not be empty." << endl;
			throw out_of_range(strOut.str());				
	}
	else
	{
		clietIssue = tempClietIssue;
	}
}

/** setDayCreated Method for WorkingTicket class
 *	Sets the Day created of the working ticket object.
 *  @param	tempDayCreated: int  (a number between 1 and 31)
 *	@throws	out_of_range exception if the param is invalid
 */
void WorkingTicket::setDayCreated(int tempDayCreated)
{
	const int MIN_DAY_CREATED = 1;		// Lowest possible Day Created
	const int MAX_DAY_CREATED = 31;		// Highest possible Day Created
	if(tempDayCreated < MIN_DAY_CREATED || tempDayCreated > MAX_DAY_CREATED)
	{
		stringstream strOut;
			
		strOut << "Day Created argument: " << tempDayCreated << endl
			   <<" Is out of range. Day created must be above " << endl
			   << MIN_DAY_CREATED << " and below " << MAX_DAY_CREATED << ". " << endl;
		throw out_of_range(strOut.str());
	}
	else
	{
		dayCreated = tempDayCreated;			
	}
}

/** setMonthCreated Method for WorkingTicket class
 *	Sets the Month created of the working ticket object.
 *  @param	tempMonthCreated: int  (a number between 1 and 12)
 *	@throws	out_of_range exception if the param is invalid
 */
void WorkingTicket::setMonthCreated(int tempMonthCreated)
{
	const int MIN_MONTH_CREATED = 1; 	// Lowest possible Month Created
	const int MAX_MONTH_CREATED = 12;	// Highest possible Month Created	
	
	if(tempMonthCreated < MIN_MONTH_CREATED || tempMonthCreated > MAX_MONTH_CREATED)
	{
		stringstream strOut;
			
			strOut << "Month Created argument: " << tempMonthCreated << endl
				   <<" Is out of range. Month created must be above " << endl
				   << MIN_MONTH_CREATED << " and below " << MAX_MONTH_CREATED << ". " << endl;
			throw out_of_range(strOut.str());
	}
	else
	{
			monthCreated = tempMonthCreated;
	}
}

/** setYearCreated Method for WorkingTicket class
 *	Sets the Month created of the working ticket object.
 *  @param	tempYearCreated: int  (a number between 2000 and 2099)
 *	@throws	out_of_range exception if the param is invalid
 */
void WorkingTicket::setYearCreated(int tempYearCreated)
{
	const int MIN_YEAR_CREATED = 2000;  // Lowest possible Year Created
	const int MAX_YEAR_CREATED = 2099;  // Highest possible Year Created
	
	if(tempYearCreated < MIN_YEAR_CREATED || tempYearCreated > MAX_YEAR_CREATED)
	{
		stringstream strOut;
			
			strOut << "Year Created argument: " << tempYearCreated << endl
				   <<" Is out of range. Year created must be above " << endl
				   << MIN_YEAR_CREATED << " and below " << MAX_YEAR_CREATED << ". " << endl;
			throw out_of_range(strOut.str());
	}
	else
	{
		yearCreated = tempYearCreated;
	}
}

/** setWorkTicket Method for WorkingTicket class
 *	Sets the all the paramitors created by the working ticket object.
 *  @param	tempWorkTicketNumber: int  (a number equal to or above 1)
 *  @param	tempClientID: string  ( can't be empty)
 *  @param	tempDayCreated: int  (a number between 1 and 31)
 *  @param	tempMonthCreated: int  (a number between 1 and 12)
 *  @param	tempYearCreated: int  (a number between 2000 and 2099)
 *  @param	tempClietIssue: string  ( can't be empty)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setWorkTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue)
{
	// Local declarations 
	const int MIN_WORK_TICKET = 1; 		// Lowest possible work ticket number
	const int MIN_DAY_CREATED = 1;		// Lowest possible Day Created
	const int MAX_DAY_CREATED = 31;		// Highest possible Day Created
	const int MIN_MONTH_CREATED = 1; 	// Lowest possible Month Created
	const int MAX_MONTH_CREATED = 12;	// Highest possible Month Created
	const int MIN_YEAR_CREATED = 2000;  // Lowest possible Year Created
	const int MAX_YEAR_CREATED = 2099;  // Highest possible Year Created
	bool returnVariable = true;	
	
	if(tempWorkTicketNumber < MIN_WORK_TICKET) 	
	{
		stringstream strOut;
			
			strOut << "Work ticket argument: " << tempWorkTicketNumber << endl
				   <<" Is out of range. Work ticket must be above " << endl
				   << MIN_WORK_TICKET << ". " << endl;
		returnVariable = false;
	}
	else if(tempClientID.empty())
	{
		stringstream strOut;
		
			strOut << "Client ID was left blank" << endl 
				   << "Cliet ID must not be empty." << endl;		
		returnVariable = false;
	}
	else if(tempClietIssue.empty())
	{
		stringstream strOut;

			strOut << "Client Issue was left blank" << endl 
				   << "Cliet Issue must not be empty." << endl;			
		returnVariable = false;
	}
	else if(tempDayCreated < MIN_DAY_CREATED || tempDayCreated > MAX_DAY_CREATED)
	{
		stringstream strOut;
			
			strOut << "Day Created argument: " << tempDayCreated << endl
				   <<" Is out of range. Day created must be above " << endl
				   << MIN_DAY_CREATED << " and below " << MAX_DAY_CREATED << ". " << endl;
		returnVariable = false;
	}
	else if(tempMonthCreated < MIN_MONTH_CREATED || tempMonthCreated > MAX_MONTH_CREATED)
	{
		stringstream strOut;
			
			strOut << "Month Created argument: " << tempMonthCreated << endl
				   <<" Is out of range. Month created must be above " << endl
				   << MIN_MONTH_CREATED << " and below " << MAX_MONTH_CREATED << ". " << endl;
		returnVariable = false;
	}
	else if(tempYearCreated < MIN_YEAR_CREATED || tempYearCreated > MAX_YEAR_CREATED)
	{
		stringstream strOut;
			
			strOut << "Year Created argument: " << tempYearCreated << endl
				   <<" Is out of range. Year created must be above " << endl
				   << MIN_YEAR_CREATED << " and below " << MAX_YEAR_CREATED << ". " << endl;
		returnVariable = false;
	}
	else
	{
		workTicketNumber = tempWorkTicketNumber;
		dayCreated = tempDayCreated;
		monthCreated = tempMonthCreated;
		yearCreated = tempYearCreated;
		clietIssue = tempClietIssue;
		clientID = tempClientID;	
	}	
	return returnVariable;
}
//*****************************************************************************************
// 			Operators
//*****************************************************************************************

// equal operator
WorkingTicket& WorkingTicket::operator=(const WorkingTicket& oldTicket)
{
	workTicketNumber = oldTicket.workTicketNumber; 	// value of ticket number is stored to the new ticket's ticket
	dayCreated = oldTicket.dayCreated; 				// value of day is stored to the new ticket's day created value
	monthCreated = oldTicket.monthCreated; 			// value of month is stored to the new ticket's month created
	yearCreated = oldTicket.yearCreated; 			// value of years stored to the new ticket's year created
	clietIssue = oldTicket.clietIssue;				// value of the client's issue is stored to the new the ticket's Client issue
	clientID = oldTicket.clientID; 					// value of client's id is stored to the new ticket's client id

	cout << "\nA WorkTicket object was ASSIGNED.\n" << endl; // Requirement for lab // displays to user a message

	return *this; // returns (this) object 
}
// Output operator
ostream& operator<<(ostream &out, const WorkingTicket& theTicket)
{
	out << setfill('0') // sets the out to have a value of zeros
		<< "Work ticket number: " << theTicket.workTicketNumber << endl	//display work ticket number	 
	    << "Client ID: " << theTicket.clientID << endl // displays client id
	    << "Date Created: " << WorkingTicket::MONTHS[theTicket.monthCreated] << " " << theTicket.dayCreated << ", " << theTicket.yearCreated << endl // displays ticket creation date
		<< "Client Issue: " << theTicket.clietIssue ; //  displays clients issue to the user
	out << endl; // formating
	return out; // return the variable holding all the displays
}
// input operator
istream& operator>>(istream &in, WorkingTicket& theTicket)  
{
	//values to hold there corrisonding variable
	int ticketNumber;
	int dayCreated;
	int monthCreated;
	int yearCreated;
	string clientID;
	string clientIssue;
	
	//inputs stored in "in" variable
	cout << "Ticket Number: ";
	in >> ticketNumber;
	cout << "Day: ";
	in >> dayCreated;
	cout << "Month: ";
	in >> monthCreated;
	cout << "Year: ";
	in >> yearCreated;
	cout << "Client Id: ";
	in >> clientID;
	cout << "Client Issue: ";
	in >> clientIssue;
	cout << endl;
	
	// sets the variables to seperate mutators because of pervious requirements to not have exceptions on the big set and
	// displays indavidual errors.
	theTicket.setClientID(clientID);
	theTicket.setClientIssue(clientIssue);
	theTicket.setDayCreated(dayCreated);
	theTicket.setMonthCreated(monthCreated);
	theTicket.setYearCreated(yearCreated);
	theTicket.setWorkTicketNumber(ticketNumber);

	return in; // return everything within "in"
}

// string operator to convert the ticket to a strong type
WorkingTicket::operator string() const
{
	stringstream consoleDisplay;	//sets up a string to hold all values
	// formats information to be stored in the consoleDisplay variable to be sent to the user.
	consoleDisplay << "Work Ticket # " << workTicketNumber << " - " << clientID << "(" << monthCreated
					<< "/" << dayCreated << "/" << yearCreated << "):" << clietIssue;
	//return the consoleDisplay variable to the user
	return consoleDisplay.str();
}

//*****************************************************************************************
// 			Accessors
//*****************************************************************************************

/** showWorkTicket Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showWorkTicket() const
{
	stringstream strOut; 
	
	strOut << "Work ticket number: " << workTicketNumber << endl
		   << "Client ID: " << clientID << endl
		   << "Date Created: " << MONTHS[monthCreated] << " " << dayCreated << ", " << yearCreated << endl
		   << "Client Issue: " << clietIssue << endl;
		   
	return strOut.str();
}

									
