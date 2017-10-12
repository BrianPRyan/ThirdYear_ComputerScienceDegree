//Brian Ryan.. CA2 Assignment.. 29/11/2016

#ifndef TREASURE_H
#define TREASURE_H

//Include header GameObject
#include "GameObject.h"

//Using namespace std
using namespace std;

//Player class inherits from GameObject Class
class Treasure : public GameObject
{
	//Treasure Public functions 
public:
	Treasure();
	virtual ~Treasure();
	void update(int level);
	string objectType();
};
#endif


