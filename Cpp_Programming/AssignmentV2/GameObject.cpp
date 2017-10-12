//Brian Ryan.. CA2 Assignment.. 29/11/2016

//Include GameObject Header
#include "GameObject.h"

//Using namespace std
using namespace std;

GameObject::GameObject()
{
	alive = true;
}

GameObject::~GameObject()
{
}

//Spawn function gives object a set of needed variable values
void GameObject::spawn(string typeID, int health, int speed, int x, int y)
{
	m_typeID = typeID;
	m_health = health;
	m_speed = speed;
	m_x = x;
	m_y = y;
};

//Draw ID, X and Y coordinates
void GameObject::draw()
{
	//cout << "Object ID : " << m_typeID << "\t X : " << m_x << "\t Y : " << m_y << endl;
};

//Return X value for object
int GameObject::GameObject_X()
{
	return m_x;
};

//return y value for object
int GameObject::GameObject_Y()
{
	return m_y;
};

//Set x value for game object
void GameObject::setGameObject_X(int x)
{
	m_x = x;
};

//Set y value for game object
void GameObject::setGameObject_Y(int y)
{
	m_y = y;
};

//Retun objects health
int GameObject::getHealth()
{
	return m_health;
}

//Virtual function to give damage when on same coordinates
int GameObject::giveDamage()
{
	return 0;
}

//Set objects health
void GameObject::setHealth(int health)
{
	m_health = health;
}

//Return object ID 
string GameObject::typeID()
{
	return m_typeID;
}

//Set objects speed
void GameObject::setSpeed(int speed)
{
	m_speed = speed;
}

//Virtual function for controlling enemy and player movements
void GameObject::update(int level)
{
	//cout << "GameObject Virtual Update Function" << endl;
}

//Return enemy type , virtual function
string GameObject::objectType()
{
	return string();
};

//Prints all objects information
void GameObject::info()
{
	/*cout << "Object ID : " << m_typeID << "\t Health : " << m_health << "\t Speed : " << m_speed << "\t X : " << m_x << "\t Y : " << m_y;

	if (m_health>0)
	cout << "\tAlive" << endl;
	else
	cout << "\tDead" << endl;*/

};

//Checks health and returns alive or dead
bool GameObject::isAlive()
{
	if (m_health>0)
		return true;
	else
		return false;
};

