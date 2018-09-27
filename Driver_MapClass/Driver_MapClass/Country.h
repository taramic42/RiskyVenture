#pragma once
#include <vector>

class Country
{
public:
	Country();
	Country(std::string countryName,int x, int y, std::string continentName, std::string border);
    Country(std::string line);

	int getOwner() const;
	int getNumberOfBorderingCountries() const;
	std::string getContinentName() const;

	Country travel(int index);
	Country travel(std::string name);
	void addCountryToBorder(Country* otherCountry);

	bool nextTo(Country otherCountry);

	void displayBorderCountries();
    
    void display();

private:
	std::string name;
	std::string continent;
    std::string borderString;
    int posX;
    int posY;
	int armyCount;
	int owner;
	int linkedCountries;
	std::vector<Country*> borderCountries;

};

