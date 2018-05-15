
#pragma once
#include <string>


using FString = std::string;
using int32 = int;



struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};


class FBullCowGame {
public:

    FBullCowGame(); //constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //todo richer return value
    bool CheckGuessValidity(FString);

    FBullCowCount SubmitGuess(FString);

private:

    //see constructor for initialization 
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};