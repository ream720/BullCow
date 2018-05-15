#pragma once
#include <string>



class FBullCowGame {
public:
    FBullCowGame(); //constructor

    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //todo richer return value
    bool CheckGuessValidity(std::string);


private:

    //see constructor for initialization 
    int MyCurrentTry;
    int MyMaxTries;
};