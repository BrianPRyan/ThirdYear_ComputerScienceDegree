#ifndef LOBBY_H
#define LOBBY_H

#include <iostream>
#include <string>
#include "Player.h"

class Lobby
{
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);
    
public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();
    
private:
    Player* m_pHead;
	Player* m_pTail;
};

#endif