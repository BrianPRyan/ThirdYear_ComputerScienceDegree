//Brian Ryan.. CA2 Assignment.. 29/11/2016

#include "Game.h"
//Using namespace std
using namespace std;

//Class Constructor
Game::Game() {}

//Class De Constructor
Game::~Game() {}

Game::Game(int level)
{
	if (level == 1)
	{
		//All our level one stuff gets initilized here
		P_Player = new Player();
		P_Enemy_1 = new Enemy();
		P_Enemy_2 = new Enemy();
		P_Enemy_3 = new Enemy();
		P_Enemy_4 = new Enemy();
		P_Treasure_1 = new Treasure();
		P_Treasure_2 = new Treasure();
		P_Treasure_3 = new Treasure();
		P_Treasure_4 = new Treasure();

		treasure_collection = 4;
	}
	else if (level == 2)
	{
		//All our level two stuff gets initilized here
		P_Player = new Player();
		P_Enemy_1 = new Enemy();
		P_Enemy_2 = new Enemy();
		P_Enemy_3 = new Enemy();
		P_Enemy_4 = new Enemy();
		P_Enemy_5 = new Enemy();
		P_Enemy_6 = new Enemy();
		P_Treasure_1 = new Treasure();
		P_Treasure_2 = new Treasure();
		P_Treasure_3 = new Treasure();
		P_Treasure_4 = new Treasure();
		P_Treasure_5 = new Treasure();
		P_Treasure_6 = new Treasure();

		treasure_collection = 6;
	}
	else if (level == 3)
	{
		//All our level three stuff gets initilized here
		P_Player = new Player();
		P_Enemy_1 = new Enemy();
		P_Enemy_2 = new Enemy();
		P_Enemy_3 = new Enemy();
		P_Enemy_4 = new Enemy();
		P_Enemy_5 = new Enemy();
		P_Enemy_6 = new Enemy();
		P_Enemy_7 = new Enemy();
		P_Enemy_8 = new Enemy();
		P_Enemy_9 = new Enemy();
		P_Enemy_10 = new Enemy();
		P_Treasure_1 = new Treasure();
		P_Treasure_2 = new Treasure();
		P_Treasure_3 = new Treasure();
		P_Treasure_4 = new Treasure();
		P_Treasure_5 = new Treasure();
		P_Treasure_6 = new Treasure();
		P_Treasure_7 = new Treasure();
		P_Treasure_8 = new Treasure();
		P_Treasure_9 = new Treasure();
		P_Treasure_10 = new Treasure();

		treasure_collection = 10;
	}
}

