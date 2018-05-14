#include <iostream>
#include <string>

using namespace std;

//functions list
void PrintIntro();
string GetGuessAndPrint();


//entry point
int main() {

    PrintIntro();

    GetGuessAndPrint();

    return 0;
}


//introduce the game
void PrintIntro() {
    constexpr int WORD_LENGTH = 5; //word length test condition

    //text
    cout << "Welcome to Bulls and Cows, a fun word game." << endl;
    cout << endl;
    //begin game by asking for a guess
    cout << "Can you guess the " << WORD_LENGTH << " letter word I'm thinking of?" << endl;
    return;
}

//get a guess from the player
string GetGuessAndPrint() {
    string Guess = "";
    cout << "What is your guess? ";
    getline(cin, Guess);
    cout << endl;

    //repeat the guess back to them
    cout << "You guessed: " + Guess + "\n" << endl;
    return Guess;
}