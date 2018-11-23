#include "AttackPhase.h"

AttackPhase::AttackPhase() {
}

AttackPhase::~AttackPhase() {}

AttackPhase::AttackPhase(Player &player, vector<Player*> players) : thePlayer(&player) {

	for (int i = 0; i < players.size(); i++)
		playerList.push_back(players[i]);
	prompt();
}

AttackPhase::AttackPhase(Player &player, vector<Player*> players, Country* source, Country* targ) {
	thePlayer = &player;
	for (int i = 0; i < players.size(); i++)
		playerList.push_back(players[i]);
	begAIAssult(source, targ);
}

void AttackPhase::setPlayer(Player & player)
{
	thePlayer = &player;
}

using namespace std;

//For AI(Aggressive)//////////////////////////////////////////////////////////////////////////
void AttackPhase::begAIAssult(Country* srcCount, Country* targCount) {
	successfullyConquered = false;
	while (!successfullyConquered) {
		//finds the Maximum assult troops to send and Maximum troops to defend
		int maxInvade;
		int maxDefend;
		if (srcCount->getArmyCount() < 2) {
			cout << "No more armies to attack from " << srcCount->getName() << endl;
			successfullyConquered = true;
			return;
		}

		if (srcCount->getArmyCount() > 3) {
			maxInvade = 3;
		}
		else {
			maxInvade = srcCount->getArmyCount() - 1;
		}
		if (targCount->getArmyCount() >= 2) {
			maxDefend = 2;
		}
		else {
			maxDefend = targCount->getArmyCount();
		}

		//Roll attacker dice
		cout << "\n>>>>>>>>>>>>>>>>>>Your troopaloops from " << srcCount->getName() << " are now attacking " << targCount->getName() << "..." << endl;
		cout << "       " << srcCount->getName() << "-" << " has " << srcCount->getArmyCount() << " army/armies" << endl;
		cout << "       " << targCount->getName() << "-" << " has " << targCount->getArmyCount() << " army/armies" << endl;
		cout << "Result of rolls for the Attacking Country " << srcCount->getName() << ":" << endl;
		thePlayer->getDice()->diceRolling(maxInvade);
		//Roll defender dice
		cout << "Result of rolls for the Defending Country " << targCount->getName() << ":" << endl;
		playerList[targCount->getOwner()]->getDice()->diceRolling(maxDefend);
		cout << "------------------------------------------------------------------------------------------------------------------\n" << endl;


		int result;
		//Determine result
		result = thePlayer->getDice()->resultOfBattle(maxInvade, maxDefend, *(playerList[targCount->getOwner()]->getDice()));
		analy(result, srcCount, targCount);
	}//end while
	return;
}

void AttackPhase::prompt() {

	while (1) {
		cout << "Would you like to attack?" << endl;
		cout << "Input \"y\" to attack or \"n\" to skip attack phase." << endl;
		cout << endl;

		char choice;
		cin >> choice;

		if (choice == 'n') {
			cout << "Attack phase over." << endl;
			return;
		}
		else if (choice == 'y') {
			//put main attack and choice logic here

			int countryIndex = displayAndChooseCountry();
			attackFromCountry(countryIndex - 1);
			return;
		}
		else {
			cout << "Invalid choice" << endl;
			cout << "Input \"y\" to attack or \"n\" to skip attack phase." << endl;
			cout << endl;
		}
	}
}


int AttackPhase::displayAndChooseCountry() {

	cout << "Which country would you like to attack from?" << endl;
	cout << endl;

	int count = 1;

	for (int i = 0; i < thePlayer->getCountriesOwned().size(); i++) {
		if (thePlayer->getCountriesOwned()[i]->getArmyCount() > 1) {

			cout << count << " " << thePlayer->getCountriesOwned()[i]->getName() << endl;

			//fill eligibleCountries container
			eligibleCountries.push_back(thePlayer->getCountriesOwned()[i]);

			count++;
		}
	}

	int choice;

	do {
		cin.clear();
		cin.ignore();

		cin >> choice;

		if (cin.fail() || choice < 1 || choice > eligibleCountries.size())
			cout << "Please be sure that the value entered is a integer in the range of 1 to " << eligibleCountries.size() << endl;

	} while (cin.fail() || choice < 1 || choice > eligibleCountries.size());

	return choice;

}



