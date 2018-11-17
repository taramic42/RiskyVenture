#pragma once
#include "Player.h"
#include"Strategy.h"
#include "AttackPhase.h"
#include"Fortify.h"
#include "ReinforcePhase.h"

class PlayerStrategy :public Strategy{
private:
	Player* player;
	vector <Player*> list;

public:
	PlayerStrategy();
	~PlayerStrategy();
	PlayerStrategy(Player *player);
	void reinforce();
	 void attack();
	 void fortify();
	 void execute();
	 void setPlayer(Player *player);
	 void setPlayerList(vector <Player*> list);
};