//Spawn objects and give them all unique place on map
void Game::init(int level)
{
	if (level == 1)
	{
		int randomInt;
		srand(time(NULL));
		int serielID = 1;

		int x;
		int y;
		for (y = 0; y <= 17; y++) { for (x = 0; x <= 17; x++) { array[y][x] = 0; } }
		//push objects onto list
		listOfObjects.push_back(P_Player);
		listOfObjects.push_back(P_Enemy_1);
		listOfObjects.push_back(P_Enemy_2);
		listOfObjects.push_back(P_Enemy_3);
		listOfObjects.push_back(P_Enemy_4);
		listOfObjects.push_back(P_Treasure_1);
		listOfObjects.push_back(P_Treasure_2);
		listOfObjects.push_back(P_Treasure_3);
		listOfObjects.push_back(P_Treasure_4);
		current_level = 1;

		//Give each item in list random unique place in map
		for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
		{
			do
			{
				x = (rand() % 17);
				y = (rand() % 17);
			} while (array[y][x] == 1);
			array[y][x] = 1;
			x++; y++;

			(*iter)->spawn(((*iter)->objectType() + ">" + to_string(serielID)), 100, 1, y, x);
			serielID++;
		}
	}

	else if (level == 2)
	{
		//All our level two INIT stuff gets initilized here
		int randomInt;
		srand(time(NULL));
		int serielID = 1;

		int x;
		int y;
		for (y = 0; y <= 22; y++) { for (x = 0; x <= 22; x++) { arrayLevel2[y][x] = 0; } }
		//push objects onto list
		listOfObjects.push_back(P_Player);
		listOfObjects.push_back(P_Enemy_1);
		listOfObjects.push_back(P_Enemy_2);
		listOfObjects.push_back(P_Enemy_3);
		listOfObjects.push_back(P_Enemy_4);
		listOfObjects.push_back(P_Enemy_5);
		listOfObjects.push_back(P_Enemy_6);
		listOfObjects.push_back(P_Treasure_1);
		listOfObjects.push_back(P_Treasure_2);
		listOfObjects.push_back(P_Treasure_3);
		listOfObjects.push_back(P_Treasure_4);
		listOfObjects.push_back(P_Treasure_5);
		listOfObjects.push_back(P_Treasure_6);
		current_level = 2;

		//Give each item in list random unique place in map
		for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
		{
			do
			{
				x = (rand() % 22);
				y = (rand() % 22);
			} while (arrayLevel2[y][x] == 1);
			arrayLevel2[y][x] = 1;
			x++; y++;

			(*iter)->spawn(((*iter)->objectType() + ">" + to_string(serielID)), 100, 1, y, x);
			serielID++;
		}
	}
	else if (level == 3)
	{
		//All our level three INIT stuff gets initilized here
		int randomInt;
		srand(time(NULL));
		int serielID = 1;

		int x;
		int y;
		for (y = 0; y <= 27; y++) { for (x = 0; x <= 27; x++) { arrayLevel3[y][x] = 0; } }
		//push objects onto list
		listOfObjects.push_back(P_Player);
		listOfObjects.push_back(P_Enemy_1);
		listOfObjects.push_back(P_Enemy_2);
		listOfObjects.push_back(P_Enemy_3);
		listOfObjects.push_back(P_Enemy_4);
		listOfObjects.push_back(P_Enemy_5);
		listOfObjects.push_back(P_Enemy_6);
		listOfObjects.push_back(P_Enemy_7);
		listOfObjects.push_back(P_Enemy_8);
		listOfObjects.push_back(P_Enemy_9);
		listOfObjects.push_back(P_Enemy_10);
		listOfObjects.push_back(P_Treasure_1);
		listOfObjects.push_back(P_Treasure_2);
		listOfObjects.push_back(P_Treasure_3);
		listOfObjects.push_back(P_Treasure_4);
		listOfObjects.push_back(P_Treasure_5);
		listOfObjects.push_back(P_Treasure_6);
		listOfObjects.push_back(P_Treasure_7);
		listOfObjects.push_back(P_Treasure_8);
		listOfObjects.push_back(P_Treasure_9);
		listOfObjects.push_back(P_Treasure_10);
		current_level = 3;

		//Give each item in list random unique place in map
		for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
		{
			do
			{
				x = (rand() % 27);
				y = (rand() % 27);
			} while (arrayLevel3[y][x] == 1);
			arrayLevel3[y][x] = 1;
			x++; y++;

			(*iter)->spawn(((*iter)->objectType() + ">" + to_string(serielID)), 100, 1, x, y);
			serielID++;
		}
	}

}

