#include <iostream>
#include <string>
#include "FBullCowGame.h";

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;

// the entry point of out application
int32 main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);

	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 count = 1; count <= NUMBER_OF_TURNS; count++) {
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


// get a guess from the player
FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << "Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

// introduce the game
void PrintIntro() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "The words length is " << WORD_LENGTH << "\n";
	std::cout << "Can you guess de X letter isogram I'm thinking of?\n";
	std::cout << std::endl;

}