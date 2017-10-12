/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include <time.h>

using namespace std;

class Enemy : public GameObject
{

public:
	//Public Variables
	Enemy();
	~Enemy();
	void update();
	int hurt();
	string type();

private:
	//Private Variables
	int m_damage = 24;
	string m_type = "enemy";

};
#endif
