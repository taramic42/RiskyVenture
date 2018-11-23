#include "Aggressive.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/Fortify.h"
#include "../../Risk/Phases/AttackPhase.h"


Aggressive::Aggressive(){}


Aggressive::~Aggressive()
{
	
}



void Aggressive::reinforce(Deck* Deck, Player* Player) {
	
	deck = Deck;
	player = Player;

	std::cout << "Player " << player->getId()+1 << " is currently playing as the aggressive strategy." << endl;
	std::cout << "Searching for country with most armies to reinforce." << endl;

	int index = 0;
	int largestArmy = 0;
	
	//loops through countries owned, finds strongest and sets choice to index of strongest country from "getCountriesOwned"

	for (int i = 0; i < player->getCountriesOwned().size(); i++) {
		if (player->getCountriesOwned()[i]->getArmyCount() > largestArmy) {
			largestArmy = player->getCountriesOwned()[i]->getArmyCount();
			index = i;
		}
	}

	std::cout << "Country with most armies found " << player->getCountriesOwned()[index]->getName() << endl;
	std::cout << "Army count " << player->getCountriesOwned()[index]->getArmyCount() << endl;

	strongestCountry = findStrongestCountry();

	ReinforcePhase phase(player);

	
	phase.cardExchange(deck, player->getHand());

	phase.placeArmies(player->getArmiesLeftToPlaceOnBoard(), index);

	std::cout << "Reinforce phase ends." << endl << endl;

}


void Aggressive::attack(Player* passedplayer, vector<Player*> playerList) {
	
	player = passedplayer;

	std::cout << "\n\n#############Beginning of Aggressive Attack Phase.#############\n\n" << endl;
	strongestCountry = findStrongestCountry();
	std::cout << "This is my strongest country: " << player->getCountriesOwned()[strongestCountry]->getName() << endl;
	std::cout << "Size of it's army: " << player->getCountriesOwned()[strongestCountry]->getArmyCount() << endl;


	vector<Country*> strongestCountryBorders = player->getCountriesOwned()[strongestCountry]->getBorderCountries();



	//Use to test eneglible targets
	/*for (int i = 0; i < strongestCountryBorders.size(); i++) {
		std::cout << "Owner " << strongestCountryBorders[i]->getOwner()+1 << endl;
	}
*/

	Country* attackFrom = player->getCountriesOwned()[strongestCountry];

	Country* attackTarget;

	int num = 0;
	for (auto i : strongestCountryBorders) {

		if (player->getId() != i->getOwner()) {
			attackTarget = i;
			num++;
		}
		num;
	}
	std::cout << "Number of border countries I can attack: " << num << endl;
	std::cout << "_________________________________________________________________________________________\n\n" << endl;

	for (auto i : strongestCountryBorders) {
		if (player->getId() != i->getOwner()) {
			attackTarget = i;
			//here we call AttackPhase()..
			if (attackFrom->getArmyCount() >= 2) {

				std::cout << "Now moving to attack boprder country " << attackTarget->getName() << endl;
				AttackPhase(*player, playerList, attackFrom, attackTarget);
			}
			else {
				std::cout << "You no longer have enough armies to attack " << attackTarget->getName() << endl;
				return;
			}

		}

	}

	std::cout << "No border countries to attack." << endl;
	std::cout << "Attack Phase ends." << endl << endl;

	

}

void Aggressive::fortify(Player *player) {



	Fortify phase(player);

	phase.prompt();


	//std::cout << "Fortify phase begins. Finding country with most armies to fortify." << endl;

	//int index = 0;
	//int largestArmy = 0;


	//for (int i = 0; i < player->getCountriesOwned().size(); i++) {
	//	if (player->getCountriesOwned()[i]->getArmyCount() > largestArmy) {
	//		largestArmy = player->getCountriesOwned()[i]->getArmyCount();
	//		index = i;
	//	}
	//}

	//Country* target = player->getCountriesOwned()[index];

	//std::cout << "Strongest country found. " << target->getName() << endl;
	//std::cout << "Searching for adjacent source country." << endl;

	//for (auto i : target->getBorderCountries()) {
	//	if (i->getOwner() == player->getId() && i->getArmyCount() > 1) {
	//		cout << "Source country found. " << i->getName() << endl;
	//		cout << "Moving forces from " << i->getName() << " to " << target->getName() << endl;

	//		Fortify phase(player);

	//		phase.fortifyCountry(i, target);
	//	}
	//}

	//cout << "End of fortification phase." << endl;

}

//returns index of largest army in player owned countries
int Aggressive::findStrongestCountry() {
	int index = 0;
	int largestArmy = 0;
	//loops through countries owned, finds strongest and sets choice to index of strongest country from "getCountriesOwned"
	for (int i = 0; i < player->getCountriesOwned().size(); i++) {
		if (player->getCountriesOwned()[i]->getArmyCount() > largestArmy) {
			largestArmy = player->getCountriesOwned()[i]->getArmyCount();
			index = i;
		}
	}
	return index;
}
