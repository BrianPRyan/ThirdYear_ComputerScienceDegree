#include "Lobby.h"

int main()
{
    Lobby myLobby;
    int choice;
    
    do
	{
	    cout << myLobby;
        cout << "\nGAME LOBBY\n";
        cout << "0 - Exit the program.\n";
        cout << "1 - Add a player to the lobby.\n";
        cout << "2 - Remove a player from the lobby.\n";
        cout << "3 - Clear the lobby.\n";
        cout << endl << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 0: cout << "Good-bye.\n"; break;
	        case 1: myLobby.AddPlayer(); break;  
            case 2: myLobby.RemovePlayer(); break;
            case 3: myLobby.Clear(); break;
            default: cout << "That was not a valid choice.\n";
        }
	}
    while (choice != 0);
	system("pause");
    
    return 0;
}


