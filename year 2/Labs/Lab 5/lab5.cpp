/** lab5.cpp
 *	
 *  A deck of cards program that can shuffle and allow the user to pick cards
 *
 *	@author		Julien Ouimet, Allan Ferencz
 *	@date		Nov 2014
 *
 *	@see		10-ObjectContainer2.cpp by Thom MacDonald
*/

#include <iostream>		
#include <stdexcept>
#include <ctime>
#include <cstdlib>

#include "StandardPlayingCard.h"

using namespace std;

// standard deck container class **************************************************** StandardDeck Class
class StandardDeck
{
	private:
		// Pointer array for size of deck
		StandardPlayingCard * cardArray; 
		// Current size of deck
		int deckSize;
		
	public:
		// Constructor
		StandardDeck(int size);
		
		// Copy Constructor
		StandardDeck(const StandardDeck &oldDeck); 
		
		// Overload Assignment Operator
		StandardDeck& operator=(const StandardDeck &oldDeck);
		
		// Destructor
		~StandardDeck() { delete [] cardArray;} 
		
		// Initialize Method
		virtual void Initialize(int size); 
		
		// Shuffle Method
		void Shuffle();
		
		// Accessor
		string showCards() const;
		
		// DrawNextCard Method
		StandardPlayingCard DrawNextCard();
		
		// Draw Random Card
		StandardPlayingCard DrawRandomCard();
		
		// Random card remover
		StandardPlayingCard RemoveRandomCard();
		
		// Resize Method
		void Resize(int newDeckSize);
		
		// Cards Remaining Method
		string CardsRemaining();	
};



// main **************************************************************************** Main		
int main()
{	
	
	try 
	{
		int size = 52;
	
		// Seed the random number generator
		srand(time(NULL));
		
		StandardDeck cards(size);
		
		cout << "\n\n~~~~CARDS!~~~~\n\n";
		
		// Show all cards as initialized
		cout << "The cards as initialized.*******************************************************" << endl;
		cout << cards.showCards() << endl;
		
		//Shuffle the cards
		cout << "\nAfter Shuffeling the cards...***************************************************" << endl;
		cards.Shuffle();
		
		// Show all cards after shuffle
		cout << cards.showCards() << endl;
		
		
		cout << "\n\nDrawing cards.******************************************************************" << endl;
		
		// Draw a card
		cout << "The card drawn from the back was the " << (string) cards.DrawNextCard() << endl;
		cout << "The next card drawn from the back was the " << (string) cards.DrawNextCard() << endl;
		cout << "The next card drawn from the back was the " << (string) cards.DrawNextCard() << endl;
		cout << "The next card drawn from the back was the " << (string) cards.DrawNextCard() << endl;
		
		//Draw a random card
		cout << "The random card drawn was the " << (string) cards.DrawRandomCard() << endl;
		cout << "The random card drawn was the " << (string) cards.DrawRandomCard() << endl;
		cout << "The random card drawn was the " << (string) cards.DrawRandomCard() << endl;
		cout << "The random card drawn was the " << (string) cards.DrawRandomCard() << endl;
		
		//Cards Remaining
		cout << "\n\n\nRemaining number of cards.******************************************************" << endl;
		cout << cards.CardsRemaining() << endl;
		
		// Show all cards remaining
		cout << "\n\nShow the remaining cards.*******************************************************" << endl;
		cout << cards.showCards() << endl;
		
		// Copy Constructor
		StandardDeck copyCards(cards);
		
		// Show all cards after copy
		cout << "\n\nShow the cards in the copied deck (copy constructor).***************************" << endl;
		cout << copyCards.showCards() << endl;
		
		// Assignment operator
		StandardDeck assignCards = cards;
		
		// Show all cards after copy
		cout << "\n\nShow the cards in the copied deck (Assignment operator).************************" << endl;
		cout << copyCards.showCards() << endl;

	}
	catch (const exception)
	{
		cerr << "\n\nERROR! " << endl;
	}
		
	return 0;	
};



// StandardDeck Constructor ******************************************************** Constructor
StandardDeck::StandardDeck(int size)
{
	// Initialize the pointer array to 0
	cardArray = 0;
	
	// Call the Initialize Method
	Initialize(size);	
}


// Copy Constructor *************************************************************** Copy Constructor
StandardDeck::StandardDeck(const StandardDeck &oldDeck)
{
	//Create a new array
	deckSize = oldDeck.deckSize;
	cardArray = new StandardPlayingCard [deckSize];
	
	//Copy the previous cardArray into a new one
	for(int count = 0; count < deckSize; count++)
	{
		cardArray[count] = oldDeck.cardArray[count];
	}
}


