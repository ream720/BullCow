
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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


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

    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |------|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}


//loop for the number of GUESS_COUNT asking for guesses
void PlayGame() {

    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();

    //TODO change to WHILE loop when we have validation done
    //loop asking for guesses while the game is NOT won
	   //and there are still tries remaining
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
	   FText Guess = GetValidGuess(); 

	   //submit valid guess
	   FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
	   std::cout << "Bulls = " << BullCowCount.Bulls;
	   std::cout << ". Cows = " << BullCowCount.Cows << ".\n\n";
    }

    PrintGameSummary();
    return;
}


//loop continually until the user gives a valid guess
FText GetValidGuess() {

    EGuessStatus Status = EGuessStatus::INVALID_STATUS;
    FText Guess = "";

    do {
	   int32 CurrentTry = BCGame.GetCurrentTry();
	   std::cout << "\nTry " << CurrentTry << " of " << BCGame.GetMaxTries();
	   std::cout << ": Enter your guess: ";
	   std::getline(std::cin, Guess);

	   Status = BCGame.CheckGuessValidity(Guess);
	   switch (Status) {
	   case EGuessStatus::NOT_ISOGRAM:
		  std::cout << "Please enter an isogram, or a word without repeating letters.\n\n";
		  break;

	   case EGuessStatus::WRONG_LENGTH:
		  std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
		  break;

	   case EGuessStatus::NOT_LOWERCASE:
		  std::cout << "Please use only lowercase letters.\n\n";
		  break;

	   default: break; //assume guess is valid;
	   }
    } while (Status != EGuessStatus::OK); //keep looping until there are no input errors
    return Guess;
}



//Ask the user to play again
bool AskToPlayAgain() {
    std::cout << "\nDo you want to play again with the same word? \n";
    std::cout << "Type Yes or No to continue. ";
    FText Response = "";
    std::getline(std::cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');
}


void PrintGameSummary() {
    if (BCGame.IsGameWon()) {
	   std::cout << "\n--! WELL DONE - YOU WIN !--\n";
    } else {
	   std::cout << "\n--! BETTER LUCK NEXT TIME !--\n";
    }
}

