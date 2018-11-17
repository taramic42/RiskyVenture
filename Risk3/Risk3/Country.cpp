#include "Country.h"
#include <sstream>
#include <iostream>


Country::Country() {
	name = "";
	continent = "";
	borderString = "";
	owner = -1;
	linkedCountries = 0;
	armyCount = 1;
}

Country::Country(std::string countryName, int x, int y, std::string continentName, std::string borders) {
	name = countryName;
	continent = continentName;
	posX = x;
	posY = y;
	borderString = borders;
	owner = -1;
	linkedCountries = 0;
	armyCount = 1;
}

Country::Country(std::string line) {

	name = line.substr(0, line.find(","));
	//Removes the first element of line
	line.replace(0, line.find(",") + 1, "");

	posX = stoi(line.substr(0, line.find(",")));

	line.replace(0, line.find(",") + 1, "");

	posY = stoi(line.substr(0, line.find(",")));

	line.replace(0, line.find(",") + 1, "");

	continent = line.substr(0, line.find(","));

	line.replace(0, line.find(",") + 1, "");

	//Given the structure of the data file, a single country cannot belong to more than one continent
	//Any attempt to do so through the .map file would either be ignored or create 2 countries with the same name and connectivity
	borderString = line;

	owner = -1;
	linkedCountries = 0;
	armyCount = 1;
}


int Country::getOwner() const {
	return owner;
}

int Country::getNumberOfBorderingCountries() const {
	return linkedCountries;
}

std::string Country::getContinentName() const {
	return continent;
}

std::string Country::getName() const {
	return name;
}

int Country::getArmyCount() const {
	return armyCount;
}

std::string Country::getBorderString() const {
	return borderString;
}

void Country::setArmyCount(int num) {
	if (num >= 0) {
		armyCount = num;
	}
	else
		std::cout << "Country named " << name << "tried to have " << num << " armies." << std::endl;


}

void Country::setOwner(int ID) {
	owner = ID;
}

Country* Country::travel(int index) {
	if (index >= 0 && index < linkedCountries)
		return borderCountries[index];
	return NULL;
}

Country* Country::travel(std::string name) {

	for (int i = 0; i < borderCountries.size(); i++) {
		if (name.compare(borderCountries[i]->name))
			return borderCountries[i];
	}

	return NULL;
}

void Country::addCountryToBorder(Country* otherCountry) {
	//Adds a pointer to the vector list that points to the location of a defined Country object
	borderCountries.push_back(otherCountry);
	linkedCountries++;
}

void Country::addArmies(int num) {
	armyCount += num;
}

void Country::emptyBorder() {

	while (borderCountries.size() > 0) {
		borderCountries.pop_back();
	}

}

bool Country::nextTo(Country otherCountry) {

	for (int i = 0; i < borderCountries.size(); i++) {
		if (otherCountry.name.compare(borderCountries[i]->name))
			return true;
	}

	return false;
}

void Country::displayBorderCountries() {
	std::cout << borderString << std::endl;
}

void Country::display() {
	std::cout << name << " on " << continent << " has " << armyCount << " armies and is owned by player " << owner << std::endl;
	std::cout << "Bordering countries: ";
	for (int i = 0; i < borderCountries.size(); i++) {
		std::cout << borderCountries[i]->name << "+";
	}
	std::cout << std::endl << std::endl;
}