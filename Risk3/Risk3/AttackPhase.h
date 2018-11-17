#pragma once
#include "Player.h"
#include "Map.h"
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


	void attackFromCountry(int fromCountry);


	//added overloaded member function for Aggressive Strategy
	void attackFromCountry(int choice, int target);


	int displayAndChooseCountry();
	bool eligibleAdjacentCountries(Country* origin, Country* target);
	void conquerCountry(Country* target);
};