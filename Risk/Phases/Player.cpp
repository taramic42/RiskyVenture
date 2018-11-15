#include "Player.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


Player::Player() {}
Player::~Player() {}

Player::Player(vector<Country*> count, int army) {
	countries = count;

	armies = army;
}
Player::Player(int n)
{
	id = n;
}
//void Player::diceImp()
//{
//	//Dice Thing
//	cout << "diceroll: " << dice << endl;
//}
void Player::setId(int n)
{
	id = n;
}
int Player::getId()
{
	return id;
}
void Player::reinforce()
{
	cout << "reinforced " << endl;
}

void Player::attack()
{
	cout << "attacked" << endl;
}



void Player::fortify(Country* c,int n)
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