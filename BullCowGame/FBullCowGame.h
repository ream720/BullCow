
#pragma once
#include <string>


using FString = std::string;
using int32 = int;



class FBullCowGame {
public:

    FBullCowGame(); //constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //todo richer return value
    bool CheckGuessValidity(FString);
    //TODO make methods for counting bull and cows, and increment turn number

private:

    //see constructor for initialization 
    int32 MyCurrentTry;
    int32 MyMaxTries;
};