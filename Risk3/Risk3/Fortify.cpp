#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Fortify.h"
using namespace std;

Fortify::Fortify() {}
Fortify::~Fortify() {}

Fortify::Fortify(Player &player) : player(&player) {}

void Fortify::displayOwnedCountries() {

	//displays all the countries owned with the i+1 for a menu choice
	for (int i = 0; i < player->getNumberOfOwnedCountries(); i++) {
		cout << i + 1 << "." << player->getCountriesOwned()[i]->getName() << endl;
	}
}

void Fortify::setOrigin()
{
	vector <Country*>pc1 = player->returnAll();
	string countryName;
	cout << "enter which country you would like to originate from\n";
	cin >> countryName;
	bool c = false;
	for (int i = 0; i < pc1.size(); i++)
	{
		if (pc1[i]->getName() == countryName)
		{
			player->setOrigin(pc1[i]);
			cout << "Origin set to: " << countryName << endl << endl;
			c = true;
		}
	}
	if (!c)
	{
		cout << "You do not have this country try again!\n";
		cin >> countryName;
		for (int i = 0; i < pc1.size(); i++)
		{
			if (pc1[i]->getName() == countryName)
			{
				player->setOrigin(pc1[i]);
				cout << "Origin set to: " << countryName << endl << endl;
				c = true;
			}
		}
	}
}

void Fortify::fortifyCountry()
{
	Country* origin = player->getOrigin();

	cout << "Adjacent countries to " << origin->getName() << endl << endl;
	vector <Country*>pc1 = player->returnAll();
	

	vector<Country*>adjacent;

	for (int j = 0; j < pc1.size(); j++)
	{
		for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
		{
			if (pc1[j]->getName() == origin->travel(i)->getName())
			{
				adjacent.push_back(origin->travel(i));
			}
			else continue;
		}
	}


	if (adjacent.size() > 0) {
		for (int j = 0; j < pc1.size(); j++)
		{
			for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
			{
				if (pc1[j]->getName() == origin->travel(i)->getName())
					cout << origin->travel(i)->getName() << endl;
				else continue;
			}
		}

		cout << "\nEnter which country you would like to fortify\n";
		string fcountry;
		cin >> fcountry;

		int army;
		cout << "\nEnter how many armies you would like to send:\n";
		cin >> army;
		while (army > player->getTotalArmies() - 1) {
			cout << "Not enough armied. Try again\n";
			cin >> army;
		}

		bool c = false;
		for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
		{
			if (origin->travel(i)->getName() == fcountry)
			{
				player->fortify(origin->travel(i), army);
				player->setTarget(origin->travel(i));
				cout << army << " armies has been sent to " << fcountry << endl;
				c = true;
			}

		}

		if (!c)
		{
			cout << "this country is not adjacent try again!\n";
			cin >> fcountry;
			for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
			{
				if (origin->travel(i)->getName() == fcountry)
				{
					player->fortify(origin->travel(i), army);
					player->setTarget(origin->travel(i));
					cout << army << " armies has been sent to " << fcountry << endl;
					c = true;

				}
			}
		}

	}
}
void Fortify::prompt()
{

	cout << "Your countries:\n";
	if (player->getNumberOfOwnedCountries() == 0)
		cout << "No countries\n";
	else
	{
		displayOwnedCountries();
	}

	setOrigin();

	Country* origin = player->getOrigin();
	if (origin == NULL)
	{
		cout << "no origin set\n";
		setOrigin();

	}
	if (player->getTotalArmies() <= 1)
	{
		cout << "Not enough armies to fortify!\n";

	}
	else
	{
		fortifyCountry();

		cout << "You now have a total of " << player->getTotalArmies() << " left.\n\n";
	}


}




