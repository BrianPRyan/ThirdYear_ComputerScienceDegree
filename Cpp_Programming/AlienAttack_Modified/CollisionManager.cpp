//Brian Ryan April 2017 Advanced Game Programming Assignment 3
#include "CollisionManager.h"
#include "Collision.h"
#include "Player.h"
#include "Enemy.h"
#include "BulletHandler.h"
#include "TileLayer.h"

void CollisionManager::checkPlayerEnemyBulletCollision(Player* pPlayer)
{
    SDL_Rect* pRect1 = new SDL_Rect();
    pRect1->x = pPlayer->getPosition().getX();
    pRect1->y = pPlayer->getPosition().getY();
    pRect1->w = pPlayer->getWidth();
    pRect1->h = pPlayer->getHeight();
    
    for(int i = 0; i < TheBulletHandler::Instance()->getEnemyBullets().size(); i++)
    {
        EnemyBullet* pEnemyBullet = TheBulletHandler::Instance()->getEnemyBullets()[i];
        
        SDL_Rect* pRect2 = new SDL_Rect();
        pRect2->x = pEnemyBullet->getPosition().getX();
        pRect2->y = pEnemyBullet->getPosition().getY();
        
        pRect2->w = pEnemyBullet->getWidth();
        pRect2->h = pEnemyBullet->getHeight();
        
        if(RectRect(pRect1, pRect2))
        {
            if(!pPlayer->dying() && !pEnemyBullet->dying())
            {
                pEnemyBullet->collision();
                pPlayer->collision();
            }
        }
        
        delete pRect2;
    }
    
    delete pRect1;
}

void CollisionManager::checkEnemyPlayerBulletCollision(const std::vector<GameObject *> &objects)
{
    for(int i = 0; i < objects.size(); i++)
    {
        GameObject* pObject = objects[i];
        
        for(int j = 0; j < TheBulletHandler::Instance()->getPlayerBullets().size(); j++)
        {
            if(pObject->type() != std::string("Enemy") || !pObject->updating())
            {
                continue;
            }
            
            SDL_Rect* pRect1 = new SDL_Rect();
            pRect1->x = pObject->getPosition().getX();
            pRect1->y = pObject->getPosition().getY();
            pRect1->w = pObject->getWidth();
            pRect1->h = pObject->getHeight();
            
            PlayerBullet* pPlayerBullet = TheBulletHandler::Instance()->getPlayerBullets()[j];
            
            SDL_Rect* pRect2 = new SDL_Rect();
            pRect2->x = pPlayerBullet->getPosition().getX();
            pRect2->y = pPlayerBullet->getPosition().getY();
            pRect2->w = pPlayerBullet->getWidth();
            pRect2->h = pPlayerBullet->getHeight();
            
            if(RectRect(pRect1, pRect2))
            {
                if(!pObject->dying() && !pPlayerBullet->dying())
                {
                    pPlayerBullet->collision();
                    pObject->collision();
                }
                
            }
            
            delete pRect1;
            delete pRect2;
        }
    }
}

void CollisionManager::checkPlayerEnemyCollision(Player* pPlayer, const std::vector<GameObject*> &objects)
{
    SDL_Rect* pRect1 = new SDL_Rect();
    pRect1->x = pPlayer->getPosition().getX();
    pRect1->y = pPlayer->getPosition().getY();
    pRect1->w = pPlayer->getWidth();
    pRect1->h = pPlayer->getHeight();
    
    for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i]->type() != std::string("Enemy") || !objects[i]->updating())
        {
            continue;
        }
        
        SDL_Rect* pRect2 = new SDL_Rect();
        pRect2->x = objects[i]->getPosition().getX();
        pRect2->y = objects[i]->getPosition().getY();
        pRect2->w = objects[i]->getWidth();
        pRect2->h = objects[i]->getHeight();
        
        if(RectRect(pRect1, pRect2))
        {
            if(!objects[i]->dead() && !objects[i]->dying())
            {
                pPlayer->collision();
            }
        }
        
        delete pRect2;
    }
    
    delete pRect1;
}

