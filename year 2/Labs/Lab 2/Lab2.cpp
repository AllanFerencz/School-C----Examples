/** WorkTicketLab2.cpp
 *	
 *	WorkTicket 
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

class WorkingTicket
{
	public:
	
	
	
		
	WorkingTicket(): workTicketNumber(0), clientID(), dayCreated(1), 
					  monthCreated(1), yearCreated(2000), clietIssue() {}	
	
	WorkingTicket (int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue);					

	


	string showWorkTicketNumber() const;
	string showClientID() const;
	string showDayCreated() const;
	string showMonthCreated() const;
	string showYearCreated() const;
	string showClientIssue() const;
	
	string showWorkTicket() const; //Displays the ticket information to the console window
	string getMonthString() const; //Displays the month number in a string format


	bool setWorkTicketNumber(int tempWorkTicketNumber);
	bool setClientID(string tempClientID);
	bool setDayCreated(int tempDayCreated);
	bool setMonthCreated(int tempMonthCreated);
	bool setYearCreated(int tempYearCreated);
	bool setClientIssue(string tempClientIssue);

	bool SetWorkTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue);
	
	
	
	private:
		int workTicketNumber;
		int dayCreated;
		int monthCreated;
		int yearCreated;	
		string clietIssue;
		string clientID;	
};

int main()
{
	const int MAX_NUMBER_OF_TICKETS = 3;
	
	int count = 0;
	int maxTickets =0;
	
	int ticketnumber;
	int day;
	int month;
	int year;
	string clientID;
	string clientIssue;
	
	WorkingTicket tickets[3];
	
	cout << "Working Ticket Class Demo" << endl
		 << "=========================" << endl;
	
    time_t t = time(0); 
    struct tm * now = localtime( & t );
    	
	year = (now->tm_year + 1900);
    month = (now->tm_mon + 1) ;
    day = now->tm_mday;
         	 
		
	while(count < MAX_NUMBER_OF_TICKETS)
	{
		try
		{
			
			cout << endl;			
			cout << "Work Ticket Number: " << count+1 << endl;
			cout << "Please enter in your ID: ";
			getline(cin,clientID);
			cout << "Please explain your issue: ";
			getline(cin,clientIssue);	

		
			tickets[count].SetWorkTicket(count+1, clientID, day, month, year,clientIssue);
			count++;
		
		}
		catch(const exception& ex) 
		{
			cerr << ex.what(); // display the exception message.
			count = count -1;		
		}
		
	}

	count = 0;
		
	
	while(count < MAX_NUMBER_OF_TICKETS)
	{		
		
		cout << tickets[count].showWorkTicket();	
		cout << "";
		count++;
		system("pause");
	}
			
}

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
bool WorkingTicket::setClientID(string tempClientID)
{
	if(tempClientID.empty())
	{
		stringstream strOut;
		
		strOut << "Client ID argument: " << tempClientID << endl
			   <<" Must be set. Client ID must not be empty." << endl;
		throw out_of_range(strOut.str());	
		return false;	
	}
	else
	{
		clientID = tempClientID;
		return true;
	}
}
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


bool WorkingTicket::SetWorkTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
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
		
			strOut << "Client ID argument: " << tempClientID << endl
				   <<" Must be set. Client ID must not be empty." << endl;
			throw out_of_range(strOut.str());		
		return false;
	}
	else if(tempClietIssue.empty())
	{
		stringstream strOut;

			strOut << "Client Issue argument: " << tempClietIssue << endl 
				   <<" Must be set. Cliet Issue must not be empty." << endl;
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

WorkingTicket::WorkingTicket(int tempWorkTicketNumber, string tempClientID, int tempDayCreated, 
					int tempMonthCreated, int tempYearCreated, string tempClietIssue)
{
	SetWorkTicket(tempWorkTicketNumber,tempClientID,tempDayCreated,tempMonthCreated,tempYearCreated,tempClietIssue);
}

string WorkingTicket::getMonthString() const
{
	const string MONTHS[] = { "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December"};

	return MONTHS[monthCreated - 1];
}

string WorkingTicket::showWorkTicket() const
{
	stringstream strOut; 
	
	strOut << "Work ticket number: " << workTicketNumber << endl
		   << "Client ID: " << clientID << endl
		   << "Date Created: " << getMonthString() << " " << dayCreated << ", " << yearCreated << endl
		   << "Client Issue: " << clietIssue << endl;
		   
	return strOut.str();
}

string WorkingTicket::showClientIssue() const
{
	stringstream strOut; 

	strOut << "Client ID: " << clientID << endl;

	return strOut.str(); 
}
string WorkingTicket::showYearCreated() const
{
	stringstream strOut; 

	strOut << "Year Created: " << yearCreated << endl;

	return strOut.str(); 	
}
string WorkingTicket::showMonthCreated() const
{
	stringstream strOut; 
	
	strOut << "Date Created: " << monthCreated << endl;

	return strOut.str();	
}
string WorkingTicket::showDayCreated() const
{
	stringstream strOut; 
	
	strOut << "Day Created: " << dayCreated << endl;

	return strOut.str();	
}
string WorkingTicket::showClientID() const
{
	stringstream strOut; 
	
	strOut << "Client ID: " << clientID << endl;
		   
	return strOut.str();	
	
}
string WorkingTicket::showWorkTicketNumber() const
{
	stringstream strOut; 
	
	strOut << "Work ticket number: " << workTicketNumber << endl;
		   
	return strOut.str();
}

