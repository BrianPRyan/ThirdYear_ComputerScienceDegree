#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "GameObjectFactory.h"
#include "BulletHandler.h"
#include "SoundManager.h"
#include <math.h>
#include "GameObject.h"

class Ice : public GameObject
{
	public:

		~Ice();

		void load(std::unique_ptr<LoaderParams> const &pParams)
		{
			GameObject::load(std::move(pParams));

		}

		void collision();

		void update();

		void draw();

		void clean();

		std::string type();

	private:

		int m_maxHeight;
		int m_minHeight;
		int m_gap;
};

class IceCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Ice();
	}
};



#endif 

