/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#include "GameObject.h"

using namespace std;

//Spawn function
void GameObject::spawn(string typeID, int health, int speed,  int x, int y)
{
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;
};

//Drawn info function
void GameObject::draw()
{
	cout << "ID : " << m_typeID << "\t x : " << m_x << "\t y : " << m_y << "\tHealth: " << m_health << endl;
};

//Update virtual function
void GameObject::update()
{
	cout << "GameObject Virtual Update Function" << endl;
}

//Print Info on object
void GameObject::info()
{
	cout << "ID : " << m_typeID << "\t Health : " << m_health << "\t Speed : " << m_speed << "\t x : " << m_x << "\t y : " << m_y << endl;
};

//Check if alive
bool GameObject::isAlive()
{
	if (m_health>0)
		return true;
	else
		return false;
};

//get x value
int GameObject::getx()
{
	return m_x;
};

//get y value
int GameObject::gety()
{
	return m_y;
};

//hurt other object
int GameObject::hurt()
{
	return 0;
}

string GameObject::type()
{
	return string();
}

//set new health value
void GameObject::setHealth(int health)
{
	m_health = health;
}

//get current health value
int GameObject::getHealth()
{
	return m_health;
}