// Overload the Assignment Operator
StandardDeck& StandardDeck::operator=(const StandardDeck &oldDeck)
{
	// Delete the current cardArray
	delete [] cardArray;
	
	//Create new cardArray
	deckSize = oldDeck.deckSize;
	cardArray = new StandardPlayingCard [deckSize];
	
	//Copy the previous cardArray into a new one
	for(int count = 0; count < deckSize; count++)
	{
		cardArray[count] = oldDeck.cardArray[count];
	}
	
	return *this;
}



// Initialize Method ************************************************************** Initialize
void StandardDeck::Initialize(int size)
{
	// If memory for the pointer has already been allocated, delete it
	if (cardArray != 0)
	{
		delete [] cardArray;
	}
	
	// Make a new array
	cardArray = new StandardPlayingCard [size];
	deckSize = size;
	
	// Create the deck of cards in order
	int countArray = 0;
	
	// Loop through setting each array element as a card in order
	for (int countSuit = 0; countSuit <= 3; countSuit++)
	{					
		for (int countRank = 1; countRank < 14; countRank++)
		{	
			cardArray[countArray].setSuit(countSuit);	
			cardArray[countArray].setRank(countRank);
			
			countArray++;
		}
	}
}


// Shuffle Method *************************************************************** Shuffle 
void StandardDeck::Shuffle()
{
	// Make a newCardArray
	StandardPlayingCard * newCardArray = new StandardPlayingCard [deckSize];
	
	// Retain the original size of the current deck
	int newDeckSize = deckSize;
	
	// Using the DrawRandomCardMethod make each element of the new array equal to a random element from the original array
	for (int shuffleCount = 0; shuffleCount < newDeckSize; shuffleCount++)
	{
		newCardArray[shuffleCount] = StandardDeck::DrawRandomCard();
	}	
	
	// Delete the old cardArray
	delete [] cardArray;
	
	//the resize method from calling the DrawRandomCard method has now screwed up the deckSize, therefore reset it	
	deckSize = newDeckSize;
	
	// Set the old array pointer to the new array
	cardArray = newCardArray;
}


// Accessor ********************************************************************* showCards
string StandardDeck::showCards() const
{
	stringstream show;
	
	show 	<< "\nCURRENT DECK OF CARDS\n" << endl;
	
	// Show each card in the cardArray
	for (int countCards = 0; countCards < deckSize; countCards++)
	{
		show << "[" << countCards + 1 << "]" << (string) cardArray[countCards] << endl;
	}
	
	return show.str();
}


// DrawNextCard **************************************************************** DrawNextCard
StandardPlayingCard StandardDeck::DrawNextCard()
{
	// If there are no cards show an error message
	if (deckSize < 1)
	{
		throw out_of_range("There are no cards to pick from.");
	}
	
	// Get the card picked
	StandardPlayingCard cardPicked = cardArray[deckSize - 1];
	
	//Shrink the deck by one
	Resize(deckSize - 1);
	
	return cardPicked;
}



// DrawRandomCard ************************************************************* DrawRandomCard
StandardPlayingCard StandardDeck::DrawRandomCard()
{
	if (deckSize < 1)
	{
		throw out_of_range("There are no cards to pick from.");
	}
	
	// Randomize a number between 0 and size of deck inclusive
	int random = rand() % (deckSize);
	
	// Get the picked card
	StandardPlayingCard cardPicked = cardArray[random];
		
	// Shift all cards after the picked card backward
	for (int shift = random; shift < deckSize; shift++)
	{
		cardArray[shift] = cardArray[shift + 1];
	}
	
	// Resize the deck
	Resize(deckSize - 1);
	
	return cardPicked;
}

 

// Resize ********************************************************************* Resize 
void StandardDeck::Resize(int newDeckSize)
{
	// Create a newCardArray based on size passed
	StandardPlayingCard * newCardArray = new StandardPlayingCard[newDeckSize];
	
	// Copy remaining cards into newCardArray
	for (int count = 0; count < newDeckSize; count++)
	{
		newCardArray[count] = cardArray[count];
	}
	
	// Set the size to remaining cards
	deckSize = newDeckSize;
	
	// Delete the old cardArray
	delete [] cardArray;
	
	// Set the old array pointer to the new array
	cardArray = newCardArray;	
}



// Cards Remaining ************************************************************ Cards Remaining
string StandardDeck::CardsRemaining()
{
	stringstream remain;
	
	remain	<< "There are " << deckSize << " cards remaining in the deck." << endl;
	
	return remain.str();	
}






