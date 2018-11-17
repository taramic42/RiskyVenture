
#pragma once
#include "Player.h"

class Strategy {


public:
	Strategy();
	~Strategy();
	virtual void reinforce() = 0;
	virtual void attack() = 0;
	virtual void fortify() = 0;
	virtual void execute() = 0;
	virtual void setPlayer(class Player *p) = 0;
	virtual void setPlayerList(vector <Player*> list) = 0;

};