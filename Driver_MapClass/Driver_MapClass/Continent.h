#pragma once
#include <vector>
#include "Country.h"

class Continent
{
public:
	Continent();
	Continent(std::string str, int bonusVal);
	int getBonus() const;
    
    void addCountry(Country* coun);
    
    void display();
	
private:
    std::string name;
	int bonus;
    std::vector<Country*> countryList;
};

