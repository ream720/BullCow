#pragma once
#include <string>



class FBullCowGame {
public:
    void Reset(); //todo richer return value
    int GetMaxTries();
    int GetCurrentTry();
    bool IsGameWon();
    bool CheckGuessValidity(std::string);

private:
    int MyCurrentTry = 1;
    int MyMaxTries = 5;
};