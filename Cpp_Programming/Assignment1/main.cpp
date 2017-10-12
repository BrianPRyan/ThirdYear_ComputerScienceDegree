/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "******NEW GAME******\n" << endl;
	cout << "**********************\n" << endl;
	int loop;
	int end;
	Game game;
	game.init();

	//Game Loop
	for (loop=0; loop<=20; loop++)
	{
		game.draw();
		game.update();
		game.battle();
		game.info();
		game.clean();

	}//End of game loop

	game.info();

	cout << "\n******Game Over******\n" << endl;

	cin >> end;
	return 0;

}