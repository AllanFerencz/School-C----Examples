/*
 * Group 11
 * Members: Allan, Justin, Alex
 * Version: Prototype
 * Date: February 9, 2014
 * Description: This program will take a user input for a numeric grade and
 *              convert it into a GPA (Grade Point Average). The program will
 *              end if a negative value is entered (since you can't get a
 *              negative grade).
 */
 
#include <iostream>
#include <iomanip>

using namespace std;

double gpa(double grade); // prototype for calling gpa function
bool validation (double& validInput); // validate numeric entry

int main()
{
    // Variable declarations
     double grade = 0;
     bool validEntry = 0;
     
     do   // begin do-while loop processing
     {
          grade = 0;
          cout << "Please enter a grade to convert into a GPA \n(enter a negative value to end): "; // asks nicely for a numeric value
          cin >> grade;
          validEntry = validation(grade); // make the validEntry value equal to the returned function value
          system("cls");
          
          if (grade >= 101) // if the grade is over 100
          {
               system("cls");
               cout << "100 is a perfect grade. You cannot achieve higher.\n\n" << endl; // tried to be cheeky
          }
          else if (grade <= 100 && grade >= 0) // if range is valid
          {
              if (validEntry == 1) // makes sure bool value is 1 (true)
              {
                   gpa(grade); // calls gpa function, passes grade value
                   cout << "\nGrade: " << grade << "\nGPA: " << gpa(grade) << endl << endl; // output some fancy numbers
                   fflush(stdin); // CLEAR THE INPUT BUFFER. SO HANDY
              }
              else // if they tried to be funny
              {
                  system("cls");
                  cout << "Please enter a numeric value!" << endl;
              }
          }
          else // if they want to exit
          {
              system("cls");             // clear the screen
              cout << "\n\n" << endl;    // give some space
          }
          
     }while (grade >= 0); // do-while runs as long as grade isn't negative
     
     system("pause"); // hold screen for keypress
     return 0; // GIVE NOTHING BACK
}

double gpa(double grade) // function to calculate GPA
{
    double gpa;
    
    if (grade >= 49.5 && grade <= 54.4)           // if-else chain to decide what gpa to give
    {
        gpa = 1.0;
        
    }
    else if (grade >= 54.5 && grade <= 59.4)      // Conditional pass
    {
        gpa = 1.5;
    }
    else if (grade >= 59.5 && grade <= 64.4)      // Acceptable
    {
        gpa = 2.0;
    }
    else if (grade >= 64.5 && grade <= 69.4)      // Satisfactory
    {
        gpa = 2.5;
    }
    else if (grade >= 69.5 && grade <= 74.4)      // Good
    {
        gpa = 3.0;
    }
    else if (grade >= 74.5 && grade <= 79.4)      // Very Good
    {
        gpa = 3.5;
    }
    else if (grade >= 79.5 && grade <= 84.4)      // Excellent
    {
        gpa = 4.0;
    }
    else if (grade >= 84.5 && grade <= 89.4)      // Exemplary
    {
        gpa = 4.5;
    }
    else if (grade >= 89.5)                       // Outstanding
    {
        gpa = 5.0;
    }
    else                                          // Fail
    {
        gpa = 0.00;
    }
    return (gpa); // return gpa value
}

bool validation(double& vaildInput) // function to determine valid entry
{

	if(cin.fail()) // if it fails
	{	
		cin.clear();
		fflush(stdin);
		return 0; // return 0 for failure
	}
	else // or else
	{
		return 1; // return 1 for pass
	}
}
