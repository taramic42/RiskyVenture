#pragma once
#include "Strategy.h"
#include "../../Risk/Board/GameBoard.h"
class Human:
	public Strategy
{
public:
	Human();
	~Human();


	void reinforce(Deck* deck, Player* player);
	void attack(Player*, vector<Player*>);
	void fortify(Player*);



	
};
