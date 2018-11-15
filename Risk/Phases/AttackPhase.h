#pragma once
#include "../Player/Player.h"
#include "../MapClass/Map.h"
#include <iostream>
#include <vector>

class AttackPhase {
private:
	Player* thePlayer;
	vector<Country*> eligibleCountries;
	vector<Player*> playerList;


public:
	AttackPhase();
	~AttackPhase();

	AttackPhase(Player &player, vector<Player*> players);

	void setPlayer(Player &player);

	void prompt();


	int attackFromCountry(int fromCountry);
	int displayAndChooseCountry();
	bool eligibleAdjacentCountries(Country* origin, Country* target);
	void conquerCountry(Country* target);
};