void CollisionManager::checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*>& collisionLayers)
{
	for (std::vector<TileLayer*>::const_iterator it = collisionLayers.begin(); it != collisionLayers.end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();

		Vector2D layerPos = pTileLayer->getPosition();

		int x, y, tileColumn, tileRow, tileid = 0;

		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		//old way just blowing up if touch anytyhing
		//for running and hitting walls as a man i need a little more checking
		//i need to check each direction seperately instead of in pairs of (right, down) and (left, up)
		//reason i check in pairs is because the sprite top right corner is (0,0) so checking left and up , i dont need to add the actual sprite width or height, when checking right and down i need to add the sprite height and width.
		//i have a double vector of tile id's and i simply devide the position by the tile size 32. i then get what column i am touching in relation to the way i am moving, velocity.
		//if the velicity is up, then i can first check the tests upwards. i know velocity is minus y, so i am moving up. in this case i only need the player position Y which will be the top entire line of player box,
		//i then check is the value of that tile zero, which means its an empty tile, if its not an emtpy tile
		//in this case i am going to do a check and see if its a solid tile, i must set the Y velocity to zero and also move its value back to just below the solid tile
		//i do same for each direction.

		bool collide = false;//check one row first, no reason check second if already collided
		switch (TheGame::Instance()->getCurrentLevel())//switch level
		{
		case 1://if on first level use simple blow up when touch solid tile
			if (pPlayer->getVelocity().getX() >= 0 || pPlayer->getVelocity().getY() >= 0)
			{
				tileColumn = ((pPlayer->getPosition().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize());
				tileRow = ((pPlayer->getPosition().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize());
				tileid = tiles[tileRow + y][tileColumn + x];
			}
			else if (pPlayer->getVelocity().getX() < 0 || pPlayer->getVelocity().getY() < 0)
			{
				tileColumn = pPlayer->getPosition().getX() / pTileLayer->getTileSize();
				tileRow = pPlayer->getPosition().getY() / pTileLayer->getTileSize();
				tileid = tiles[tileRow + y][tileColumn + x];
			}

			if (tileid != 0)
			{
				pPlayer->collision();
			}
			break;

		case 2://when on level 2 i need a little bit more control over collision and player velocity etc
			if (pPlayer->getVelocity().getX() >= 0)//checking here if velocity is moving right
			{
				//i have to check usually two rows as our player can be touching blocks in either 2 or 1 rows
				collide = false;

				tileColumn = ((pPlayer->getPosition().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize());
				tileRow = ((pPlayer->getPosition().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize()) - 1;//first row check + col
				tileid = tiles[tileRow + y][tileColumn + x];
				if (tileid != 0)
				{
					std::cout << "We Hit right wall" << std::endl;
					collide = true;//if true step back a bit and skip next check
					pPlayer->setPositionX((tileColumn * 32) - 5);//step player back left into emtpy area
				}

				if (!collide)//check next row now for collision with wall just in case
				{
					tileColumn = ((pPlayer->getPosition().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize());
					tileRow = ((pPlayer->getPosition().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize());
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0)
					{
						std::cout << "We Hit right wall" << std::endl;
						pPlayer->setPositionX((tileColumn * 32) - 5);//step player back left into emtpy area

					}
				}
			}

			if (pPlayer->getVelocity().getY() >= 0)//check here if velcoty is moving down
			{
				collide = false;

				tileColumn = ((pPlayer->getPosition().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize()) - 1;
				tileRow = (pPlayer->getPosition().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize();
				tileid = tiles[tileRow + y][tileColumn + x];
				if (tileid != 0)
				{
					std::cout << "We Hit bottom wall" << std::endl;
					collide = true;//if true step back a bit and skip next check
					pPlayer->setPositionX((tileRow * 32) - 5);//step player back up into emtpy area
				}

				if (!collide)//check now other column block
				{
					tileColumn = ((pPlayer->getPosition().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize());
					tileRow = ((pPlayer->getPosition().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize());
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0)
					{
						std::cout << "We Hit bottom wall" << std::endl;
						pPlayer->setPositionX((tileRow * 32) - 5);//step player back up into emtpy area
					}
				}

				collide = false;
			}

			if (pPlayer->getVelocity().getX() < 0)//checking left
			{
				tileColumn = (pPlayer->getPosition().getX() / pTileLayer->getTileSize());
				tileRow = (pPlayer->getPosition().getY() / pTileLayer->getTileSize());
				tileid = tiles[tileRow + y][tileColumn + x];
				if (tileid != 0)
				{
					std::cout << "We Hit left wall" << std::endl;
					collide = true;//if true step back a bit and skip next check
					pPlayer->setPositionX((tileColumn * 32) + 5);//step player back up into emtpy area
				}

				if (!collide)//check now other column block
				{
					tileColumn = (pPlayer->getPosition().getX() / pTileLayer->getTileSize());
					tileRow = ((pPlayer->getPosition().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize());
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0)
					{
						std::cout << "We Hit bottom wall" << std::endl;
						pPlayer->setPositionX((tileColumn * 32) + 5);//step player back up into emtpy area
					}
				}

				collide = false;

			}

			if (pPlayer->getVelocity().getY() < 0)//checking up
			{
				tileColumn = pPlayer->getPosition().getX() / pTileLayer->getTileSize();
				tileRow = pPlayer->getPosition().getY() / pTileLayer->getTileSize();
				tileid = tiles[tileRow + y][tileColumn + x];
				if (tileid != 0)
				{
					std::cout << "We Hit top wall" << std::endl;
					collide = true;//if true step back a bit and skip next check
					pPlayer->setPositionX((tileRow * 32) + 5);//step player back up into emtpy area
				}


				if (!collide)//check now other column block
				{
					tileColumn = ((pPlayer->getPosition().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize());
					tileRow = (pPlayer->getPosition().getY() / pTileLayer->getTileSize());
					tileid = tiles[tileRow + y][tileColumn + x];
					if (tileid != 0)
					{
						std::cout << "We Hit bottom wall" << std::endl;
						pPlayer->setPositionX((tileRow * 32) + 5);//step player back up into emtpy areaa
					}
				}

				collide = false;
			}
			break;
		}
	}
}