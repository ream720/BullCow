
#include "FBullCowGame.h"


using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame() { Reset(); }


int32 FBullCowGame::GetMaxTries()		const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry()	const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon()		const { return bGameIsWon; }



void FBullCowGame::Reset(){
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;

    return;
}





EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (false) { //if the guess isn't an isogram
	   return EGuessStatus::NOT_ISOGRAM;

    } else if (false) { //if the guess isn't lowercase
	   return EGuessStatus::NOT_LOWERCASE;

    } else if (Guess.length() != GetHiddenWordLength()) {    //if the guess length is wrong
	   return EGuessStatus::WRONG_LENGTH;

    } else {    //otherwise 
	   return EGuessStatus::OK;
    }
}



FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

    //increment turn number, setup return var, loop thru all letters in guess
    MyCurrentTry++;
    FBullCowCount BullCowCount;

	   //compare letters against the hidden word
    //loop through all letters in guess
    int32 WordLength = MyHiddenWord.length(); //assuming same length as guess
    for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {

	   //compare letters against hidden word
	   for (int32 GChar = 0; GChar < WordLength; GChar++) {

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
    if (BullCowCount.Bulls == WordLength) {
	   bGameIsWon = true;

    } else {
	   bGameIsWon = false;

    }
   return BullCowCount;
}