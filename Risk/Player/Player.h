#pragma once
#include <string>
#include <vector>
#include "../Dice/DiceClass.hpp"
#include "../Card/Hand.hpp"
#include "../MapClass/Country.h"
#include "../../Risk_Master/Risk_Master/Strategy.h"


using namespace std;

class Player{

private:
	
	vector <Country*> countries;
	Hand m_hand;
	DiceRollingFacility dice;
	int id;

	int armiesToPlaceOnBoard;

	//need to add class here not sure why
	Strategy *playerStrategy;

	Country* origin;

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

	void reinforce(Deck* deck);
	void attack(vector<Player*> players);
	void fortify();

	void display();

	void setStrategy(Strategy* newStrat);

	Hand* getHand();

	void setOrigin(Country* country);
	Country* getOrigin();
};

