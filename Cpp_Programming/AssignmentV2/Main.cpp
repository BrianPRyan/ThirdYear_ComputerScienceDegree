//Brian Ryan.. CA2 Assignment.. 29/11/2016

//Included libraries & header files
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include "TitleScreen.h"
#include "StoryScreen.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <mmsystem.h>

#define _WIN32_WINNT 0x0500

//Clear console 
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

//Using namespace std
using namespace std;

//Main function
int main()
{
	//Set screen size
	{
		//Make window a specific size
		SMALL_RECT rect;
		COORD coord;
		coord.X = 140; //Defining X coloumns
		coord.Y = 50;  //Y rows
		rect.Top = 0;
		rect.Left = 0;
		rect.Bottom = coord.Y - 1; //height for window
		rect.Right = coord.X - 1;  //width for window
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); //get handle
		SetConsoleScreenBufferSize(hwnd, coord);       //set buffer size
		SetConsoleWindowInfo(hwnd, TRUE, &rect);       //set window size
	}

	//Call title screen 
	TitleScreen newTitleScreen;
	newTitleScreen.Screen();

	//pause title screen for 5 seconds
	Sleep(5000);
	ClearScreen();//Call clear screen function

	//Call first story screen
	StoryScreen newStoryScreen;
	newStoryScreen.Story();

	//pause story screen for 12 seconds
	Sleep(12000);
	ClearScreen();//Call clear screen function

	//Call Game level 1 and game init function to create first level and map, spawn enemys and treasure
	Game game(1);
	game.init(1);

	//Set breaker to 1, this int is used as a means to finish level
	int breaker = 1;

	//Game Level1
	while (breaker != 0)//while breaker not equal to zero we implement the functions below
	{
		game.draw(1);

		game.update();

		game.battle();

		game.clean();

		//When getTreasure is equal to zero on the level
		if (game.getTreasure() == 0)
			breaker = 0;//breaker gets set to zero so the loop concludes
		ClearScreen();

	}//End of game loop

	ClearScreen();

	//Call second story screen
	StoryScreen newStoryScreenTwo;
	newStoryScreenTwo.StoryTwo();

	//pause story screen for 10 seconds
	Sleep(10000);
	ClearScreen();//Call clear screen function
	
	//Call Game level 2 and game init function to create first level and map, spawn enemys and treasure
	Game twogame(2);
	twogame.init(2);

	//Set breaker to 1, this int is used as a means to finish level
	breaker = 1;

	//Game Level2
	while (breaker != 0)//while breaker not equal to zero we implement the functions below
	{
		twogame.draw(2);

		twogame.update();

		twogame.battle();

		twogame.clean();

		//When getTreasure is equal to zero on the level
		if (twogame.getTreasure() == 0)
			breaker = 0;//breaker gets set to zero so the loop concludes
		ClearScreen();
	}//End of game loop

	ClearScreen();

	//Call third story screen
	StoryScreen newStoryScreenThree;
	newStoryScreenThree.StoryThree();

	Sleep(10000);
	ClearScreen();
	
	//Call Game level 3 and game init function to create first level and map, spawn enemys and treasure
	Game threegame(3);
	threegame.init(3);

	//Set breaker to 1, this int is used as a means to finish level
	breaker = 1;

	//Game Level3
	while (breaker != 0)
	{
		threegame.draw(3);

		threegame.update();

		threegame.battle();

		threegame.clean();

		//When getTreasure is equal to zero on the level
		if (threegame.getTreasure() == 0)
			breaker = 0;//breaker gets set to zero so the loop concludes
		ClearScreen();
	}//End of game loop

	ClearScreen();

	//Call fourth story screen
	StoryScreen newStoryScreenFour;
	newStoryScreenFour.StoryFour();

	Sleep(10000);
	ClearScreen();

	Sleep(5000);
	return 0;

}