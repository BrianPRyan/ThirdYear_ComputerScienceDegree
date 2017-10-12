#include "Lobby.h"

Lobby::Lobby():
    m_pHead(0)

{}

Lobby::~Lobby()
{
    Clear();
}

void Lobby::AddPlayer()
{
    //create a new player node
    cout << "Please enter the name of the new player: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);

    //if list is empty, make head of list this new player
    if (m_pHead == 0)
    {
        m_pHead = pNewPlayer;
		m_pTail = pNewPlayer;
    }
    //otherwise find the end of the list and add the player there
    else
    {
        /*Player* pIter = m_pHead;
        while (pIter->GetNext() != 0)
        {
            pIter = pIter->GetNext();       
        }*/
        m_pTail->SetNext(pNewPlayer);
		m_pTail = m_pTail->GetNext();//new line pointer pointing to last member of list
		cout << " Just added " << *m_pTail<<" \n";
    }
}

void Lobby::RemovePlayer()
{
    if (m_pHead == 0)
    {
        cout << "The game lobby is empty.  No one to remove!\n";
    }
    else
    {
        Player* pTemp = m_pHead;
        m_pHead = m_pHead->GetNext();
        delete pTemp;
    }
}

void Lobby::Clear()
{
    while (m_pHead != 0)
    {
        RemovePlayer();
    }
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
    Player* pIter = aLobby.m_pHead;

    os << "\nHere's who's in the game lobby:\n";
    if (pIter == 0)
    {
        os << "The lobby is empty.\n";
    }
    else
    {
        while (pIter != 0)
        {   
            os << *pIter << endl;//will use the overload << for printing the player object i.e. piter
	        pIter = pIter->GetNext();
        }
    }

    return os;
}

ostream& operator<<(ostream& os, const Player& aPlayer)
{
			os << "Player Details\n" << endl;
			os << aPlayer.m_Name << endl;
	
			return os;
}

