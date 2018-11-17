#pragma once
#include "Strategy.h"
#include "../../Risk/Board/GameBoard.h"

class Aggressive :
	public Strategy
{
public:
	Aggressive();
	~Aggressive();

	void reinforce();
	void reinforce(Deck* deck, Player* player);
	void attack();
	void fortify();

	void setStrongest(int choice);

private:
	int strongestCountry;
	Deck* deck;
	Player* player;
};

