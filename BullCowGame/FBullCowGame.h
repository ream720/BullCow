
#pragma once
#include <string>


using FString = std::string;
using int32 = int;



enum class EWordStatus {
    OK, 
    NOT_ISOGRAM
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
    EWordStatus CheckGuessValidity(FString) const;

    void Reset(); //todo richer return value
    

    FBullCowCount SubmitGuess(FString);

private:

    //see constructor for initialization 
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};