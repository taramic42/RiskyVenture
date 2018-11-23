#pragma once
#include <vector>
#include "../Player/Player.h"
#include "../MapClass/Map.h"
#include <cmath>
#include <math.h>


using namespace std;

class ReinforcePhase {
public:
	ReinforcePhase();
	~ReinforcePhase();
	ReinforcePhase(Player *player, Deck* adeck);
	//use for AI
	ReinforcePhase(Player *player);

	void getArmies();
	void getContinentBonus(Map* map);

	void placeArmies(int numOfArmies, int countryChoice);
	void prompt();
	void displayOwnedCountries();
	void cardExchange(Deck* d, Hand* h);


private:
	Player* thePlayer;
};