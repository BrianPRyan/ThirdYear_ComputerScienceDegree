//Brian Ryan April 2017 Advanced Game Programming Assignment 3
#ifndef __SDL_Game_Programming_Book__Player__
#define __SDL_Game_Programming_Book__Player__

#include <iostream>
#include <vector>
#include "ShooterObject.h"
#include "GameObjectFactory.h"

class Player : public ShooterObject
{
	public:
    
		Player();
		virtual ~Player() {}
    
		virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
		virtual void draw();
		virtual void update();
		virtual void clean();
    
		virtual void collision();
    
		virtual std::string type() { return "Player"; }

		void jump();
    
	private:
    
		// bring the player back if there are lives left
		void ressurect();
    
		// handle any input from the keyboard, mouse, or joystick
		void handleInput();
    
		// handle any animation for the player
		void handleAnimation();

		// player can be invulnerable for a time
		int m_invulnerable;
		int m_invulnerableTime;
		int m_invulnerableCounter;

		//jumping variable
		bool jumping;
		float shootingAngle;
};

// for the factory
class PlayerCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Player();
    }
};

#endif
