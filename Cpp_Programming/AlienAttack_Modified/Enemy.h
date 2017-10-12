//Brian Ryan April 2017 Advanced Game Programming Assignment 3
#ifndef __SDL_Game_Programming_Book__Enemy__
#define __SDL_Game_Programming_Book__Enemy__

#include <iostream>
#include "ShooterObject.h"

// Enemy base class
class Enemy : public ShooterObject
{
	public:
    
		virtual std::string type() { return "Enemy"; }
    
	protected:
    
		int m_health;
    
		Enemy() : ShooterObject() {}
		virtual ~Enemy() {}
};

#endif
