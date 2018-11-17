#include "Player.h"
#include "Country.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


Player::Player() {}
Player::~Player() {}


Player::Player(vector<Country*> count, int army) {
	countries = count;
	armies = army;
	armiesToPlaceOnBoard = army;

}
Player::Player(int n)
{
	id = n;
}
Player::Player(Strategy* s)
{
	this->strategy = s;
}

void Player::setId(int n)
{
	id = n;
}
int Player::getId() const
{
	return id;
}


void Player::fortify()
{
	strategy->fortify();
}

void Player::fortify(Country* c, int n)
{

	setTotalArmies(getTotalArmies() - n);
	cout << "fortify" << endl;
	origin = c;
}

void Player::setTotalArmies(int n)
{
	armies = n;
}

int Player::getTotalArmies()
{
	return armies;
}

vector <Country*> Player::returnAll()
{
	return countries;
}
void Player::addCountry(Country* country) {
	country->setOwner(id);
	countries.push_back(country);
}

void Player::removeCountry(string name) {

	int target = -1;

	for (int i = 0; i < countries.size(); i++)
		if (countries[i]->getName().compare(name) == 0) {
			target = i;
			i = countries.size();
		}
	if (target > -1)
		countries.erase(countries.begin() + target);
}
void Player::placeOneArmy(int countryIndex) {
	if (countryIndex >= 0 && countryIndex < countries.size())
		countries[countryIndex]->addArmies(1);
}

void Player::display() {

	cout << "Player " << id << " owns:" << endl;

	for (int i = 0; i < countries.size(); i++) {
		cout << countries[i]->getName();
		cout << endl;
	}

}
int Player::getNumberOfOwnedCountries()
{
	return countries.size();
}

void Player::setOrigin(Country* c)
{
	origin = c;
}

Country* Player::getOrigin()
{
	return origin;
}

void Player::setTarget(Country* c)
{
	target = c;
}
Country* Player::getTarget()
{
	return target;
}

void Player::diceImp(int num)
{
	//Dice Thing

	cout << "diceroll of player " << id << endl;
}

void Player::reinforce()
{
	strategy->reinforce();
}

void Player::attack()
{
	strategy->attack();
}
vector<Country*> Player::getCountriesOwned()
{
	return countries;
}
DiceRollingFacility * Player::getDice()
{
	return &dice;
}
void Player::addArmiesToPlaceOnBoard(int num)
{
	armiesToPlaceOnBoard += num;
}
int Player::getArmiesLeftToPlaceOnBoard() 
{
	return armiesToPlaceOnBoard;

}
void Player::setCountries(vector<Country*> list)
{
	countries.clear();

	for (int i = 0; i < list.size(); i++)
	{
		countries.push_back(list[i]);
		list[i]->setOwner(id);
	}

}

void Player::setStrategy(Strategy* s)
{
	strategy = s;
}

void Player::execute()
{
	this->strategy->execute();
}