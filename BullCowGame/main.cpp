
/* This is the console executable that makes use of the BullCow class.
    This acts as the view in a MVC pattern and is responsible for all user interaction.
    
    For game logic, see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;


//functions list / PROTOTYPES
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; //instantiate a new game



//MAIN
int main() {

    do {
	   PrintIntro();
	   PlayGame();

    } while (AskToPlayAgain() == true);

    return 0;
}



//   METHODS & FUNCTIONS	  METHODS & FUNCTIONS    METHODS & FUNCTIONS	  METHODS & FUNCTIONS	  METHODS & FUNCTIONS    METHODS & FUNCTIONS	METHODS & FUNCTIONS	  METHODS & FUNCTIONS    METHODS & FUNCTIONS


    //introduce the game
void PrintIntro() {
    constexpr int32 WORD_LENGTH = 5; //word length test condition

    std::cout << std::endl;
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << std::endl;

    std::cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?" << std::endl; //begin game by asking for a guess
    return;
}


//get a guess from the player
FText GetGuess() {

    int32 CurrentTry = BCGame.GetCurrentTry();

    FText Guess = "";
    std::cout << "Try: " << CurrentTry << ". Enter your guess: ";
    std::getline(std::cin, Guess);
    return Guess;
}


//loop for the number of GUESS_COUNT asking for guesses
void PlayGame() {

    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();

    //TODO change to WHILE loop when we have validation done
    for (int32 i = 1; i <= MaxTries; i++) {
	   FText Guess = GetGuess(); //TODO loop validity checker

	   //submit valid guess
	   //print bulls and cows

	   //repeat the guess back to them
	   std::cout << "You guessed: " + Guess + "\n" << std::endl;
    }
    //TODO summarize game 
}

//Ask the user to play again
bool AskToPlayAgain() {
    std::cout << "Do you want to play again? \n";
    std::cout << "Type Yes or No to continue. ";
    FText Response = "";
    std::getline(std::cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');
}

