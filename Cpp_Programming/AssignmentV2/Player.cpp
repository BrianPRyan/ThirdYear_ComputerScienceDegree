//Brian Ryan.. CA2 Assignment.. 29/11/2016

//Include library and header
#include "Player.h"
#include <time.h>

//Using namespace std
using namespace std;

//Player constructor
Player::Player() {}

//Player De Constructor
Player::~Player() {}

//Player update movement via user input, boundary control
void Player::update(int level)
{
	//if level = 1 set boundaries for x and y
	if (level == 1)
	{
		boundaryX = 24;
		boundaryY = 24;
	}//if level = 2 set boundaries for x and y
	else if (level == 2)
	{
		boundaryX = 34;
		boundaryY = 34;
	}
	else if (level == 3)//if level = 3 set boundaries for x and y
	{
		boundaryX = 34;
		boundaryY = 34;
	}

	int x;
	char c = ' ';

	do
	{
		cout << "\nTake your turn, choose direction & press return : ";
		cin >> c;
	} while (c != 'w' && c != 'a' && c != 's' && c != 'd');//take in user key press for movement

	//Move player and control boundaries
	switch (c)
	{

	case 'w':
		for (x = m_speed; x > 0; x--)
		{
			if (m_y >= 2)
			{
				m_y--;
			}
			else
			{
				m_y = m_y + x;
				x = 0;
			}
		}
		break;

	case 's':
		for (x = m_speed; x >0; x--)
		{
			if (m_y <= boundaryY)
			{
				m_y++;
			}
			else
			{
				m_y = m_y - x;
				x = 0;
			}
		}
		break;

	case 'a':
		for (x = m_speed; x >0; x--)
		{
			if (m_x >= 2)
			{
				m_x--;
			}
			else
			{
				m_x = m_x + x;
				x = 0;
			}
		}
		break;

	case 'd':
		for (x = m_speed; x >0; x--)
		{
			if (m_x <= boundaryX)
			{
				m_x++;
			}
			else
			{
				m_x = m_x - x;
				x = 0;
			}
		}
		break;

	default:
		cout << "Error Switch Player Update" << endl;
		break;

	}//End of switch statement

	m_health = m_health - m_speed;
}

//Return Player damage 
int Player::giveDamage()
{
	srand(time(NULL));

	m_damage = rand() % 100;

	return m_damage;
}

//Return player object type
string Player::objectType()
{
	m_type = "player";
	return m_type;
}
