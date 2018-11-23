#include "Passive.h"


Passive::Passive() {}
Passive::~Passive() {}

void Passive::reinforce(Deck* deck, Player* player)
{
	cout << "Player " << player->getId()+1 << " is currently playing as the passive strategy." << endl;

	if (player->getArmiesLeftToPlaceOnBoard() > 0)
	{
		cout << "Searching for country with least armies to reinforce.\n" << endl;

		vector < Country * > countries = player->getCountriesOwned();
		Country* least = countries[0];
		for (int i = 1; i < countries.size(); i++)
			if (countries[i]->getArmyCount() < countries[i - 1]->getArmyCount())
				least = countries[i];
		cout << "country found\n";

		Country* most = countries[0];
		for (int i = 1; i < countries.size(); i++)
			if (countries[i]->getArmyCount() > countries[i - 1]->getArmyCount())
				most = countries[i];

		least->addArmies(most->getArmyCount());
		player->addArmiesToPlaceOnBoard(-(most->getArmyCount()));

			cout <<most->getArmyCount()<<" arimes were added to "<<least->getName()<< endl;
	}
	
	cout << "\nReinforce phase ends." << endl << endl;
}
void Passive::attack(Player*, vector<Player*> list)
{
	cout << "no attack phase for passive player\n" << endl;
}

void Passive::fortify(Player* player)
{
	cout << "Fortify phase begins." << endl;

	
		vector < Country * > countries = player->getCountriesOwned();

		Country* most = countries[0];
		for (int i = 1; i < countries.size(); i++)
			if (countries[i]->getArmyCount() > countries[i - 1]->getArmyCount())
				most = countries[i];


		vector<Country*>adjacent;

		for (int j = 0; j < countries.size(); j++)
		{
			for (int i = 0; i < most->getNumberOfBorderingCountries(); i++)
			{
				if (countries[j]->getName() == most->travel(i)->getName())
				{
					adjacent.push_back(most->travel(i));
				}
				else continue;
			}
		}


		if (adjacent.size() >= 1)
		{
			/*for (int i = 0; i < adjacent.size(); i++)
				cout << adjacent[i]->getName() << endl;*/

			Country* leastAdjacent = adjacent[0];

			if (adjacent.size() > 1)
				for (int i = 1; i < adjacent.size(); i++)
					if (adjacent[i]->getArmyCount() < adjacent[i - 1]->getArmyCount())
						leastAdjacent = adjacent[i];

			int numOfArmies = most->getArmyCount();
			leastAdjacent->addArmies(numOfArmies / 2);
			player->addArmiesToPlaceOnBoard(-(numOfArmies / 2));
			cout << "country found\n";
			cout << (numOfArmies / 2) << " armies were moved from " << most->getName() << " to " << leastAdjacent->getName() << endl;
		}

	cout << "Fortify phase ends." << endl << endl;
}

void Passive::setPlayer(Player *p)
{
	player = p;
}
void Passive::setPlayerList(vector <Player*> list) {}

