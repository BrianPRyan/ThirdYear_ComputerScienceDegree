//Brian Ryan.. CA2 Assignment.. 29/11/2016

#ifndef ENEMY_H
#define ENEMY_H

//Include headers and libraries
#include "GameObject.h"
#include <time.h>

//Using namespace std
using namespace std;

//Class Enemy inherits from GameObject class
class Enemy : public GameObject
{
	//Puclic functions
public:
	Enemy();
	virtual ~Enemy();
	void update(int level);
	int giveDamage();
	string objectType();

private:
	int boundaryX;
	int boundaryY;


};
#endif


