
#include "FBullCowGame.h"


using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame() { Reset(); }


int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }



void FBullCowGame::Reset(){
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;

    return;
}


bool FBullCowGame::IsGameWon() const {
    return false;
}


bool FBullCowGame::CheckGuessValidity(FString) const {
    return false;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    //recieved valid guess -

    //increments turn -
    MyCurrentTry++;

    //returns count
    FBullCowCount BullCowCount;

    //increment turn number, setup return var, loop thru all letters in guess
	   //compare letters against the hidden word

    //loop through all letters in guess
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {

	   //compare letters against hidden word
	   for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {

		  //if they match, then
		  if (Guess[GChar] == MyHiddenWord[HWChar]) {

			 //if they're in the same "place"
			 if (HWChar == GChar) {
				BullCowCount.Bulls++;   //increment bulls
			 }
			 else {
				BullCowCount.Cows++;    //must be a cow, increment
			 }
		  }
	   }
    }

    return BullCowCount;
}