//Draw all game graphics, map, objects, info and more
void Game::draw(int level)
{
	if (level == 1)
	{
		//Information Displayed On HeadUpDisplay
		HeadUpDisplay[0] = "\tTreasure to be collected = " + (to_string(treasure_collection));
		HeadUpDisplay[1] = "\tPlayer  -> X : " + (to_string(P_Player->GameObject_X())) + "\tY : " + (to_string(P_Player->GameObject_Y())) + "\tHealth : " + (to_string(P_Player->getHealth()));
		HeadUpDisplay[2] = "\tEnemy 1 -> X : " + (to_string(P_Enemy_1->GameObject_X())) + "\tY : " + (to_string(P_Enemy_1->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_1->getHealth()));
		HeadUpDisplay[3] = "\tEnemy 2 -> X : " + (to_string(P_Enemy_2->GameObject_X())) + "\tY : " + (to_string(P_Enemy_2->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_2->getHealth()));
		HeadUpDisplay[4] = "\tEnemy 3 -> X : " + (to_string(P_Enemy_3->GameObject_X())) + "\tY : " + (to_string(P_Enemy_3->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_3->getHealth()));
		HeadUpDisplay[5] = "\tEnemy 4 -> X : " + (to_string(P_Enemy_4->GameObject_X())) + "\tY : " + (to_string(P_Enemy_4->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_4->getHealth()));
		HeadUpDisplay[6] = "           ";
		HeadUpDisplay[7] = "\t   Up = w";
		HeadUpDisplay[8] = "\t Down = s";
		HeadUpDisplay[9] = "\t Left = a";
		HeadUpDisplay[10] = "\tRight = d";

		//Asign epmty spaces to our entire virtual array
		for (y = 0; y <= 19; y++)
		{
			for (x = 0; x <= 19; x++)
			{
				virtualArray[y][x] = ' ';
			}
		}

		//Give all Objects a character for animation on Map
		for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
		{
			if (((*iter)->objectType()) == "player")
				virtualArray[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = 'P';
			else if (((*iter)->objectType()) == "treasure")
				virtualArray[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = '?';
			else
				virtualArray[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = 'E';

			(*iter)->draw();
		}

		//Draw map, HeadUpDisplay and all object to console using our virtual array
		for (y = 0; y <= 20; y++)
		{
			for (x = 0; x <= 20; x++)
			{
				if (x == 0 || x == 20 || y == 0 || y == 20)
					std::cout << setw(2) << "X";
				else
					std::cout << setw(2) << virtualArray[y][x];
			}
			if (y >= 10 && y <= 20)
				cout << HeadUpDisplay[y - 10];

			std::cout << std::endl;
		}
	}

	else if (level == 2)
	{
		//All our level two DRAW stuff gets initilized here
		//Information Displayed On HeadUpDisplay
		HeadUpDisplay2[0] = "\tTreasure to be collected = " + (to_string(treasure_collection));
		HeadUpDisplay2[1] = "\tPlayer  -> X : " + (to_string(P_Player->GameObject_X())) + "\tY : " + (to_string(P_Player->GameObject_Y())) + "\tHealth : " + (to_string(P_Player->getHealth()));
		HeadUpDisplay2[2] = "\tEnemy 1 -> X : " + (to_string(P_Enemy_1->GameObject_X())) + "\tY : " + (to_string(P_Enemy_1->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_1->getHealth()));
		HeadUpDisplay2[3] = "\tEnemy 2 -> X : " + (to_string(P_Enemy_2->GameObject_X())) + "\tY : " + (to_string(P_Enemy_2->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_2->getHealth()));
		HeadUpDisplay2[4] = "\tEnemy 3 -> X : " + (to_string(P_Enemy_3->GameObject_X())) + "\tY : " + (to_string(P_Enemy_3->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_3->getHealth()));
		HeadUpDisplay2[5] = "\tEnemy 4 -> X : " + (to_string(P_Enemy_4->GameObject_X())) + "\tY : " + (to_string(P_Enemy_4->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_4->getHealth()));
		HeadUpDisplay2[6] = "\tEnemy 5 -> X : " + (to_string(P_Enemy_5->GameObject_X())) + "\tY : " + (to_string(P_Enemy_5->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_5->getHealth()));
		HeadUpDisplay2[7] = "\tEnemy 6 -> X : " + (to_string(P_Enemy_6->GameObject_X())) + "\tY : " + (to_string(P_Enemy_6->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_6->getHealth()));
		HeadUpDisplay2[8] = "           ";
		HeadUpDisplay2[9] = "\t   Up = w";
		HeadUpDisplay2[10] = "\t Down = s";
		HeadUpDisplay2[11] = "\t Left = a";
		HeadUpDisplay2[12] = "\tRight = d";


		//Asign epmty spaces to our entire virtual array
		for (y = 0; y <= 24; y++)
		{
			for (x = 0; x <= 24; x++)
			{
				virtualArrayLevel2[y][x] = ' ';
			}
		}

		//Give all Objects a character for animation on Map
		for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
		{
			if (((*iter)->objectType()) == "player")
				virtualArrayLevel2[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = 'P';
			else if (((*iter)->objectType()) == "treasure")
				virtualArrayLevel2[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = '?';
			else
				virtualArrayLevel2[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = 'E';

			(*iter)->draw();
		}

		//Draw map, HeadUpDisplay and all object to console using our virtual array
		for (y = 0; y <= 25; y++)
		{
			for (x = 0; x <= 25; x++)
			{
				if (x == 0 || x == 25 || y == 0 || y == 25)
					std::cout << setw(2) << "X";
				else
					std::cout << setw(2) << virtualArrayLevel2[y][x];
			}
			if (y >= 12 && y <= 24)
				cout << HeadUpDisplay2[y - 12];

			std::cout << std::endl;
		}

	}
	else if (level == 3)
	{
		//All our level three DRAW stuff gets initilized here
		//Information Displayed On HeadUpDisplay
		HeadUpDisplay3[0] = "\tTreasure to be collected = " + (to_string(treasure_collection));
		HeadUpDisplay3[1] = "\tPlayer  -> X : " + (to_string(P_Player->GameObject_X())) + "\tY : " + (to_string(P_Player->GameObject_Y())) + "\tHealth : " + (to_string(P_Player->getHealth()));
		HeadUpDisplay3[2] = "\tEnemy 1 -> X : " + (to_string(P_Enemy_1->GameObject_X())) + "\tY : " + (to_string(P_Enemy_1->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_1->getHealth()));
		HeadUpDisplay3[3] = "\tEnemy 2 -> X : " + (to_string(P_Enemy_2->GameObject_X())) + "\tY : " + (to_string(P_Enemy_2->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_2->getHealth()));
		HeadUpDisplay3[4] = "\tEnemy 3 -> X : " + (to_string(P_Enemy_3->GameObject_X())) + "\tY : " + (to_string(P_Enemy_3->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_3->getHealth()));
		HeadUpDisplay3[5] = "\tEnemy 4 -> X : " + (to_string(P_Enemy_4->GameObject_X())) + "\tY : " + (to_string(P_Enemy_4->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_4->getHealth()));
		HeadUpDisplay3[6] = "\tEnemy 5 -> X : " + (to_string(P_Enemy_5->GameObject_X())) + "\tY : " + (to_string(P_Enemy_5->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_5->getHealth()));
		HeadUpDisplay3[7] = "\tEnemy 6 -> X : " + (to_string(P_Enemy_6->GameObject_X())) + "\tY : " + (to_string(P_Enemy_6->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_6->getHealth()));
		HeadUpDisplay3[8] = "\tEnemy 7 -> X : " + (to_string(P_Enemy_7->GameObject_X())) + "\tY : " + (to_string(P_Enemy_7->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_7->getHealth()));
		HeadUpDisplay3[9] = "\tEnemy 8 -> X : " + (to_string(P_Enemy_8->GameObject_X())) + "\tY : " + (to_string(P_Enemy_8->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_8->getHealth()));
		HeadUpDisplay3[10] = "\tEnemy 9 -> X : " + (to_string(P_Enemy_9->GameObject_X())) + "\tY : " + (to_string(P_Enemy_9->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_9->getHealth()));
		HeadUpDisplay3[11] = "\tEnemy 10 -> X : " + (to_string(P_Enemy_10->GameObject_X())) + "\tY : " + (to_string(P_Enemy_10->GameObject_Y())) + "\tHealth : " + (to_string(P_Enemy_10->getHealth()));
		HeadUpDisplay3[13] = "           ";
		HeadUpDisplay3[14] = "\t   Up = w";
		HeadUpDisplay3[15] = "\t Down = s";
		HeadUpDisplay3[16] = "\t Left = a";
		HeadUpDisplay3[17] = "\tRight = d";

		//Asign epmty spaces to our entire virtual array
		for (y = 0; y <= 29; y++)
		{
			for (x = 0; x <= 29; x++)
			{
				virtualArrayLevel2[y][x] = ' ';
			}

		}

		//Give all Objects a character for animation on Map
		for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
		{
			if (((*iter)->objectType()) == "player")
				virtualArrayLevel2[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = 'P';
			else if (((*iter)->objectType()) == "treasure")
				virtualArrayLevel2[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = '?';
			else
				virtualArrayLevel2[(*iter)->GameObject_Y()][(*iter)->GameObject_X()] = 'E';

			(*iter)->draw();
		}

		//Draw map, HeadUpDisplay and all object to console using our virtual array
		for (y = 0; y <= 30; y++)
		{
			for (x = 0; x <= 30; x++)
			{
				if (x == 0 || x == 30 || y == 0 || y == 30)
					std::cout << setw(2) << "X";
				else
					std::cout << setw(2) << virtualArrayLevel2[y][x];
			}
			if (y >= 10 && y <30)
				cout << HeadUpDisplay3[y-10];

			std::cout << std::endl;
		}
	}
}

//Call update function for all objects which controls there movement, health, and speed
void Game::update()
{

	//Call all objects update fucntion by jumping past virtual GameObject jumping function
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		(*iter)->update(current_level);
	}
}

//If objects hold the same ground call damage function and modify objects health
void Game::battle()
{
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		for (iter2 = listOfObjects.begin(); iter2 != listOfObjects.end(); iter2++)
		{
			if ((*iter)->objectType() != (*iter2)->objectType())
			{
				if ((*iter)->GameObject_X() == (*iter2)->GameObject_X() && (*iter)->GameObject_Y() == (*iter2)->GameObject_Y())
				{
					if ((*iter)->objectType() == "player" && (*iter2)->objectType() == "treasure")//checking if player and treasure hold the same coordinates
					{
						(*iter2)->setHealth(0);
						treasure_collection = treasure_collection - 1;
					}
					else
					{
						(*iter)->setHealth((*iter)->getHealth() - (*iter2)->giveDamage());
						(*iter2)->setHealth((*iter2)->getHealth() - (*iter)->giveDamage());
						if ((*iter)->getHealth() < 0)
							(*iter)->setHealth(0);
						if ((*iter2)->getHealth() < 0)
							(*iter2)->setHealth(0);
					}
				}
			}
		}
	}
}

//Call all objects info function, displaying all info on screen
void Game::info()
{
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		(*iter)->info();
	}
	Sleep(1000);
}

//If any objects have less than 1 health , they are removed from list
void Game::clean()
{
	string deleteID;

	for (iter = listOfObjects.begin(); iter != listOfObjects.end();)
	{
		if (((*iter)->isAlive()) == false)
			iter = listOfObjects.erase(iter);
		else
			++iter;
	}
}

int Game::getTreasure()
{
	return treasure_collection;
}
