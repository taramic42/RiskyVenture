#pragma once
#include <vector>

class Country
{
public:
	//Constructors
	Country();
	Country(std::string countryName,int x, int y, std::string continentName, std::string border);
    Country(std::string line);

	//Getters
	int getOwner() const;
	int getNumberOfBorderingCountries() const;
	std::string getContinentName() const;
	std::string getName() const;
	int getArmyCount() const;
	std::string getBorderString() const;

	//Setters
	void setArmyCount(int num);
	void setOwner(int ID);

	//Utility methods
	Country* travel(int index);
	Country* travel(std::string name);
	void addCountryToBorder(Country* otherCountry);
	void addArmies(int num);

	void emptyBorder();

	bool nextTo(Country otherCountry);

	void displayBorderCountries();
    
    void display();

	//for aggressive strategy class
	std::vector<Country*> getBorderCountries();

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

