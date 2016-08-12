/** WorkTicketLab2.cpp
 *	
 *	created a WorkTicket class to hold issues 
 *  clients have along with general information that goes along with them.
 *  Program askes the user for a client ID and Client Issue. That repeats 3 times
 *  then displays that to the user.
 *   
 *	@author		Allan Ferencz, Dilpreet Singh
 *	@since		20 Sept 2014
*/

#include <ctime>
#include <iostream>
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for out_of_range
#include <sstream>		// for stringstream
#include <cstdlib>		// for system()
//#include "MyInputValidation.h" // for GetValidDouble()
using namespace std;	

class WorkingTicket // Class declaration section
{
	public:
	// Default constructor using an initialization list
	// - by default
	//Ticket number is 0
	//Client ID is ""
	//Date Created is 1/1/2000
	//Client Issue is ""	
	WorkingTicket(): workTicketNumber(0), clientID(), dayCreated(1), 
					  monthCreated(1), yearCreated(2000), clietIssue() {}	
	// Parameterized constructor
	WorkingTicket (int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue);					

	// Accessors
	string showWorkTicketNumber() const; //Shows the workTicketNumber value to the command window
	string showClientID() const; //Shows the clientID value to the command window
	string showDayCreated() const; //Shows the dayCreated value to the command window
	string showMonthCreated() const; //Shows the monthCreated value to the command window
	string showYearCreated() const; //Shows the yearCreated value to the command window
	string showClientIssue() const; //Shows the clietIssue value to the command window
	string showWorkTicket() const; //Displays the ticket information to the console window
	string getMonthString() const; //Displays the month number in a string format

	//Mutators
	bool setWorkTicketNumber(int tempWorkTicketNumber); //Sets the workTicketNumber value 
	bool setClientID(string tempClientID); //Sets the clientID value 
	bool setDayCreated(int tempDayCreated); //Sets the dayCreated value 
	bool setMonthCreated(int tempMonthCreated); //Sets the monthCreated value 
	bool setYearCreated(int tempYearCreated); //Sets the yearCreated value 
	bool setClientIssue(string tempClientIssue); //Sets the clietIssue value 

	//Mutator - setWorkTicket
	//Sets the workTicketNumber value 
	//Sets the clientID value 
	//Sets the dayCreated value 
	//Sets the monthCreated value 
	//Sets the yearCreated value 
	//Sets the clietIssue value 
	bool setWorkTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue);	
	
	private:
		int workTicketNumber; // value must be positive and above 1 to represent the ticket number
		int dayCreated; // value must be between 1 and 31 to represent the Day Created
		int monthCreated; // value must be between 1 and 12 to represent the Month Created
		int yearCreated; // value must be between 2000 and 2099 to represent the year Created	
		string clietIssue; // contents must not be empty and holds the Clients issue
		string clientID; // contents must not be empty and holds the Clients id	
};

int main()
{
	const int MAX_NUMBER_OF_TICKETS = 3; // the maximum amount of tickets that can be made 
	
	
	int count = 0; // counts what position in the array is currently being stored in
	
	int ticketnumber; // holds the ticket number
	int day; // holds the day the ticket is being made
	int month; // holds the month the ticket is being made
	int year; //  holds the year the ticket is being made
	string clientID; // holds the ID of the client
	string clientIssue; // holds the issue the client is having
	
	WorkingTicket tickets[MAX_NUMBER_OF_TICKETS]; // array that holds the tickets information
	
	
    time_t t = time(0); 
    struct tm * now = localtime( & t );
    	
	year = (now->tm_year + 1900); // stores year in to year variable
    month = (now->tm_mon + 1) ; // stores month in to month variable
    day = now->tm_mday; //stores day in to day variable
         	 

	// information header
	cout << "Working Ticket Class Demo" << endl
		 << "=========================" << endl;

	//INPUT	
	while(count < MAX_NUMBER_OF_TICKETS) // runs till the tickets have been filled
	{
		try
		{

			
			cout << "\nWork Ticket Number: " << count+1 << endl; // display workticket number too user
			cout << "Please enter in your ID: ";// display message to user
			getline(cin,clientID); //user enters the client id
			cout << "Please explain your issue: "; // display message to user
			getline(cin,clientIssue); // user enters the Issue	


			system ("CLS"); //clears the screen
			
			// information header
			cout << "Working Ticket Class Demo" << endl
			 	 << "=========================" << endl;
			
			// sets the workticket information with all the gather peramitors
			//returns true or false depending on if there was an error or not
			//I don't do anything with it but I programmed it incase future need
			//True means no error, false means an error
			tickets[count].setWorkTicket(count+1, clientID, day, month, year,clientIssue);
			
			count++;// after user successfully enters in a corrent workingticket variable then moves on to ned array possition
		}
		catch(const exception& ex) // catches an error within the .setWorkTicket meathod call
		{
			cerr << ex.what(); // display the exception message.		
		}	
	}

	count = 0; // reset array placement as we move to the output stage
		
	//OUTPUT
	while(count < MAX_NUMBER_OF_TICKETS) // runs till the tickets have been displayed
	{		
		system ("CLS");	// clears all the previous user input to not clutter the screen
		
		// information header
		cout << "Working Ticket Class Demo" << endl // display message to user
	 		 << "=========================\n" << endl; // display message to user
		
		cout << tickets[count].showWorkTicket(); // calls to the showWorkingTicket to display to the user	
		cout << ""<< endl; //outputs a blank line to the command propmt to split up text for readablility
		system("pause"); // waits for for user to move on to the next ticket
		count++; // moves on to the next place in the array
	}
			
}


