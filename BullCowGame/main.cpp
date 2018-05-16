
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

    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter word I'm thinking of?" << std::endl; //begin game by asking for a guess
    return;
}

//loop continually until the user gives a valid guess
FText GetValidGuess() {

    EGuessStatus Status = EGuessStatus::INVALID_STATUS;

    do {
	   int32 CurrentTry = BCGame.GetCurrentTry();
	   FText Guess = "";
	   std::cout << "Try " << CurrentTry << ": Enter your guess: ";
	   std::getline(std::cin, Guess);

	  Status = BCGame.CheckGuessValidity(Guess);
		 switch (Status) {
		  case EGuessStatus::NOT_ISOGRAM:
			 std::cout << "Please enter an isogram, or a word without repeating letters.";
			 break;

		  case EGuessStatus::WRONG_LENGTH:
			 std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			 break;

		  case EGuessStatus::NOT_LOWERCASE:
			 std::cout << "Please use only lowercase letters.";
			 break;

		  default: return Guess;
		 }
		  std::cout << "\n" << std::endl;
	   } while (Status != EGuessStatus::OK); //keep looping until there are no input errors
    }



//loop for the number of GUESS_COUNT asking for guesses
void PlayGame() {

    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();

    //TODO change to WHILE loop when we have validation done
    for (int32 i = 1; i <= MaxTries; i++) {
	   FText Guess = GetValidGuess(); 

	   //submit valid guess
	   FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
	   std::cout << "\nBulls = " << BullCowCount.Bulls;
	   std::cout << "\nCows = " << BullCowCount.Cows << std::endl;
	   std::cout << "\nYou guessed: " + Guess + "\n" << std::endl;
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

