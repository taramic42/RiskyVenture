#pragma once
#include "../../Risk/Player/Player.h"
#include "../../Risk/Card/Deck.hpp"


class Strategy
{
public:
	Strategy();
	virtual ~Strategy();

	virtual void s_reinforce(Deck*, Player*)=0;
	virtual void attack()=0;
	virtual void fortify()=0;

};

