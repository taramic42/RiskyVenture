#pragma once
class Player;
class Deck;



class Strategy
{
public:
	Strategy();
	virtual ~Strategy();
	virtual void reinforce() = 0 {};
	virtual void reinforce(Deck*, Player*) =0 {};
	virtual void attack() =0 {};
	virtual void fortify() =0{};

};

