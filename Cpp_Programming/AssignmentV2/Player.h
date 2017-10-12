//Brian Ryan.. CA2 Assignment.. 29/11/2016

#ifndef PLAYER_H
#define PLAYER_H

//Include header GameObject
#include "GameObject.h"

//Using namespace std
using namespace std;

//Player class inherits from GameObject Class
class Player : public GameObject
{
	//Player Public functions 
public:
	Player();
	virtual ~Player();
	void update(int level);
	int giveDamage();
	string objectType();

private:
	int boundaryX;
	int boundaryY;

};
#endif



