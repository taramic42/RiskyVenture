#pragma once
#include "Player.h"
#include"Strategy.h"
#include"Fortify.h"
#include "ReinforcePhase.h"
class Passive :public Strategy {
private:
	Player *player;


public:
	Passive();
	~Passive();
	void reinforce();
	void fortify();
	void attack();
	void execute();
	void setPlayer(Player *p);
	void setPlayerList(vector <Player*> list);
};
