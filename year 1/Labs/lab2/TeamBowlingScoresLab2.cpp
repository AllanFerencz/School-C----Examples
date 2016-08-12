/*  Name: Allan
	Program Name: TeamBowlingScoresLab2
	Date:2014-01-26
	Description:	This program has the user enter bowling scores for 5 different team members
*/




#include <iostream> // for cin and cout
using namespace std; // std means standard


int main()
{
	int scoreCount; // count for what number of game the player is currently entering
	int playerCount; // count for what player is currently entering scores for games
	double avgScore; // holds the average score of the player
	double avgTeamScore; // holds the team score for all the players
	double userInput; // holds what the user has enterd
	const int highestScore = 300; // holds what the highest possable score could be
	const int lowestScore = 0; // holds what the lowest possable score could be
	
	string decimalTest = ""; // holds the user input to test for a decimal
	
	playerCount = 1; // sets the counts to 1 so the while loops run correctly
	scoreCount = 1; // sets the counts to 1 so the while loops run correctly

	while (playerCount <=3) // When playerCount hits 4 than 3 players have input scores
	{
	
	
		while (scoreCount <= 3) // When scoreCount hits 4 than the player has entered scores for 3 games
		{
			cout << "Please enter a score for game #" << scoreCount <<" for bowler #" << playerCount << "\n";  // promts the user to enter score for the current game
			cin >> userInput; // puts score in to userInput
			decimalTest = userInput; // puts userInput in to a string variable to test for a decimal

			if( cin.fail() ) // if statement to check if cin failed meaning that he user entered a 
			{
				// Error msg
				cout << "Error: Number not numeric, please enter a number between " << lowestScore << " - " << highestScore <<"\n";
				cin.clear(); //Clears the error flag on the cin
				fflush(stdin); //clears the buffer 
			}
			else
			{
				
				std::size_t found = decimalTest.find("."); // checks if user had a decimal in the input
				
				if (userInput <= (lowestScore - 1) || userInput >=(highestScore + 1)) // checks if the user entered a out of range number
				{
					// Error msg
					cout << "Error: Number out of range, please enter a number between " << lowestScore << " - " << highestScore <<"\n";
				}
				else if  (found == std::string::npos)
				{			
					// Error msg
					cout << "Error: Number is deciamal, please enter a number between " << lowestScore << " - " << highestScore <<"\n";	
				}
		    	else // when this point is hit than know errors are left
		   		{	    		
				avgScore += (double)userInput; // acumalates the scores
				scoreCount++; // moves on to the next score
				}
			}
		}
		scoreCount = 1; // resets to game 1 for next player
		avgScore = avgScore / 3; // does the math on the average score
		avgTeamScore += avgScore; // acumalates the team score of the players
		cout << "Average Score of bowler number #" << playerCount << ": " << avgScore << "\n"; // Displays the average score of the bowler
		avgScore = 0; // resets the avg score for the next player
		playerCount++; // moves to the next player
	}
	avgTeamScore = avgTeamScore / 3; // calculates the average score of the team
	cout <<"Average Team Score: " << avgTeamScore; // Displays the team average score
}


