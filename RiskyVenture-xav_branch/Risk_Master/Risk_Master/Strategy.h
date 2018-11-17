#pragma once
class Player;
class Deck;
//class vector;
#include <vector>


using namespace std;

class Strategy
{
public:
	Strategy();
	virtual ~Strategy();

	virtual void reinforce(Deck*, Player*) =0 {};
	virtual void attack(Player*,vector<Player*>) =0 {};
	virtual void fortify() =0{};

};