void AttackPhase::attackFromCountry(int fromCountry) {
	//display adjacent list

	int size = eligibleCountries[fromCountry]->getNumberOfBorderingCountries();

	vector<Country*> eligibleTargets;

	for (int i = 0; i < size; i++)
		if (eligibleAdjacentCountries(eligibleCountries[fromCountry], eligibleCountries[fromCountry]->travel(i)))
			eligibleTargets.push_back(eligibleCountries[fromCountry]->travel(i));

	cout << "Please choose a country to attack: " << endl;
	for (int i = 0; i < eligibleTargets.size(); i++)
		cout << i << " -> " << eligibleTargets[i]->getName() << endl;

	//get user input
	int choice;

	if (eligibleTargets.size() > 0) {
		do {
			cin.clear();
			cin.ignore();

			cin >> choice;

			if (cin.fail() || choice < 0 || choice >= eligibleTargets.size())
				cout << "Invalid choice, try again" << endl;

		} while (cin.fail() || choice < 0 || choice >= size);

		char command;
		int armyAmount;
		int defenderAmount;
		int result;
		do {
			cout << eligibleCountries[fromCountry]->getName() << " has " << eligibleCountries[fromCountry]->getArmyCount() << " armies." << endl;
			cout << eligibleTargets[choice]->getName() << " has " << eligibleTargets[choice]->getArmyCount() << " armies." << endl;
			cout << "How many armies do you want to send from " << eligibleCountries[fromCountry]->getName() << "? (Between 1 and 3 inclusive)(Enter 0 to cancel attack)" << endl;

			do {
				cin.clear();
				cin.ignore();

				cin >> armyAmount;

				//Check that int is valid
				if (cin.fail() || armyAmount < 0 || armyAmount>3)
					cout << "Invalid choice, try again." << endl;
				//Check that enough armies exist to be sent
				if (!cin.fail() && armyAmount > (eligibleCountries[fromCountry]->getArmyCount() - 1))
					cout << "You do not have enough armies in " << eligibleCountries[fromCountry]->getName() << " to send that many." << endl;

			} while (cin.fail() || armyAmount < 0 || armyAmount>3 || armyAmount > eligibleCountries[fromCountry]->getArmyCount() - 1);

			cout << "Will 1 or 2 armies defend " << eligibleTargets[choice]->getName() << "?" << endl;

			do {
				cin.clear();
				cin.ignore();

				cin >> defenderAmount;

				//Check that int is valid
				if (cin.fail() || defenderAmount < 1 || defenderAmount>2)
					cout << "Invalid choice, try again." << endl;
				//Check that enough armies exist to be sent
				if (!cin.fail() || defenderAmount > eligibleTargets[choice]->getArmyCount())
					cout << "Not enough armies in " << eligibleTargets[choice]->getName() << " for that many." << endl;

			} while (cin.fail() || defenderAmount < 1 || defenderAmount>2 || defenderAmount > eligibleTargets[choice]->getArmyCount());

			//attack logic+dice
			if (armyAmount > 0) {

				//Roll attacker dice
				cout << "Result of rolls for the Attacking Country " << eligibleCountries[fromCountry]->getName() << endl;
				thePlayer->getDice()->diceRolling(armyAmount);
				//Roll defender dice
				cout << "Result of rolls for the Defending Country " << eligibleTargets[choice]->getName() << endl;
				playerList[eligibleTargets[choice]->getOwner()]->getDice()->diceRolling(defenderAmount);

				//Determine result
				result = thePlayer->getDice()->resultOfBattle(armyAmount, defenderAmount, *(playerList[eligibleTargets[choice]->getOwner()]->getDice()));

				//change army counts
				if (armyAmount > 1 && eligibleTargets[choice]->getArmyCount() > 1)
					//Both att and def have more than 1 army
					if (result == 0) {
						//Both countries lose an army
						eligibleCountries[fromCountry]->addArmies(-1);
						eligibleTargets[choice]->addArmies(-1);
					}

					else if (result > 0) {
						//Defenders lose 2 armies
						if (eligibleTargets[choice]->getArmyCount() > 1)
							eligibleTargets[choice]->addArmies(-2);
						else
							eligibleTargets[choice]->addArmies(-1);
					}
					else {
						//Attacker loses 2 armies
						eligibleCountries[fromCountry]->addArmies(-2);
					}
				else
					//One or the other has 1 army
					if (result > 0) {
						//Defender loses 1 army
						eligibleTargets[choice]->addArmies(-1);
					}
					else {
						//Attacker loses 1 army
						eligibleCountries[fromCountry]->addArmies(-1);
					}

			}
			if (eligibleTargets[choice]->getArmyCount() == 0) {
				//Attacker has conquered country
				cout << eligibleTargets[choice] << " successfully conquered." << endl;
				conquerCountry(eligibleTargets[choice]);
				//Move armies from origin to conquered country

				do {
					cout << "Please choose the number of armies to send to " << eligibleTargets[choice]->getName() << endl;

					cin.clear();
					cin.ignore();

					cin >> armyAmount;

					if (cin.fail())
						cout << "Invalid input. Try again." << endl;
					else if (armyAmount<1 || armyAmount>eligibleCountries[fromCountry]->getArmyCount() - 1)
						cout << "Invalid amount (likely not enough armies to send). Allowable range: 1 to" << eligibleCountries[fromCountry]->getArmyCount() - 1 << endl;

				} while (cin.fail() || armyAmount<1 || armyAmount>eligibleCountries[fromCountry]->getArmyCount() - 1);

				//Move armies
				eligibleCountries[fromCountry]->addArmies(-armyAmount);
				eligibleTargets[choice]->addArmies(armyAmount);
				command = 'n';

			}
			else if (eligibleCountries[fromCountry]->getArmyCount() == 1) {

				//Attacker only has 1 army left in origin country
				cout << "You only have 1 army left in " << eligibleCountries[fromCountry]->getName() << ". Ending attack phase." << endl;
				command = 'n';
			}
			else {
				//ask for continuence
				cout << "Enter y or Y to continue attacking. Enter anything else to end attack phase." << endl;

				cin >> command;
			}

		} while (command == 'y' || command == 'Y');
	}
	else
		cout << "You own all countries that border " << eligibleCountries[fromCountry]->getName() << endl;


}

