
#pragma once
#include <string>


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


    void Reset(); //todo richer return value
    
    FBullCowCount SubmitValidGuess(FString);


private:

    //see constructor for initialization 
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bGameIsWon;

    bool IsIsogram(FString) const;
};