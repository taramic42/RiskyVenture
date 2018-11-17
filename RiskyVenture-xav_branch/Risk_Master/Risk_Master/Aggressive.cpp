#include "Aggressive.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/AttackPhase.h"


Aggressive::Aggressive(){}


Aggressive::~Aggressive()
{
	
}



void Aggressive::reinforce(Deck* Deck, Player* Player) {
	
	deck = Deck;
	player = Player;

	std::cout << "Player " << player->getId() + 1 << " is currently playing as the aggressive strategy." << endl;
	std::cout << "Reinforce phase begins. Finding adjacent country to fortify." << endl;


	std::cout << "\n  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING " << endl;
	for (int i = 0; i < player->getCountriesOwned().size(); i++) {
		std::cout << "Country name " << player->getCountriesOwned()[i]->getName() << endl;
		std::cout << "Army count " << player->getCountriesOwned()[i]->getArmyCount() << endl;
	}
	std::cout << "\n  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING  TESTING " << endl;


	//int choice = 0;
	//
	////loops through countries owned, finds strongest and sets choice to index of strongest country from "getCountriesOwned"

	//for (int i = 0; i < player->getCountriesOwned().size(); i++) {
	//	if ( i + 1 == player->getCountriesOwned().size())
	//		break;

	//	if (player->getCountriesOwned()[i]->getArmyCount() > player->getCountriesOwned()[i + 1]->getArmyCount()) {
	//		choice = i;
	//	}
	//	else {
	//		choice = i + 1;
	//	}
	//}
	//

	//int choice = findStrongestCountry();






	int index = findStrongestCountry();
	setStrongest(index);
	std::cout << "Country with most armies found " << player->getCountriesOwned()[index]->getName() << endl;
	std::cout << "Army count " << player->getCountriesOwned()[index]->getName() <<  " " << player->getCountriesOwned()[index]->getArmyCount() << endl;

	

	ReinforcePhase phase(player);

	
	phase.cardExchange(deck, player->getHand());

	phase.placeArmies(player->getArmiesLeftToPlaceOnBoard(), index);
	std::cout << "Moved army "<< endl;

	//std::cout << "Army count " << player->getCountriesOwned()[choice]->getName() << " " << player->getCountriesOwned()[choice]->getArmyCount() << endl;

	std::cout << "Reinforce phase ends." << endl << endl;

}

void Aggressive::attack(Player* player, vector<Player*> playerList) {
	player = player;

	std::cout << "\n\n#############Beginning of Aggressive Attack Phase.#############\n\n" << endl;
	int index = findStrongestCountry();
	setStrongest(index);
	std::cout << "This is my strongest country: " << player->getCountriesOwned()[strongestCountry]->getName() <<  endl;
	std::cout << "Size of it's army: " << player->getCountriesOwned()[strongestCountry]->getArmyCount() << endl;

	
	vector<Country*> strongestCountryBorders = player->getCountriesOwned()[strongestCountry]->getBorderCountries();
	
	

	//Use to test eneglible targets
	/*for (int i = 0; i < strongestCountryBorders.size(); i++) {
		std::cout << "Owner " << strongestCountryBorders[i]->getOwner()+1 << endl;
	}
*/

	Country* attackFrom = player->getCountriesOwned()[strongestCountry];

	Country* attackTarget;

	int num =0;
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
				AttackPhase(*player, playerList, attackFrom, attackTarget);
			}
			else {
				std::cout << "You no longer have enough armies in "<< attackTarget->getName() << endl;
				return;
			}
			
		}
		
	}

	std::cout << "No border countries to attack." << endl;
	std::cout << "Attack Phase ends." << endl << endl;

	//need TODO this
	//AttackPhase phase = AttackPhase(attackFrom, attackTarget);

}

void Aggressive::fortify() {

	//TODO

	std::cout << "Fortify phase begins. Finding country with most armies to fortify." << endl;

}

void Aggressive::setStrongest(int choice)
{
	strongestCountry = choice;
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
