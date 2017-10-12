/*Brian Ryan K00202212
Game Programming Assignment 1 Oct/Nov 2016*/

#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

using namespace std;

class Player : public GameObject
{

public:
	//Public Variables
	Player();
	~Player();
	void update();
	int hurt();
	string type();

private:
	//Private Variables
	int m_damage = 50;
	string m_type = "player";
}; 
#endif

