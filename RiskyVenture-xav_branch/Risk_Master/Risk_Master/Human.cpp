
#include "Human.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/Fortify.h"
#include "../../Risk/Phases/AttackPhase.h"


Human::Human() {}


Human::~Human() {}


void Human::reinforce(Deck* deck, Player* player) {
	
	ReinforcePhase(player, deck);

}


void Human::attack(Player* passedplayer, vector<Player*> playerList) {

	AttackPhase(*passedplayer, playerList);
	

}

void Human::fortify(Player* aplayer) {
	//Fortify();
	Fortify phase(aplayer);
}

