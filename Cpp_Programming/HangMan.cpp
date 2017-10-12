#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

//declare variables
char getPlayersGuess();
//declare functions
void elseFunction(char, int* pWrong);
void isGuessInWord(char guess, string* pTheWord, string *pSoFar, int* pWrong);

int main()
{
	const int MAX_WRONG = 8; 	// Max number of incorrect guesses allowed
	string used = ""; 			// letters already guessed
	
	vector<string> words; 		// Collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	
	srand(static_cast<unsigned int>(time(0)));//random seed generator
	random_shuffle(words.begin(), words.end());//random word chosen
	string THE_WORD = words[0]; 		// word to guess
	int wrong = 0; 						// number of incorrect guesses
	string soFar(THE_WORD.size(), '-'); // word guessed so far
	
	cout << "Welcome to Hangman. Good luck!" << endl;
	
	
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))//game loop
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;
		
		char guess = getPlayersGuess();
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			getPlayersGuess();
		}
		used += guess;
		isGuessInWord(guess, &THE_WORD, &soFar, &wrong);
	}
	
	if (wrong == MAX_WRONG) cout << "\nYou've been hanged!";
	else cout << "\nYou guessed it!";
	
	cout << "\nThe word was " << THE_WORD << endl;
		
	return 0;
}

// Function 1: Get The Players Guess
char getPlayersGuess()
{
	char playerGuess;
	cout << "\n\nPlease Enter Your Guess: ";
	cin >> playerGuess;
	playerGuess = toupper(playerGuess);//convert playerGuess to uppercase
	
	return playerGuess;
}

// Function 2: Determine if guess is in secret word
void isGuessInWord(char guess, string* pTheWord, string *pSoFar, int* pWrong)
{
	if ((*pTheWord).find(guess) != string::npos)
	{
		cout << "That's right! " << guess << " is in the word.\n";
		
		for (int i = 0; i < pTheWord->length(); ++i)
		{
			if ((*pTheWord)[i] == guess) (*pSoFar)[i] = guess;
		}
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		++(*pWrong);
	}
}
