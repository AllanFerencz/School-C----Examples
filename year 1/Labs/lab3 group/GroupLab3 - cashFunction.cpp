 /** CPRG11_GroupLab3.cpp
 *	  
 *	   
 *	@author		Allan Ferencz
 *	@version	2014.01
 *	@since		2014-02-04
*/


#include <iostream>	// cin and cout
#include <stdlib.h> // System clear
using namespace std; // cin and cout


void cash(int TotalDollarAmount,int& hundreds,int& fifties,int& twenties,int& tens,int& fives,int& toonies,int& loonies); // prototype for the cash function that sorts the money entered to lowest bills

void clearCash(int& hundreds,int& fifties,int& twenties,int& tens,int& fives,int& toonies,int& loonies);// prototype to clearCash since it needs to be reset

bool validation(double& vaildatedNumber); // validate for non numeric entry

int main()
{
	//***********Declaration***********
	int hundreds = 0; //declare the variable for the hundred dollor bills and set it to 0
	int fifties  = 0; //declare the variable for the fiftie dollor bills and set it to 0
	int twenties = 0; //declare the variable for the twentie dollor bills and set it to 0
	int tens = 0; //declare the variable for the ten dollor bills and set it to 0
	int fives = 0; //declare the variable for the five dollor bills and set it to 0
	int toonies = 0; //declare the variable for the toonies and set it to 0
	int loonies = 0; //declare the variable for the loonies and set it to 0
	double cashValue; // User enters cash value 
	bool validationPass = 0; // bool that holds in the validation was sucessful
	int count = 0; // count to keep track of what number its run through
	
	cout << string( 6, '\n' ); // Formatting so it doesn't look confusing 
	while( count < 3) // while loop because I don't know how many times this will be run through
	{
	
	cout << "\nPlease enter an amount of money\n"; //Display to user to enter money 
	
	cin >> cashValue; // wait for user to enter an amout of money
	system("cls"); // clear console formatting
	validationPass = validation(cashValue); //call the validation function to check if user enterd a string number

	if (validationPass == 1) // checks the variable after the validation to check if its correct
	{
	
	cash(cashValue,hundreds, fifties,twenties,tens,fives,toonies,loonies); // runs through the cash function to sort through the bills
	
	
	//***********Display***********
	cout << "Hundreds: " << hundreds; 
	cout << "\nFifties: " << fifties;
	cout << "\nTwenties: " << twenties;
	cout << "\nTens: " << tens;
	cout << "\nFives: " << fives;
	cout << "\nToonies: " << toonies;
	cout << "\nLoonies: " << loonies;
	
	clearCash(hundreds, fifties,twenties,tens,fives,toonies,loonies); //clears the variables for the amount of bills
	}
	else // if its not a number than its a string 
	{
		cout << "Error: Please enter a numeric number"; // Error message for user entry
		cout << string( 6, '\n' ); //formatting
		count = count - 1; // since the user entered an incorrect number sets the count down one so they still can enter 3 
	}
	count = count + 1; // adds one to the count to move closer to the total 3 needed
	}
	return 0; // returns 0 to pause the program
}
void cash(int TotalDollarAmount,int& hundreds,int& fifties,int& twenties,int& tens,int& fives,int& toonies,int& loonies)
{
	while (TotalDollarAmount >= 1) // if the money is less than 1 than it doesn't get sorted in to bils
	{
		if (TotalDollarAmount >= 100) // if the money is greater than 100 than it can add one to the 100 dollor bills
		{
		hundreds++;// add one to the count
		TotalDollarAmount -= 100; // since the money was transfered in to a bill it can be droped from the total
		}
		
		else if (TotalDollarAmount >= 50)// if the money is greater than 50 than it can add one to the 50 dollor bills
		{
		fifties++;// add one to the count
		TotalDollarAmount -= 50; // since the money was transfered in to a bill it can be droped from the total
		}
		
		else if (TotalDollarAmount >= 20)// if the money is greater than 20 than it can add one to the 20 dollor bills
		{
		twenties++;// add one to the count
		TotalDollarAmount -= 20; // since the money was transfered in to a bill it can be droped from the total
		}
		
		else if (TotalDollarAmount >= 10)// if the money is greater than 10 than it can add one to the 10 dollor bills
		{
		tens++; // add one to the count
		TotalDollarAmount -= 10	;	 // since the money was transfered in to a bill it can be droped from the total
		}
		
		else if (TotalDollarAmount >= 5)// if the money is greater than 5 than it can add one to the 5 dollor bills
		{
		fives++;// add one to the count
		TotalDollarAmount -= 5; // since the money was transfered in to a bill it can be droped from the total
		}
		
		else if (TotalDollarAmount >= 2)// if the money is greater than 2 than it can add one to the toonies
		{
		toonies++;// add one to the count
		TotalDollarAmount -= 2; // since the money was transfered in to a coin it can be droped from the total
		}
		
		else if (TotalDollarAmount >= 1)// if the money is greater than 1 than it can add one to the loonies
		{
		loonies++;// add one to the count
		TotalDollarAmount -= 1; // since the money was transfered in to a coin it can be droped from the total
		}
	}
}
void clearCash(int& hundreds,int& fifties,int& twenties,int& tens,int& fives,int& toonies,int& loonies)
{
	//Clears the counts for bills/coins. I made this so that if I ever need to use this function I can use both instead of havign to find the clearvariables in the main()
	hundreds = 0;
	fifties  = 0;
	twenties = 0;
	tens = 0;
	fives = 0;
	toonies = 0;
	loonies = 0;
}

bool validation(double& vaildatedNumber)
{

	if( cin.fail() ) // if statement to check if cin failed meaning that he user entered a non-number
	{	
		cin.clear(); //Clears the error flag on the cin
		fflush(stdin); //clears the buffer 
		return 0; // return a 0 to indacate it failed
	}
	else
	{
		return 1; // return a 1 since it didn't fail
	}
}
