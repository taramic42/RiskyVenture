#include "Aggressive.h"
#include "../../Risk/Phases/ReinforcePhase.h"
#include "../../Risk/Phases/Fortify.h"


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

	setStrongest(index);

	ReinforcePhase phase(player);

	
	phase.cardExchange(deck, player->getHand());

	phase.placeArmies(player->getArmiesLeftToPlaceOnBoard(), index);

	std::cout << "Reinforce phase ends." << endl << endl;

}

void Aggressive::attack() {

	std::cout << "Beginning of Aggressive Attack Phase." << endl;
	//PHIL is doing this
}

void Aggressive::fortify() {

	std::cout << "Fortify phase begins. Finding country with most armies to fortify." << endl;

	int index = 0;
	int largestArmy = 0;


	for (int i = 0; i < player->getCountriesOwned().size(); i++) {
		if (player->getCountriesOwned()[i]->getArmyCount() > largestArmy) {
			largestArmy = player->getCountriesOwned()[i]->getArmyCount();
			index = i;
		}
	}

	Country* target = player->getCountriesOwned()[index];

	std::cout << "Strongest country found. " << target->getName() << endl;
	std::cout << "Searching for adjacent source country." << endl;

	for (auto i : target->getBorderCountries()) {
		if (i->getOwner() == player->getId() && i->getArmyCount() > 1) {
			cout << "Source country found. " << i->getName() << endl;
			cout << "Moving forces from " << i->getName() << " to " << target->getName() << endl;

			Fortify phase(player);

			phase.fortifyCountry(i, target);
		}
	}

	cout << "End of fortification phase." << endl;

}

void Aggressive::setStrongest(int choice)
{
	strongestCountry = choice;
}
