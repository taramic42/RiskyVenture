#pragma once
#include <string>
#include <vector>
#include "Country.h"
#include "DiceClass.h"
#include "Card.h"
#include "Strategy.h"

using namespace std;

class Player {

private:
	vector <Country*> countries;
	vector <Card> hand;
	DiceRollingFacility dice;
	int id;
	int armiesToPlaceOnBoard;
	vector <Country> flist;
	int armies;
	Country* origin;
	Country* target;
	class Strategy* strategy;



public:
	Player();
	~Player();
	Player(int num);
	Player(vector<Country*> count, int army);
	Player(Strategy *s);
	int getNumberOfOwnedCountries();
	void diceImp(int num);
	void addCountry(Country* country);
	void removeCountry(string name);
	void placeOneArmy(int index);
	void setTotalArmies(int n);
	int getTotalArmies();
	vector <Country*> returnAll();
	void reinforce();
	void attack();
	void fortify(Country* c, int n);
	void fortify();
	void display();
	void setId(int n);
	int getId() const;
	void setTarget(Country* c);
	Country* getTarget();
	void setOrigin(Country* c);
	Country* getOrigin();
	vector<Country*> getCountriesOwned();
	DiceRollingFacility* getDice();
	void addArmiesToPlaceOnBoard(int num);
	int getArmiesLeftToPlaceOnBoard();
	void setCountries(vector<Country*> list);
	void setStrategy(Strategy* s);
	void execute();

};
