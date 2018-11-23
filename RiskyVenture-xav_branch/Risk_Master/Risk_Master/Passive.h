#pragma once
#include "../../Risk/Player/Player.h"
#include"Strategy.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/Fortify.h"
#include "../../Risk/Board/GameBoard.h"


class Passive :public Strategy {
private:
	Player *player;

public:
	Passive();
	~Passive();

	void fortify(Player* player);

	void reinforce(Deck* deck, Player* player);
	void attack(Player*, vector<Player*>);
	void setPlayer(Player *p);
	void setPlayerList(vector <Player*> list);
};
