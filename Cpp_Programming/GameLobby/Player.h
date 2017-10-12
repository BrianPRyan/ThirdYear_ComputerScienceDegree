#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:  
    Player(const string& name = "");
    string GetName() const;
    Player* GetNext() const;
    void SetNext(Player* next);
	friend ostream& operator<<(ostream& os, const Player& aPlayer);
    
private:
    string m_Name; // friend function is enablingg us to access this private variable
    Player* m_pNext;  //Pointer to next player in list
};

#endif