bool AttackPhase::eligibleAdjacentCountries(Country* origin, Country* target) {
	//check that origin has different
	if (origin->getOwner() == target->getOwner())
		return false;

	//check that target is next to origin
	for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
		if (origin->travel(i)->getName() == target->getName())
			return true;

	return false;
}

void AttackPhase::conquerCountry(Country * target)
{
	int defenderId = target->getOwner();
	playerList[defenderId]->removeCountry(target->getName());
	thePlayer->addCountry(target);

}


void AttackPhase::analy(int res, Country* srcCount, Country* targCount) {
	switch (res) {
	case -2:
		cout << "   ******************************************************" << endl;
		cout << "   *   RESULT OF BATTLE: Lost ~~~ You lost 2 armies ~~~ *" << endl;
		cout << "   ******************************************************" << endl;
		srcCount->addArmies(-2);
		break;
	case -1:
		cout << "   ******************************************************" << endl;
		cout << "   *   RESULT OF BATTLE: Lost ~~~ You lost 1 army ~~~   *" << endl;
		cout << "   ******************************************************" << endl;
		srcCount->addArmies(-1);
		break;
	case 0:
		cout << "   ******************************************************************************" << endl;
		cout << "   *   RESULT OF BATTLE: Tie ~~~ You lost 1 army/ defender has lost 1 army ~~~  *" << endl;
		cout << "   ******************************************************************************" << endl;
		targCount->addArmies(-1);
		srcCount->addArmies(-1);
		break;
	case 1:
		cout << "   ************************************************************" << endl;
		cout << "   *   RESULT OF BATTLE: Won ~~~ Defender has lost 1 army ~~~ *" << endl;
		cout << "   ************************************************************" << endl;
		targCount->addArmies(-1);
		break;
	case 2:
		cout << "   **************************************************************" << endl;
		cout << "   *   RESULT OF BATTLE: Won ~~~ Defender has lost 2 armies ~~~ * " << endl;
		cout << "   **************************************************************" << endl;
		targCount->addArmies(-2);
		break;
	}

	if (targCount->getArmyCount() == 0) {
		conquerCountry(srcCount, targCount);
		successfullyConquered = true;
	}

	//if (srcCount->getArmyCount() < 2) {
	//	//If the attacking country has less than 2 armies
	//	//must exit inner loop from attackPhasePromt and "restart" dialog...
	//	//cout << "There are no longer enough armies in " << eligibleCountries[attCon]->getName() << " to attack" << endl;
	//	//flag = false;
	//}

}

//overloaded to work with AI(Aggressive)
void AttackPhase::conquerCountry(Country* source, Country* target)
{
	cout <<
		"\n____________________________________________________________________________________________\n\n"
		"++++++++++++++++++++++++++++++ YOU HAVE CONQUERED: " << target->getName() << "  +++++++++++++++++++++++++++++++++" <<
		"\n___________________________________________________________________________________________\n" << endl;
	cout << "--> You have conquered " << target->getName() << " from Player " << target->getOwner() + 1 << endl;
	int defenderId = target->getOwner();
	playerList[defenderId]->removeCountry(target->getName());
	thePlayer->addCountry(target);



	cout << "--> You now have a total of " << source->getArmyCount() << " armies in " << source->getName() << endl;
	cout << "--> Sending 1 army to occupy " << target->getName() << endl;

	source->addArmies(-1);
	target->addArmies(1);
	return;
}
