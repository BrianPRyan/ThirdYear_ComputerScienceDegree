#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
		
	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

	srand(static_cast<unsigned int>(time(0))); //seed random number generator based on current time

	int randomNumber = rand ();		//generate random number

	cout << "\n\n---------------------\n\n";

	int dice1 = rand() % 10+1; //random number between 1 & 10
		
	if (dice1 == 10)	//error handling for first dice
	{
		dice1 = 0;
	}

	SetConsoleTextAttribute( hstdout, 0x04 ); //set colour of dice 1 to red
	cout << "\n\nDice 1: You rolled a " << dice1 << endl; //output of number rolled on dice


	int dice2 = rand() % 10+1; //random number between 1 & 10

	SetConsoleTextAttribute( hstdout, 0x02 ); //set colour of dice 2 to green
	cout << "\n\nDice 2: You rolled a " << dice2 << endl; //output of number rolled on dice

	int result = (dice1 * 10 + dice2); //calculation to give result

	SetConsoleTextAttribute( hstdout, 0xF ); //set colour back to white
	cout << "\n\nYour result is: " << result << endl; //output of result

	cout << "\n\n---------------------\n\n";

	FlushConsoleInputBuffer( hstdin );

	//Keep users happy
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	//cin.get();
	return 0;
}
