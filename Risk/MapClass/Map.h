#pragma once
#include <vector>
#include "Continent.h"

class Map
{
public:
	//Constructors
	Map();
	Map(std::vector<std::string> lineList);
	Map(std::string file);

	//Getter Methods
    Country* getCountry(int i);
	Continent* getContinent(int i);
	int numberOfContinents();
    int size();

	//Utility Methods
    void addContinent(Continent cont);
    void addCountry(Country coun);
    void connectObjects();
    bool validGraph();
	bool connectedMap(Country start);
	bool connectedSubGraph(Continent target);
	bool allLinksAreTwoWay();
	void display();

private:
	std::vector<Continent> continent;
	std::vector<Country> country;

	bool isDefault;

	bool inVectorList(std::vector<Country> list, Country count);
};

