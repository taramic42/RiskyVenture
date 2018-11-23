#include "PlayerStrategy.h"


PlayerStrategy::PlayerStrategy() {}
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
void PlayerStrategy::reinforce(Deck* deck, Player* player)
{
	ReinforcePhase phase(player);
	phase.prompt();
}
void PlayerStrategy::attack(Player*player , vector<Player*> list)
{
	AttackPhase phase(*player, list);
	phase.prompt();
}
void PlayerStrategy::fortify(Player *player)
{
	Fortify phase(player);
	phase.prompt();
}


