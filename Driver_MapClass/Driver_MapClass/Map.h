#pragma once
#include <vector>
#include "Continent.h"

class Map
{
public:
	Map();
    void addContinent(Continent cont);
    void addCountry(Country coun);
    void connectObjects();
    bool validGraph();
	void display();

private:
	std::vector<Continent> continent;
	std::vector<Country> country;
};

