//Brian Ryan.. CA2 Assignment.. 29/11/2016

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//Included libraries
#include <iostream>
#include <string>
#include <list>

//Using namespace std
using namespace std;

//Class GameObject
class GameObject
{
	//Public Functions for GameObject
public:
	GameObject();
	~GameObject();
	void spawn(string typeID, int health, int speed, int x, int y);
	void draw();
	void info();
	void setGameObject_X(int x);
	void setGameObject_Y(int y);
	void setHealth(int health);
	void setSpeed(int speed);
	virtual void update(int level);
	virtual string objectType();
	virtual int giveDamage();
	int GameObject_X();
	int GameObject_Y();
	int getHealth();
	string typeID();
	bool isAlive();

	//Protected variables to allow child classes direct access
protected:
	string m_typeID;
	signed int m_health;
	int m_speed;
	signed int m_x;
	signed int m_y;
	bool alive;
	int m_damage;
	string m_type;
};

#endif

