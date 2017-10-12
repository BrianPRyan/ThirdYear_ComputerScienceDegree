//Brian Ryan.. CA2 Assignment.. 29/11/2016

//Include Enemy Header
#include "Enemy.h"

//Using namespace std
using namespace std;

//Enemy constructor
Enemy::Enemy() {}

//Enemy De Constructor
Enemy::~Enemy() {}

//Update enemy position with random movement, boundary control
void Enemy::update(int level)
{
	if (level == 1)//if level = 1 set boundaries for x and y
	{
		boundaryX = 24;
		boundaryY = 24;
	}
	else if (level == 2)//if level = 2 set boundaries for x and y
	{
		boundaryX = 34;
		boundaryY = 34;
	}
	else if (level == 3)//if level = 3 set boundaries for x and y
	{
		boundaryX = 34;
		boundaryY = 34;
	}
	//random function to set case for enemy movement
	srand(time(NULL));
	int x;
	int randomNumber = (rand() % 4) + 1;

	//Code to deal with enemy border collision
	switch (randomNumber)
	{
		//Case Up
	case 1:
	{
		for (x = m_speed; x > 0; --x)
		{
			if (m_y > 1)
				m_y--;
			else
				m_y = m_y + x;
			x = 0;
		}
	}
	break;

	//Case Right
	case 2:
	{
		for (x = m_speed; x > 0; --x)
		{
			if (m_x < boundaryX)
				m_x++;
			else
				m_x = m_x - x;
			x = 0;
		}
	}
	break;

	//Case Down
	case 3:
	{
		for (x = m_speed; x > 0; --x)
		{
			if (m_y < boundaryY)
				m_y++;
			else
				m_y = m_y - x;
			x = 0;
		}
	}
	break;

	//Case Left
	case 4:
	{
		for (x = m_speed; x > 0; --x)
		{
			if (m_x > 1)
				m_y--;
			else
				m_x = m_x + x;
			x = 0;
		}
	}
	break;

	//Case Error
	default:
		cout << "Enemy Switch Update Error" << endl;

	}

	//Remove Health by value of it's Speed
	m_health = m_health - m_speed;
}

//Return enemy damage value
int Enemy::giveDamage()
{
	srand(time(NULL));

	m_damage = rand() % 50;

	return m_damage;
}

//Return Object type enemy
string Enemy::objectType()
{
	m_type = "enemy";
	return m_type;
}
