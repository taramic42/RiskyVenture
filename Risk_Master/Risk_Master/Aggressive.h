#pragma once
#include "Strategy.h"
#include "../../Risk/Board/GameBoard.h"

class Aggressive :
	public Strategy
{
public:
	Aggressive();
	~Aggressive();

	void Aggressive::getArmies(Player* thePlayer);
	void reinforce(Deck* deck, Player* player);
	void attack(Player*, vector<Player*>);
	void fortify(Player *player);

	
	int findStrongestCountry();

private:
	int strongestCountry;
	Deck* deck;
	Player* player;
	Player* playerList;
};

