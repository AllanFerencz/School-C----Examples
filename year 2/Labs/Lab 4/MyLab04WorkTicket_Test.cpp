/** MyLab04WorkTicket_Test.cpp
 *	
 *	Testing the header for Lab 4.
 *   
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		CPRG4202.Lab02.Classes.pdf
 *	@see		CPRG4202.Lab03.AddingFunctionality.pdf
 *	@see		CPRG4202.Lab04.Inheritance.pdf
 *  @see		tmLab04WorkTicket.h
 *	@see		MyDateV3.h
*/

#include <iostream>		// for cin, cout
#include "MyLab04WorkTicket.h" 	// version 2014.02
#include "MyInputValidation14.h" // for GetValidInt()

using namespace std;
using namespace myValidation14;

void Lab02Requirements();
void Lab03Requirements();
void Lab04Requirements();

int main()
{
	char choice;
	bool needInput = true;
	do
	{
		cout << "\nMENU " << endl
			 << "=====" << endl << endl
			 << "\'2\' Run Lab 2 Requirements" << endl
			 << "\'3\' Run Lab 3 Requirements" << endl
			 << "\'4\' Run Lab 4 Requirements" << endl
			 << "\'Q\' to Quit" << endl << endl
			 << ": ";
			 
		fflush(stdin);
		choice = cin.get();
		choice = toupper(choice);
		
		switch(choice)
		{
			case '2':
				Lab02Requirements();
				break;
			case '3':
				Lab03Requirements();
				break;
			case '4':
				Lab04Requirements();
				break;
			case 'Q':
				needInput = false;
				break;
			default:
				cout << "\nUnrecognized choice. Please try again.";
		}
	}while (needInput);
  
	cout << endl << endl;
	return 0;
}

void Lab02Requirements()
{
 	 // DECLARATIONS
	 const int NUMBER_OF_TICKETS = 3;
	 WorkTicket tickets[NUMBER_OF_TICKETS]; //	an array of at least three WorkTicket objects.
	 int ticketNumber;	 // temporary input variable
	 string clientId;	 // temporary input variable
	 int day;			 // temporary input variable
	 int month;			 // temporary input variable
	 int year;			 // temporary input variable
	 string description; // temporary input variable
	 	 
	 cout << "\n******************************************************" << endl;
	 cout << "                 Lab 02 Requirements" << endl;
	 cout << "            " << (string) MyDate::Today() << endl;
	 cout << "******************************************************" << endl << endl;
	 
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
	 
     cout << endl;
}

void Lab03Requirements()
{ 
	//Declare a new object based on an existing object.
	WorkTicket ticket1(1, "ABC-123", 1, 4, 2014, "Password Reset");
	WorkTicket ticket2 = ticket1;
	
	cout << "\n******************************************************" << endl;
	cout << "                 Lab 03 Requirements" << endl;
	cout << "            " << (string) MyDate::Today() << endl;
	cout << "******************************************************" << endl << endl;
	
	
	//Typecast an object as a string and output it to the console.
	cout << (string) ticket1 << endl;
	
	//Have the user input an object's attributes from the console using cin.
	cin >> ticket2;
	
	//Test if two objects are equal.
	if(ticket1 == ticket2)
	{
		cout << endl << (string) ticket1 << " is the same as " 
			 << endl << (string) ticket2 << endl;
	}
	else
	{
		cout << endl << (string) ticket1 << " is different than " 
			 << endl << (string) ticket2 << endl;
	}
	
	//Assign an existing object to another existing object.
	ticket1 = ticket2;
	
	//Output an object to the console using cout.
	cout << ticket1 << endl;
	 
    cout << endl;
}

void Lab04Requirements()
{
	//Thom's testing code
	ExtendedWorkTicket testTicket1; 
	ExtendedWorkTicket testTicket2(true, 2, "AMCE_123", 1, 7, 2014, "Password Reset");
	
	cout << endl << "As Initialized: " << endl; testTicket1.ShowWorkTicket(); testTicket2.ShowWorkTicket();
	
	if(!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true)) 
	cout << "\nErrors! No changes to the ticket made." << endl;
	
	cout << endl << "Ticket 1: " << testTicket1 << endl;
	
	if(!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false)) 
	cout << "\nErrors! No changes to the ticket made." << endl;

	cout << endl << "Ticket 2: " << testTicket2 << endl;
	
	testTicket2.CloseTicket();
	
	cout << endl << "After Ticket 2 closed: " << testTicket2 << endl;
	cout << endl << endl; 
}
