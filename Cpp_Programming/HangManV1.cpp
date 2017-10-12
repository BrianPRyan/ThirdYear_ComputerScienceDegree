// Hangman
// The classic game of hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

char guess();
char getGuess();

int main()
{
    cout << "Welcome to Hangman.  Good luck!\n";

	char guess();
	char getGuess();

    return 0;
}

char guess()
{
	vector<string> words;  // collection of possible words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");


	srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
	const int MAX_WRONG = 8;
	int wrong = 0; 
	const string THE_WORD = words[0];
	string soFar(THE_WORD.size(), '-');
	string used = "";

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); //make uppercase since secret word in uppercase
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;
		    
	if (wrong == MAX_WRONG)
        cout << "\nYou've been hanged!";
    else
        cout << "\nYou guessed it!";
    
    cout << "\nThe word was " << THE_WORD << endl;

		return guess;
	}
}
	
char getGuess()
{
		char getGuess;
		
	vector<string> words;  // collection of possible words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
	const string THE_WORD = words[0];
	int wrong = 0; 
	string soFar(THE_WORD.size(), '-');

        if (THE_WORD.find(getGuess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";

            // update soFar to include newly guessed letter
            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
			{
                if (THE_WORD[i] == getGuess)
				{
                    soFar[i] = getGuess;
				}
			}
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
  	return getGuess;
}  

