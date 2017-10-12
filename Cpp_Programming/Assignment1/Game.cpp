/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#include "Game.h"

Game::Game()
{}
Game::~Game()
{}

void Game::init()
{
	//Variables for function
	int ID = 1;
	int x;
	int y;

	//Make Empty Array
	for (y = 0; y <= 22; y++) 
	{ 
		for (x = 0; x <= 22; x++)
		{ 
			array[y][x] = 0; 
		} 
	}

	//cout << "Items Start Adding" << endl;

	//Add objects to list  
	listOfObjects.push_back(player1);
	listOfObjects.push_back(enemy1);
	listOfObjects.push_back(enemy2);
	listOfObjects.push_back(enemy3);
	listOfObjects.push_back(enemy4);

	//cout << "Items Added" << endl;

	//Give each item in list random unique place in map
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		do
		{
			x = (rand() % 22)+1;
			y = (rand() % 22)+1;
		}while (array[y][x] == 1);


		(*iter)->spawn(to_string(ID), 160, 1, y, x);
		ID = ID + 1;
	}

	//cout << "Init Function Complete" << endl;
}

void Game::draw()
{

	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		(*iter)->draw();
	}
	//cout << "\nDraw Function Complete" << endl;
}

void Game::update()
{
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		(*iter)->update();
	}
	cout << "\nUpdate Function Complete" << endl;
}

void Game::battle()
{
	//Check first list of objects against second list of objects
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		for (iter2 = listOfObjects.begin(); iter2 != listOfObjects.end(); iter2++)
		{
			//if x and y are same we change health of both
			if ((*iter)->getx() == (*iter2)->getx() && (*iter)->gety() == (*iter2)->gety() && (!((*iter)->type() == (*iter2)->type())))
			{
				(*iter)->setHealth((*iter)->getHealth() - (*iter2)->hurt());
				(*iter2)->setHealth((*iter2)->getHealth() - (*iter)->hurt());

			}
		}
	}

	//cout << "Battle Function Complete\n" << endl;
}

void Game::info()
{
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		(*iter)->info();
	}
	cout << "\nInfo Function Complete" << endl;
}

void Game::clean()
{
	string deleteID;

	//checking list to see if objects are alive, if health is above zero
	for (iter = listOfObjects.begin(); iter != listOfObjects.end();)
	{
		if (((*iter)->isAlive()) == false)
			iter = listOfObjects.erase(iter);
		else
			++iter;
	}
	//cout << "Clean Function Complete\n" << endl;
}
