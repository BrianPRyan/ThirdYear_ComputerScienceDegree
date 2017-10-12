/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include <list>

using namespace std;

class GameObject
{
	public:
		//Public Variables
		void spawn(string typeID, int health, int speed, int x, int y);
		void draw();
		virtual void update();
		void info();
		bool isAlive();
		int getx();
		int gety();
		void setHealth(int health);
		int getHealth();
		virtual int hurt();
		virtual string type();

	protected:
		//Protected Variables
		string m_typeID;
		int m_health;
		int m_speed;
		int m_x;
		int m_y;
		bool alive;
};

#endif