#pragma once
#include"Player.h"
#include"Map.h"

class Fortify
{
public:
	Fortify();
	~Fortify();
	Fortify(Player &p);
	void displayOwnedCountries();
	void prompt();
	void setOrigin();
	void fortifyCountry();

private:
	Player* player;

};
