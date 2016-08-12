/** GroupLab6.cpp
 *	
 *	Group Lab
 *	Program opens a file with all employees names, hours worked and wage. Then
 *	Saves a chart with name and money earned per employee along with total money
 *	required to pay employees in to "pay.txt" 
 *	   
 *	@author		Allan Ferencz, Alexander Plant, Justin Walker
 *	@version	2014.01
 *	@since		2014-03-25
*/

#include <iostream>
#include <iomanip>
#include <fstream>	// needed for ifstream class
using namespace std;

int main()
{
	// DECLARATIONS
	string fileName = "hours.txt";	// hold the file name to open
	string targetFileName = "pay.txt";
	ifstream inFile;		// an ifstream object to connect to the file	
  	string firstName;
  	string lastName;
  	string fullName;
  	const string dot = ". ";
  	double hoursWorked;
  	double wage;
  	double moneyEarned;
  	double totalMoney;
	int returnValue = 0; 	// holds the return value for main()	
	
	ofstream outFile;
	
	inFile.open(fileName.c_str());
	
	if(inFile.fail()) // If the input file could not be opened
 	{
 		// Inform the user
		cout << "\nThe file hours.txt was NOT successfully opened. "
			 << "Check that the file exists" << endl;
		
		// set the return value of main() to 1
		returnValue = 1;  // '1' indicating the program did not 
 	 				      // execute successfully
 	}
 	else
 	{
 		outFile.open(targetFileName.c_str());
 		
		if (outFile.fail())
		{
			// Inform the user
			cout << "\nThe Desination file was NOT successfully opened. "
				 << "Check that the file exists" << endl;
		
		// set the return value of main() to 1
		returnValue = 1;  // '1' indicating the program did not 
 	 				      // execute successfully
		}
		else
		{
			outFile << " Names: Allan Ferencz, Alexander Plant, Justin Walker"<< endl;
 			outFile << " PAY FOR THIS WEEK" << endl;
 			outFile << " ============================\n"<< endl;
 		
 				while(!inFile.eof())
				{
			
					inFile >> firstName >> lastName >> hoursWorked >> wage;
					fullName = firstName.at(0) + dot + lastName;
					moneyEarned = hoursWorked * wage;
					totalMoney = moneyEarned + totalMoney;
					if(!inFile.eof())
					{
						outFile  << right << setw(15) << fullName << "   $   "
						   		 << left << setw(10) << fixed << setprecision(2) << moneyEarned << endl;	
					}
				}
			
				inFile.close(); // close the file.
				outFile << "\n ============================\n";
				outFile << "         Total:   $   " << fixed << setprecision(2) << totalMoney;
				outFile.close();	
		}
	}
	
	cout << endl << endl;
	return returnValue;
	
}
