#include "ReinforcePhase.h"

using namespace std;

ReinforcePhase::ReinforcePhase() {}
ReinforcePhase::~ReinforcePhase() {}

ReinforcePhase::ReinforcePhase(Player *player) : thePlayer(player) {
}

ReinforcePhase::ReinforcePhase(Player *player, Deck* adeck) : thePlayer(player) {
	//cardExchange(adeck, thePlayer->getHand());
	getArmies();
	//placeArmies(thePlayer->getArmiesLeftToPlaceOnBoard());
	prompt();
}

void ReinforcePhase::getArmies() {

	int size = thePlayer->getNumberOfOwnedCountries();

	if (size > 0) {
		if (size < 9) {
			thePlayer->addArmiesToPlaceOnBoard(3);
		}
		else {
			int temp = floor(size / 3);
			thePlayer->addArmiesToPlaceOnBoard(temp);
		}
	}
}

void ReinforcePhase::getContinentBonus(Map* map) {

	int playerID = thePlayer->getId();
	int totalBonus = 0;

	for (int i = 0; i < map->numberOfContinents(); i++) {

		int count = 0;
		string continentName = map->getContinent(i)->getName();


		for (int j = 0; j < map->getContinent(i)->size(); j++) {
			//note maybe strcmp better
			if (thePlayer->getCountriesOwned()[j]->getContinentName() == continentName) {
				count++;
			}
		}

		if (count == map->getContinent(i)->size()) {
			totalBonus += map->getContinent(i)->getBonus();
		}

	}

	thePlayer->addArmiesToPlaceOnBoard(totalBonus);
}

void ReinforcePhase::placeArmies(int numOfArmies, int countryChoice) {
	//place the armies on the selected country
	thePlayer->getCountriesOwned()[countryChoice]->addArmies(numOfArmies);

	//subract armies held by player by the amount you placed
	thePlayer->addArmiesToPlaceOnBoard(-numOfArmies);

	cout << ">Placed " << numOfArmies << " amry(s) on " << thePlayer->getCountriesOwned()[countryChoice]->getName() << endl;
}


void ReinforcePhase::displayOwnedCountries() {

	//displays all the countries owned with the i+1 for a menu choice
	for (int i = 0; i < thePlayer->getNumberOfOwnedCountries(); i++) {
		cout << i + 1 << "." << thePlayer->getCountriesOwned()[i]->getName() << " - Army size: " << thePlayer->getCountriesOwned()[i]->getArmyCount() << endl;
	}
}

void ReinforcePhase::prompt() {


	int numOfArmies;
	int sel = 0;
	int countryChoice;

	while (1)
	{
		cout << "________________________________________________________________________________________" << endl;
		numOfArmies = thePlayer->getArmiesLeftToPlaceOnBoard();

		if (numOfArmies < 1) {
			cout << "No Armies to place" << endl;
			return;
		}
		cout << "You have " << numOfArmies << " armies that you must place on the board." << endl;
		cout << "Here is the list of counries you own and the number of armies they currently contain: " << endl;
		displayOwnedCountries();
		cout << "Please choose wich country you wish to add troops to:" << endl;

		//displayOwnedCountries()
		cin.clear();
		cin >> countryChoice;
		while (countryChoice > thePlayer->getNumberOfOwnedCountries() || countryChoice < 1 || cin.fail()) {
			cout << "Invalid input must be in range of 1 to " << thePlayer->getNumberOfOwnedCountries() << " try again." << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}

			cin >> countryChoice;
		}

		cout << "How many troops do you want to place on " << thePlayer->getCountriesOwned()[countryChoice - 1]->getName() << "?" << endl;
		cin.clear();
		cin >> sel;
		while (sel > numOfArmies || sel <= 0 || cin.fail()) {
			cout << "Invalid input try again." << endl;
			cout << "You have " << numOfArmies << " armies that you must place on the board." << endl;
			cout << "How many troops do you want to place on " << thePlayer->getCountriesOwned()[countryChoice - 1]->getName() << "?" << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cin >> sel;
		}
		//subtract 1 from countryChoice so you don't go out of bounds
		placeArmies(sel, countryChoice - 1);


	}//end while

}

void ReinforcePhase::cardExchange(Deck* d, Hand* h) {

	if (h->handSize() >= 5)
	{
		int armies = h->exchange(*d);
		thePlayer->addArmiesToPlaceOnBoard(armies);
	}

}