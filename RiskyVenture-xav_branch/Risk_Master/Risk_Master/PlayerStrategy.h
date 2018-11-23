#pragma once
#include "../../Risk/Player/Player.h"
#include"Strategy.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/Fortify.h"
#include "../../Risk/Phases/AttackPhase.h"
#include "../../Risk/Board/GameBoard.h"

class PlayerStrategy :public Strategy {
private:
	Player* player;
	vector <Player*> list;

public:
	PlayerStrategy();
	~PlayerStrategy();
	PlayerStrategy(Player *player);;
	void fortify(Player *player);
	void setPlayer(Player *player);
	void setPlayerList(vector <Player*> list);
	void reinforce(Deck* deck, Player* player);
	void attack(Player*, vector<Player*>);
};

