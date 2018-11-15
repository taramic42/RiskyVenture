#pragma once
//#include "stdafx.h"
#include <string>
#include <vector>
#include "../Dice/DiceClass.hpp"
#include "../Card/Hand.hpp"
#include "../MapClass/Country.h"
#include "../../Risk_Master/Risk_Master/Subject.h"

using namespace std;

class Player:public Subject{

private:
	vector <Country*> countries;
	vector <Card> hand;
	DiceRollingFacility dice;
	int id;
	int armiesToPlaceOnBoard;
public:
	Player();
	~Player();
	Player(int num);

	DiceRollingFacility* getDice();

	int getNumberOfOwnedCountries();
	vector<Country*> getCountriesOwned();
	int getId() const;

	void diceImp(int num);

	void addCountry(Country* country);
	void removeCountry(string name);
	void placeOneArmy(int index);

	void addArmiesToPlaceOnBoard(int num);
	int getArmiesLeftToPlaceOnBoard() const;

	void setCountries(vector<Country*> list);

	void reinforce();
	void attack();

	void fortify();

	void display();
};

