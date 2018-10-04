#pragma once
#include "Player.h"
#include <string>

using namespace std;







    Player::Player (string a, string b) {
		a = countries;
		b = cards;
	}

	Player::Player() {}
	Player::~Player() {}


	void Player::diceImp()
	{
		//Dice Thing
	}

	void Player::reinforce()
	{
		cout << "reinforced" << endl;
		return;
	}

	void Player::attack()
	{
		cout << "attacked" << endl;
		return;
	}

	void Player::fortify()
	{
		cout << "fortify" << endl;
		return;
	}


