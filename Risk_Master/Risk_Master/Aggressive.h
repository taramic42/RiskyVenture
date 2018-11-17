#pragma once
#include "Strategy.h"
#include "../../Risk/Board/GameBoard.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/AttackPhase.h"

class Aggressive :
	public Strategy
{
public:
	Aggressive();
	~Aggressive();


	void s_reinforce(Deck* deck, Player* player);
	void attack() override;
	void fortify() override;

	void setStrongest(int choice);

private:
	int strongestCountry;
	Deck* deck;
	Player* player;
};

