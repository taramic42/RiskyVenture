#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"

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
	//Added for observer pattern
	//To ensure chart is updated
	notify();
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

	//Added for observer pattern
	//In case game is started with specified countries for players
	notify();
}

void Player::diceImp(int num)
{
	//Dice Thing

	cout<<"diceroll of player " << id <<endl;
}

void Player::reinforce()
{
	cout << "reinforced " << endl;
}

void Player::attack()
{
	cout << "attacked" << endl;
}

void Player::fortify()
{
	cout << "fortify" << endl;
}

void Player::display() {

	cout << "Player " << id << " owns:"<<endl;
	
	for (int i = 0; i < countries.size();i++) {
		cout << countries[i]->getName()<<" with "<<countries[i]->getArmyCount()<<" armies.";
		cout << endl;
	}

}

