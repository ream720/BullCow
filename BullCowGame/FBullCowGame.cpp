/*
    C++ file for BullCowGame where methods/functions are defined.

*/

#pragma once

#include "FBullCowGame.h"
#include <map>

#define TMap std::map	   //to make syntax UnrealEngine 4 friendly 
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry()	const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon()		const { return bGameIsWon; }



int32 FBullCowGame::GetMaxTries()	const {
    TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}


void FBullCowGame::Reset(){

    const FString HIDDEN_WORD = "plan"; //this MUST be an isogram
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
    bGameIsWon = false;

    return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (!IsIsogram(Guess)) { //if the guess isn't an isogram
	   return EGuessStatus::NOT_ISOGRAM;

    } else if (!IsLowercase(Guess)) { //if the guess isn't lowercase
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


bool FBullCowGame::IsIsogram(FString Word) const {

    //treat 0 and 1 letter words as isograms
    if (Word.length() <= 1) { return true; }

    TMap<char, bool> LetterSeen; //set up map

	  for (auto Letter : Word) { //for all letters of the word

	   Letter = tolower(Letter); //make all letters lowercase
		if (LetterSeen[Letter]) { //check if letter is in map
			 return false; //not isogram

		} else {    
		  LetterSeen[Letter] = true;
		}
		 return true;
	  }
}


bool FBullCowGame::IsLowercase(FString Word) const {
    for (auto Letter : Word) {

	   //if not a lowercase letter
	   if (!islower(Letter)) {
		  return false;
	   }
    }
    //otherwise 
    return true;
}