//Constructor


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


//Mutators


/** setWorkTicketNumber Method for WorkingTicket class
 *	Sets the Ticket number of the working ticket object.
 *  @param	tempWorkTicketNumber: int  (a number equal to or above 1)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setWorkTicketNumber(int tempWorkTicketNumber)
{
	const int MIN_WORK_TICKET = 1; 		// Lowest possible work ticket number
	
	if(tempWorkTicketNumber < MIN_WORK_TICKET) 	
	{
		stringstream strOut;
			
			strOut << "Work ticket argument: " << tempWorkTicketNumber << endl
				   <<" Is out of range. Work ticket must be above " << endl
				   << MIN_WORK_TICKET << ". " << endl;
			throw out_of_range(strOut.str());
			return false;
	}
	else
	{
		workTicketNumber = tempWorkTicketNumber;
		return true;
	}
	
	
		
}
/** setClientID Method for WorkingTicket class
 *	Sets the Client Id of the working ticket object.
 *  @param	tempClientID: string  ( can't be empty)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setClientID(string tempClientID)
{
	if(tempClientID.empty())
	{
		stringstream strOut;
		
			strOut << "Client ID was left blank" << endl 
				   << "Cliet ID must not be empty." << endl;
			throw out_of_range(strOut.str());		
		return false;	
	}
	else
	{
		clientID = tempClientID;
		return true;
	}
}
/** setClientIssue Method for WorkingTicket class
 *	Sets the Client Issue of the working ticket object.
 *  @param	tempClietIssue: string  ( can't be empty)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setClientIssue(string tempClietIssue)
{
	if(tempClietIssue.empty())
	{
		stringstream strOut;

			strOut << "Client Issue was left blank" << endl 
				   << "Cliet Issue must not be empty." << endl;
			throw out_of_range(strOut.str());				
		return false;	
	}
	else
	{
		clietIssue = tempClietIssue;
		return true;
	}
}
/** setDayCreated Method for WorkingTicket class
 *	Sets the Day created of the working ticket object.
 *  @param	tempDayCreated: int  (a number between 1 and 31)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setDayCreated(int tempDayCreated)
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
		return false;
	}
	else
	{
		dayCreated = tempDayCreated;		
		return true;	
	}
}
/** setMonthCreated Method for WorkingTicket class
 *	Sets the Month created of the working ticket object.
 *  @param	tempMonthCreated: int  (a number between 1 and 12)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setMonthCreated(int tempMonthCreated)
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
			return false;
	}
	else
	{
			monthCreated = tempMonthCreated;
			return true;
	}

}
/** setYearCreated Method for WorkingTicket class
 *	Sets the Month created of the working ticket object.
 *  @param	tempYearCreated: int  (a number between 2000 and 2099)
 *	@throws	out_of_range exception if the param is invalid
 */
