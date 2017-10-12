/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#ifndef GAME_H
#define GAME_H
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "windows.h"
#include <list>
#include <time.h>
#include <array>
#include <string>
#include <iostream>
using namespace std;

class Game
{
public:
	//Public Variables
	Game();
	~Game();
	void init();
	void draw();
	void update();
	void battle();
	void info();
	void clean();


private:
	//Private Variables
	int array[23][23];

	//Game Objects
	GameObject* player1 = new Player();
	GameObject* enemy1 = new Enemy();
	GameObject* enemy2 = new Enemy();
	GameObject* enemy3 = new Enemy();
	GameObject* enemy4 = new Enemy();

	//List and iterator
	list <GameObject*> listOfObjects;
	list <GameObject*>::iterator iter;
	list <GameObject*>::iterator iter2;
};
#endif