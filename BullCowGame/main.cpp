#include <iostream>
#include <string>
#include "FBullCowGame.h"


//functions list / PROTOTYPES
void PrintIntro();
void PlayGame();
std::string GetGuess();
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
    constexpr int WORD_LENGTH = 5; //word length test condition

    std::cout << std::endl;
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << std::endl;

    std::cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?" << std::endl; //begin game by asking for a guess
    return;
}


//get a guess from the player
std::string GetGuess() {

    int CurrentTry = BCGame.GetCurrentTry();

    std::string Guess = "";
    std::cout << "Try: " << CurrentTry << ". Enter your guess: ";
    std::getline(std::cin, Guess);
    return Guess;
}


//loop for the number of GUESS_COUNT asking for guesses
void PlayGame() {

    BCGame.Reset();

    int MaxTries = BCGame.GetMaxTries();

    for (int i = 1; i <= MaxTries; i++) {
	   std::string Guess = GetGuess();
	   //repeat the guess back to them
	   std::cout << "You guessed: " + Guess + "\n" << std::endl;
    }
}

//Ask the user to play again
bool AskToPlayAgain() {
    std::cout << "Do you want to play again? \n";
    std::cout << "Type Yes or No to continue. ";
    std::string Response = "";
    std::getline(std::cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');
}

