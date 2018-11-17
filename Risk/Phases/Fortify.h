#pragma once
#include <vector>
#include <iostream>
#include "../Player/Player.h"
#include "../MapClass/Map.h"

class Fortify 
{
public:
	Fortify();
	~Fortify();
	Fortify(Player* p);
	//void displayOwnedCountries();
	//void prompt();
	//void setOrigin();
	//void fortifyCountry();

	//Added by Xavier
	void setTotalArmiesOnCountries();
	void fortifyCountry(Country* origin, Country* target);

private:
	Player* player;
	//Added by Xavier
	int totalArmiesOnCountries;
};