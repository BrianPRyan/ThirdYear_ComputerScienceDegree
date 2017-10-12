#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	int number, randomNumber;
	int allNumbers[6] = {0,0,0,0,0,0}; //initialise numbers to zero

	srand(static_cast<unsigned int>(time(0)));  // seed random number generator based on current time

	for (int i = 1; i <= 6; ++i)
	{
		randomNumber = rand(); // generate random number
		number = (randomNumber % 47) + 1; // get a number between 1 and 47
		allNumbers[i-1]=number; //add the number to the array

	}
	
	for(int i = 0; i < 6; ++i)
	{
		cout << "Number " << i+1 << ": " << allNumbers[i] << endl;
	}
	    
	return 0;
}
