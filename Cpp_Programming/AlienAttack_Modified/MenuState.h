//Brian Ryan April 2017 Advanced Game Programming Assignment 3
#ifndef SDL_Game_Programming_Book_MenuState_h
#define SDL_Game_Programming_Book_MenuState_h

#include "GameState.h"

class MenuState : public GameState
{
public:
    
    virtual ~MenuState() {}
    
protected:
    
    typedef void(*Callback)();
    virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
    
    std::vector<Callback> m_callbacks;
};


#endif
