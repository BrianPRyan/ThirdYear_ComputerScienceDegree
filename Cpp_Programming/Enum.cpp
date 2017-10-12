#include <iostream>
#include <string>
using namespace std;

int main()
{
	enum difficulty {NOVICE, EASY, HARD, DEATHMODE};
	difficulty myDifficulty;
	myDifficulty = DEATHMODE;
	cout << "The current difficulty setting is: " << myDifficulty << "\n";

	enum shipCost {FIGHTER_COST = 25, BOMBER_COST = 50};
	shipCost myShipCost = BOMBER_COST;
	int loot = 500;
	cout << "The loot is: " << loot << "\n";
	loot = loot - myShipCost;
	cout << "The loot is now: " << loot;

	return 0;

}
