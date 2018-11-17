#pragma once
#include <vector>
#include <iostream>
#include "../Player/Player.h"
#include "../MapClass/Map.h"
#include <algorithm>

class Fortify 
{
public:
	Fortify();
	~Fortify();
	Fortify(Player* p);
	void prompt();
	void fortifyCountry(int armies);

	//Added by Xavier
	void setTotalArmiesOnCountries();
	void fortifyCountry(Country* origin, Country* target);
	vector<Country*> getElegibleCountries();
	vector<Country*> getElegibleTargetCountries();

private:
	Player* player;
	//Added by Xavier
	int totalArmiesOnCountries;
	Country *m_origin;
	Country *m_target;
};