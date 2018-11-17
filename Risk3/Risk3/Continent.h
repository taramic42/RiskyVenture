#pragma once
#include <vector>
#include "Country.h"

class Continent
{
public:
	//Constructors
	Continent();
	Continent(std::string str, int bonusVal);
	Continent(std::string line);

	//Getters
	int getBonus() const;
	std::string getName() const;

	//Utility methods
	Country travel(int index);
	int size();

	void addCountry(Country* coun);
	void emptyCountryList();

	void display();

private:
	std::string name;
	int bonus;
	std::vector<Country*> countryList;
};

