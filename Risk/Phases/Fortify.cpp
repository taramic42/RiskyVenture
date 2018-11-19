#include "Fortify.h"

using namespace std;

Fortify::Fortify() {}
Fortify::~Fortify() {}

Fortify::Fortify(Player *player) : player(player) {}


void Fortify::fortifyCountry(int armies)
{
	int armiesToMove = armies;
	m_origin->addArmies(armiesToMove);

	m_target->addArmies(-armiesToMove);
}


void Fortify::prompt()
{
	cout << "Beginning of fortification phase." << endl;

	bool loopFlag = true;

	while (loopFlag) {

		int choice = 0;
		m_origin = NULL;
		m_target = NULL;
\
		cout << "Which country would you like to fortify?" << endl;

		//display list of elegible countries that have neighboring countries with armies greater than 1
		vector<Country*> eligibleCountries = getElegibleCountries();

		for (int i = 0; i < eligibleCountries.size(); i++) {
			cout << i + 1 << " " << eligibleCountries[i]->getName()<<" Total armies " << eligibleCountries[i]->getArmyCount() << endl;
		}

		cin >> choice;
		choice--;

		if (choice >= 0 && choice < eligibleCountries.size()) {
			m_origin = eligibleCountries[choice];
		}

		cout << "Your origin country chosen to fortify is " << m_origin->getName() << endl;

		cout << "Choose from the list of elegible countries to take armies from." << endl;

		vector<Country*> eligibleBorderCountry = getElegibleTargetCountries();

		for (int i = 0; i < eligibleBorderCountry.size(); i++) {
			cout << i + 1 << " " << eligibleBorderCountry[i]->getName() << " Total armies: " << eligibleBorderCountry[i]->getArmyCount() << endl;
		}

		cin >> choice;
		choice--;


		if (choice >= 0 && choice < eligibleBorderCountry.size()) {
			m_target = eligibleBorderCountry[choice];
		}

		cout << "Your target country chosen to move armies from is " << m_target->getName() << endl;

		cout << "How many armies would you like to displace?" << endl;

		cin >> choice;

		if (choice < m_target->getArmyCount()) {
			cout << "Valid input. Armies moved." << endl;
			fortifyCountry(choice);
			cout << "Origin country's new amount of armies. " << m_origin->getArmyCount() << endl;
			cout << "Target country's new amount of armies. " << m_target->getArmyCount() << endl;
		}
		else {
			cout << "Invalid input." << endl;
		}

		cout << "Would you like to fortify another country?" << endl;
		cout << "To continue input 'y', to end fortification phase enter anything" << endl;
		char answer;
		cin >> answer;

		if (answer == 'y')
			loopFlag = true;
		else
			loopFlag = false;
	}
}


void Fortify::setTotalArmiesOnCountries()
{
	totalArmiesOnCountries = 0;

	for (auto i : player->getCountriesOwned()) {
		totalArmiesOnCountries += i->getArmyCount();
	}
}

void Fortify::fortifyCountry(Country* origin, Country * target)
{
	int armiesToMove = origin->getArmyCount() - 1;
	origin->addArmies(-armiesToMove);

	target->addArmies(armiesToMove);
}

vector<Country*> Fortify::getElegibleCountries()
{
	vector<Country*> eligibleCountries;

	for (int i = 0; i < player->getCountriesOwned().size(); i++) {
		
		for (int j = 0; j < player->getCountriesOwned()[i]->getBorderCountries().size(); j++) {

			if (player->getId() == player->getCountriesOwned()[i]->getBorderCountries()[j]->getOwner()) {

				if (player->getCountriesOwned()[i]->getBorderCountries()[j]->getArmyCount() > 1) {

					eligibleCountries.push_back(player->getCountriesOwned()[i]);
					
				}
			}
		}	
	}

	//removes duplicates
	auto end = eligibleCountries.end();
	for (auto it = eligibleCountries.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}

	eligibleCountries.erase(end, eligibleCountries.end());

	return eligibleCountries;
}

vector<Country*> Fortify::getElegibleTargetCountries()
{
	vector<Country*> eligibleTargetCountries;

	for (int i = 0; i < m_origin->getBorderCountries().size(); i++) {
		if (player->getId() == m_origin->getBorderCountries()[i]->getOwner() && m_origin->getBorderCountries()[i]->getArmyCount() > 1) {
			eligibleTargetCountries.push_back(m_origin->getBorderCountries()[i]);
		}
	}

	return eligibleTargetCountries;

}



