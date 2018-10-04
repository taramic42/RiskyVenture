#pragma once
#include <string>
#include <iostream>


using namespace std;
class Player
{
private:
	string countries;
	string cards;

public:
	Player(string a, string b);
	Player();
	~Player();


	void diceImp();

	void reinforce();
	void attack();

	void fortify();
};

