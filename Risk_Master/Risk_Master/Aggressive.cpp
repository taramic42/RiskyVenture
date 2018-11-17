#include "Aggressive.h"
#include "../../Risk/Phases/ReinforcePhase.h"


Aggressive::Aggressive(){}


Aggressive::~Aggressive()
{
	
}



void Aggressive::reinforce(Deck* Deck, Player* Player) {
	
	deck = Deck;
	player = Player;

	std::cout << "Player " << player->getId() << " is currently playing as the aggressive strategy." << endl;
	std::cout << "Reinforce phase begins. Finding adjacent country to fortify." << endl;


	int choice = 0;
	
	//loops through countries owned, finds strongest and sets choice to index of strongest country from "getCountriesOwned"

	for (int i = 0; i < player->getCountriesOwned().size(); i++) {
		if (i + 1 == player->getCountriesOwned().size())
			break;

		if (player->getCountriesOwned()[i]->getArmyCount() > player->getCountriesOwned()[i + 1]->getArmyCount()) {
			choice = i;
		}
		else {
			choice = i + 1;
		}
	}

	std::cout << "Country with most armies found " << player->getCountriesOwned()[choice]->getName() << endl;
	std::cout << "Army count " << player->getCountriesOwned()[choice]->getName() << endl;

	setStrongest(choice);

	ReinforcePhase phase(player);

	
	phase.cardExchange(deck, player->getHand());

	phase.placeArmies(player->getArmiesLeftToPlaceOnBoard(), choice);

	std::cout << "Reinforce phase ends." << endl << endl;

}

void Aggressive::attack() {

	std::cout << "Beginning of Aggressive Attack Phase." << endl;


	vector<Country*> strongestCountryBorders = player->getCountriesOwned()[strongestCountry]->getBorderCountries();
	
	Country* attackFrom = player->getCountriesOwned()[strongestCountry];

	Country* attackTarget;
	
	for (auto i : strongestCountryBorders) {
		if (player->getId() != i->getOwner()) {
			attackTarget = i;
		}
		else {
			std::cout << "No border countries to attack." << endl;
			std::cout << "Attack Phase ends." << endl << endl;
		}
	}

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
