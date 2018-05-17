
/*
    Header file for BullCowGame where objects are defined.

    Game logic (no view code or direct user interaction) 
    -simple word-guessing game based on "Mastermind"
*/

#pragma once

#include <string>

//to make syntax UnrealEngine 4 friendly
using FString = std::string;
using int32 = int;



enum class EGuessStatus {
    INVALID_STATUS,
    OK, 
    NOT_ISOGRAM,
    WRONG_LENGTH,
    NOT_LOWERCASE,
};


struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};


class FBullCowGame {
public:

    FBullCowGame(); //constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;

    void Reset();
    
    FBullCowCount SubmitValidGuess(FString);


private:

    //see constructor for initialization 
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;

    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};