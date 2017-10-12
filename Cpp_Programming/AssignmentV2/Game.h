//Brian Ryan.. CA2 Assignment.. 29/11/2016

#ifndef GAME_H
#define GAME_H

//Included headers of classes
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Treasure.h"
#include <Windows.h>
#include <Iomanip>

//Included libraries
#include <list>
#include <cstdlib>
#include <conio.h>
#include <array>
#include <time.h>
#include <string>
#include <iostream>

//Using namespace std
using namespace std;

//Class Game
class Game
{
	//public functions for Game
public:
	Game();
	~Game();
	Game(int level);
	void init(int level);
	void draw(int level);
	void update();
	void battle();
	void info();
	void clean();
	int getTreasure();
	int current_level;

protected:
	char c = ' ';
	char virtualArray[20][20];
	int array[18][18];

	char virtualArrayLevel2[25][25];
	int arrayLevel2[23][23];

	char virtualArrayLevel3[30][30];
	int arrayLevel3[28][28];

	char playerCharacter = 'P';
	char enemyCharacter = 'E';
	int x = 0;
	int y = 0;
	int end = 0;
	int ObjectX = 10;
	int ObjectY = 10;
	int speedControl = 1;
	int speed = 1;
	int treasure_collection;

	string HeadUpDisplay[12];
	string HeadUpDisplay2[13];
	string HeadUpDisplay3[20];

	list <GameObject*> listOfObjects;
	list <GameObject*>::iterator iter;
	list <GameObject*>::iterator iter2;

	GameObject* P_Player;
	GameObject* P_Enemy_1;
	GameObject* P_Enemy_2;
	GameObject* P_Enemy_3;
	GameObject* P_Enemy_4;
	GameObject* P_Enemy_5;
	GameObject* P_Enemy_6;
	GameObject* P_Enemy_7;
	GameObject* P_Enemy_8;
	GameObject* P_Enemy_9;
	GameObject* P_Enemy_10;

	GameObject* P_Treasure_1;
	GameObject* P_Treasure_2;
	GameObject* P_Treasure_3;
	GameObject* P_Treasure_4;
	GameObject* P_Treasure_5;
	GameObject* P_Treasure_6;
	GameObject* P_Treasure_7;
	GameObject* P_Treasure_8;
	GameObject* P_Treasure_9;
	GameObject* P_Treasure_10;
};
#endif
