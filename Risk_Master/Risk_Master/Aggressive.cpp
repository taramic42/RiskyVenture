#include "Aggressive.h"


Aggressive::Aggressive() : Strategy(){}


Aggressive::~Aggressive()
{
	
}



void Aggressive::s_reinforce(Deck* Deck, Player* Player) {
	
	deck = Deck;
	player = Player;

	vector<Country*> borderCountries;

	std::cout << "Player " << player->getId() << " is currently playing as the aggressive strategy." << endl;
	std::cout << "Reinforce phase begins. Finding adjacent country to fortify." << endl;


	int choice = 0;

	//build list of countrys that have potential targets to reinforce them
	vector<Country*> reinforceList;

	//check to see if the player has a bordering country that does not belong to him to reinforce
	for (int i = 0; i < player->getNumberOfOwnedCountries(); i++) {
		for (int j = 0; player->getCountriesOwned()[i]->getBorderCountries().size(); j++) {
			if (player->getId() != player->getCountriesOwned()[i]->getBorderCountries()[j]->getOwner()) {
				reinforceList.push_back(player->getCountriesOwned()[i]);
			}
		}
	}

	for (int i = 0; i < reinforceList.size(); i++) {
		if (i + 1 > reinforceList.size())
			break;
		if (reinforceList[i]->getArmyCount() > reinforceList[i + 1]->getArmyCount()) {
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
	//AttackPhase phase();

}

void Aggressive::fortify() {

	//TODO

	std::cout << "Fortify phase begins. Finding country with most armies to fortify." << endl;

}

void Aggressive::setStrongest(int choice)
{
	strongestCountry = choice;
}
