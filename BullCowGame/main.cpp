#include <iostream>
#include <string>


using namespace std;


//functions list / PROTOTYPES
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


//MAIN
int main() {

    PrintIntro();

    PlayGame();

    AskToPlayAgain();

    cout << AskToPlayAgain();

    return 0;
}



//   METHODS & FUNCTIONS	  METHODS & FUNCTIONS    METHODS & FUNCTIONS	  METHODS & FUNCTIONS	  METHODS & FUNCTIONS    METHODS & FUNCTIONS	METHODS & FUNCTIONS	  METHODS & FUNCTIONS    METHODS & FUNCTIONS


    //introduce the game
void PrintIntro() {
    constexpr int WORD_LENGTH = 5; //word length test condition

    cout << "Welcome to Bulls and Cows, a fun word game." << endl;
    cout << endl;

    cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?" << endl; //begin game by asking for a guess
    return;
}


//get a guess from the player
string GetGuess() {
    string Guess = "";
    cout << "What is your guess? ";
    getline(cin, Guess);
    return Guess;
}


//loop for the number of GUESS_COUNT asking for guesses
void PlayGame() {
    constexpr int GUESS_COUNT = 5;
    for (int i = 1; i <= GUESS_COUNT; i++) {
	   string Guess = GetGuess();
	   //repeat the guess back to them
	   cout << "You guessed: " + Guess + "\n" << endl;
    }
}

//Ask the user to play again
bool AskToPlayAgain() {
    cout << "Do you want to play again? \n";
    cout << "Type Yes or No to continue. ";
    string Response = "";
    getline(cin, Response);

    return (Response[0] == 'y') || (Response[0] == 'Y');
}