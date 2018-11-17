#pragma once
#include "Player.h"
#include "PlayerStrategy.h"

class Human : public PlayerStrategy
{
private:
	Player* player;

public:
	Human();
	~Human();
	void reinforce();
	void attack();
	void fortify();
};
