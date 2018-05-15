#pragma once
#include <string>



class FBullCowGame {
public:

    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //todo richer return value
    bool CheckGuessValidity(std::string);


private:

    int MyCurrentTry = 1;
    int MyMaxTries = 5;
};