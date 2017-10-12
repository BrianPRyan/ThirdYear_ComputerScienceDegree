/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#include "Enemy.h"

using namespace std;

Enemy::Enemy() 
{}

Enemy::~Enemy() 
{}

//Update function class
void Enemy::update()
{
	srand(time(NULL));
	int randomNumber = (rand() % 4) + 1;

	//Code to deal with enemy border collision
	switch (randomNumber)
	{
		case 1:
			if (m_y>0)
			{
				m_y--;
			}
			break;
		case 2:
			if (m_y<23)
			{
				m_y++;
			}
			break;
		case 3:
			if (m_x<23)
			{
				m_x++;
			}
			break;
		case 4:
			if (m_x>0)
			{
				m_x--;
			}
			break;
	}

	//Enemy health minus speed
	m_health = m_health - m_speed;
}

//hurt function 
int Enemy::hurt()
{
	return m_damage;
}

//differentiate between player/enemy
string Enemy::type()
{
	return m_type;
}
