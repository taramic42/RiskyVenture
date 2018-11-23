#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "../Phases/Fortify.h"

Player::Player() {}
Player::~Player() {}

Player::Player (int num) {
	id = num;
	dice = DiceRollingFacility();
	armiesToPlaceOnBoard = 0;
}

DiceRollingFacility * Player::getDice()
{
	return &dice;
}

int Player::getNumberOfOwnedCountries() {
	return countries.size();
}

vector<Country*> Player::getCountriesOwned()
{
	return countries;
}

int Player::getId() const
{
	return id;
}

void Player::addCountry(Country* country) {
	country->setOwner(id);
	countries.push_back(country);
}

void Player::removeCountry(string name) {

	int target = -1;

	for(int i = 0; i<countries.size(); i++)
		if (countries[i]->getName().compare(name) == 0) {
			target = i;
			i = countries.size();
		}
	if (target > -1)
		countries.erase(countries.begin() + target);
}

void Player::placeOneArmy(int countryIndex) {
	if(countryIndex>=0&&countryIndex<countries.size())
		countries[countryIndex]->addArmies(1);
}

void Player::addArmiesToPlaceOnBoard(int num)
{
	armiesToPlaceOnBoard += num;
}

int Player::getArmiesLeftToPlaceOnBoard() const
{
	return armiesToPlaceOnBoard;
}

void Player::setCountries(vector<Country*> list)
{
	countries.clear();

	for (int i = 0; i < list.size(); i++)
		countries.push_back(list[i]);

}

void Player::diceImp(int num)
{

	cout<<"diceroll of player " << id <<endl;
}

void Player::reinforce(Deck* deck)
{
	cout << "                                        PLAYER " + to_string(id + 1) +
		"\n__________________________________________________________________________________\n"
		"+++++++++++++++++++++++++++++++++ REINFORCE PHASE ++++++++++++++++++++++++++++++++\n"
		"__________________________________________________________________________________\n\n" << endl;
	playerStrategy->reinforce(deck, this);
}

void Player::attack(vector<Player*> players)
{
	cout <<
		"                                        PLAYER " + to_string(id + 1) +
		"\n________________________________________________________________________________\n"
		"++++++++++++++++++++++++++++++++++ ATTACK PHASE ++++++++++++++++++++++++++++++++\n"
		"________________________________________________________________________________\n\n" << endl;
	playerStrategy->attack(this, players);
}

void Player::fortify()
{
	cout <<
		"                                        PLAYER " + to_string(id + 1) +
		"\n________________________________________________________________________________\n"
		"+++++++++++++++++++++++++++++++ FORTIFY PHASE ++++++++++++++++++++++++++++++++++\n"
		"________________________________________________________________________________\n\n" << endl;
	playerStrategy->fortify(this);
	
}

void Player::display() {

	cout << "Player " << id << " owns:"<<endl;
	
	for (int i = 0; i < countries.size();i++) {
		cout << countries[i]->getName()<<" with "<<countries[i]->getArmyCount()<<" armies.";
		cout << endl;
	}

}


void Player::setStrategy(Strategy* newStrategy) {
	playerStrategy =  newStrategy;
}

Hand* Player::getHand()
{
	return &m_hand;
}

void Player::setOrigin(Country * country)
{
	origin = country;
}

Country * Player::getOrigin()
{
	return origin;
}
