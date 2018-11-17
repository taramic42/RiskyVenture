#include "PlayerStrategy.h"


PlayerStrategy::PlayerStrategy(){}
PlayerStrategy::~PlayerStrategy() {}
PlayerStrategy::PlayerStrategy(Player *p) { player = p; }

void PlayerStrategy::setPlayer(Player *p)
{
	player = p;
}
void PlayerStrategy::setPlayerList(vector <Player*> plist)
{
	list = plist;
}
void PlayerStrategy::reinforce()
{
	ReinforcePhase phase(*player);
	phase.prompt();
}
void PlayerStrategy::attack()
{
	//attack phase still needs to be debugged 
	AttackPhase phase(*player,list);
	phase.prompt();
}
void PlayerStrategy::fortify()
{
	Fortify phase(*player);
	phase.prompt();
}
void PlayerStrategy::execute()
{
	cout << "Player " << player->getId()<<endl;
	reinforce();
	attack();
	fortify();
}