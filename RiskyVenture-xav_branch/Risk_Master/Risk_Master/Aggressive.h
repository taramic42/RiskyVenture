#pragma once
#include "Strategy.h"
#include "../../Risk/Board/GameBoard.h"

class Aggressive :
	public Strategy
{
public:
	Aggressive();
	~Aggressive();


	void reinforce(Deck* deck, Player* player);
	void attack(Player*, vector<Player*>);
	void fortify();

	void setStrongest(int choice);
	int findStrongestCountry();

private:
	int strongestCountry;
	Deck* deck;
	Player* player;
	Player* playerList;
};

