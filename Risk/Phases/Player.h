#pragma once
#include <string>
#include <vector>
#include "Country.h"

using namespace std;

class Player {

private:
	vector <Country*> countries;
	//vector <Card> hand;
	//DiceRollingFacility dice;
	int id;
	vector <Country> flist;
	int armies;
	Country* origin;
	Country* target;

public:
	Player();
	~Player();
	Player(int num);
	Player(vector<Country*> count,  int army);

	int getNumberOfOwnedCountries();

	//void diceImp(int num);

	void addCountry(Country* country);
	void removeCountry(string name);
	void placeOneArmy(int index);
	void setTotalArmies(int n);
	int getTotalArmies();
	vector <Country*> returnAll();

	void reinforce();
	void attack();

	void fortify(Country* c, int n);

	void display();
	void setId(int n);
	int getId();
	void setTarget(Country* c);
	Country* getTarget();
	void setOrigin(Country* c);
	Country* getOrigin();
};
