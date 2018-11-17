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
	//AI flag
	bool successfullyConquered;
	


public:
	AttackPhase();
	~AttackPhase();
	//For a human
	AttackPhase(Player &player, vector<Player*> players);

	//For AI(Aggressive)
	AttackPhase(Player &player, vector<Player*> players, Country* source, Country* targ);

	void setPlayer(Player &player);

	void prompt();
	//For AI(Aggressive)
	void begAIAssult(Country* source, Country* targ);


	void attackFromCountry(int fromCountry);


	int displayAndChooseCountry();
	bool eligibleAdjacentCountries(Country* origin, Country* target);
	//added this analysis method
	void analy(int res, Country* srcCount, Country* targCount);
	void conquerCountry(Country* target);

	//overloaded to work with AI(Aggressive)
	void conquerCountry(Country* source, Country* target);
};