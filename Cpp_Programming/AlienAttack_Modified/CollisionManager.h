//Brian Ryan April 2017 Advanced Game Programming Assignment 3
#ifndef __SDL_Game_Programming_Book__CollisionManager__
#define __SDL_Game_Programming_Book__CollisionManager__

#include <iostream>
#include <vector>
#include "Vector2D.h"

class Player;
class GameObject;
class TileLayer;

class CollisionManager
{
public:
    
    void checkPlayerEnemyBulletCollision(Player* pPlayer);
    void checkPlayerEnemyCollision(Player* pPlayer, const std::vector<GameObject*> &objects);
    void checkEnemyPlayerBulletCollision(const std::vector<GameObject*>& objects);
    void checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*>& collisionLayers);
};

#endif
