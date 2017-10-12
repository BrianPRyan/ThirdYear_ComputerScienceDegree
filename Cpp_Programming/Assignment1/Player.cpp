/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#include "Player.h"
#include <time.h>

using namespace std;

Player::Player()
{}

Player::~Player()
{}

//player input and update
void Player::update()
{
	char c = ' ';

	do
	{
		cout << "\nEnter w, d, s or a : ";
		cin >> c;
	} while (c != 's' && c != 'd' && c != 'w' && c != 'a');
	
	//Move player and control boundaries
	switch (c)
	{

	case 'w':
		if (m_y>0)
		{
			m_y--;
		}
		break;
	case 's':
		if (m_y<23)
		{
			m_y++;
		}
		break;
	case 'd':
		if (m_x<23)
		{
			m_x++;
		}
		break;
	case 'a':
		if (m_x>0)
		{
			m_x--;
		}
		break;
	}//End of switch statement

	//Take speed from health
	m_health = m_health - m_speed;
}

//hurt enemy 
int Player::hurt()
{
	return m_damage;
}

//differentiate between player/enemy
string Player::type()
{
	return m_type;
}