bool WorkingTicket::setYearCreated(int tempYearCreated)
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
			return false;
	}
	else
	{
		yearCreated = tempYearCreated;
		return true;
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
	
	
	if(tempWorkTicketNumber < MIN_WORK_TICKET) 	
	{
		stringstream strOut;
			
			strOut << "Work ticket argument: " << tempWorkTicketNumber << endl
				   <<" Is out of range. Work ticket must be above " << endl
				   << MIN_WORK_TICKET << ". " << endl;
			throw out_of_range(strOut.str());
		return false;
	}
	else if(tempClientID.empty())
	{
		stringstream strOut;
		
			strOut << "Client ID was left blank" << endl 
				   << "Cliet ID must not be empty." << endl;
			throw out_of_range(strOut.str());		
		return false;
	}
	else if(tempClietIssue.empty())
	{
		stringstream strOut;

			strOut << "Client Issue was left blank" << endl 
				   << "Cliet Issue must not be empty." << endl;
			throw out_of_range(strOut.str());				
		return false;
	}
	else if(tempDayCreated < MIN_DAY_CREATED || tempDayCreated > MAX_DAY_CREATED)
	{
		stringstream strOut;
			
			strOut << "Day Created argument: " << tempDayCreated << endl
				   <<" Is out of range. Day created must be above " << endl
				   << MIN_DAY_CREATED << " and below " << MAX_DAY_CREATED << ". " << endl;
			throw out_of_range(strOut.str());
		return false;
	}
	else if(tempMonthCreated < MIN_MONTH_CREATED || tempMonthCreated > MAX_MONTH_CREATED)
	{
		stringstream strOut;
			
			strOut << "Month Created argument: " << tempMonthCreated << endl
				   <<" Is out of range. Month created must be above " << endl
				   << MIN_MONTH_CREATED << " and below " << MAX_MONTH_CREATED << ". " << endl;
			throw out_of_range(strOut.str());
		return false;
	}
	else if(tempYearCreated < MIN_YEAR_CREATED || tempYearCreated > MAX_YEAR_CREATED)
	{
		stringstream strOut;
			
			strOut << "Year Created argument: " << tempYearCreated << endl
				   <<" Is out of range. Year created must be above " << endl
				   << MIN_YEAR_CREATED << " and below " << MAX_YEAR_CREATED << ". " << endl;
			throw out_of_range(strOut.str());
		return false;
	}
	else
	{
		workTicketNumber = tempWorkTicketNumber;
		dayCreated = tempDayCreated;
		monthCreated = tempMonthCreated;
		yearCreated = tempYearCreated;
		clietIssue = tempClietIssue;
		clientID = tempClientID;	
		return true;
	}	
}

//Accessors


/** getMonthString Method for WorkingTicket class
 *	Gets the Month of this WorkingTicket object as a string.
 *  @return	the name of the Month corresponding to the Month number.
 */
string WorkingTicket::getMonthString() const
{
	const string MONTHS[] = { "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December"};

	return MONTHS[monthCreated - 1];
}
/** showWorkTicket Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showWorkTicket() const
{
	stringstream strOut; 
	
	strOut << "Work ticket number: " << workTicketNumber << endl
		   << "Client ID: " << clientID << endl
		   << "Date Created: " << getMonthString() << " " << dayCreated << ", " << yearCreated << endl
		   << "Client Issue: " << clietIssue << endl;
		   
	return strOut.str();
}
/** showClientIssue Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showClientIssue() const
{
	stringstream strOut; 

	strOut << "Client ID: " << clientID << endl;

	return strOut.str(); 
}
/** showYearCreated Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showYearCreated() const
{
	stringstream strOut; 

	strOut << "Year Created: " << yearCreated << endl;

	return strOut.str(); 	
}
/** showMonthCreated Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showMonthCreated() const
{
	stringstream strOut; 
	
	strOut << "Date Created: " << monthCreated << endl;

	return strOut.str();	
}
/** showDayCreated Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showDayCreated() const
{
	stringstream strOut; 
	
	strOut << "Day Created: " << dayCreated << endl;

	return strOut.str();	
}
/** showClientID Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showClientID() const
{
	stringstream strOut; 
	
	strOut << "Client ID: " << clientID << endl;
		   
	return strOut.str();	
	
}
/** showWorkTicketNumber Method for WorkingTicket class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string WorkingTicket::showWorkTicketNumber() const
{
	stringstream strOut; 
	
	strOut << "Work ticket number: " << workTicketNumber << endl;
		   
	return strOut.str();
}

