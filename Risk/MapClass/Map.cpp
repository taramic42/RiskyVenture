#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include "Map.h"
#include "Continent.h"



Map::Map(){
	isDefault = true;
}

//The following constructors assume that the provided information is of correct structure.
//That validation is assumed to be done in the MapLoader
Map::Map(std::vector<std::string> lineList) {

	isDefault = false;

	int i = 0;

	//Iterate through entries until tag [Continents] is found
	while (lineList[i].compare("[Continents]") != 0) {
		i++;
	}

	//Move to next line which should be lines withthe correct structure
	i++;

	//As long as you don't hit an empty line
	while (lineList[i].compare("") != 0) {
		//If the line if not empty
		if (lineList[i].compare("") != 0)
			//Add the continent to your map
			addContinent(lineList[i]);
		//Move to the next line
		i++;
	}
	//Skip past the tag [Territories]
	i+=2;
	
	//For the rest of the lines
	while (i < lineList.size()) {
		//If line is not empty
		if (lineList[i].compare("") != 0)
			//Add country to your map
			addCountry(lineList[i]);
		//Move to next line
		i++;
	}

}

//This constructor acts the same as the previous constructor, but accepts a filepath as the input.
//Once again, the MapLoader is assumed to have accounted for an invalid filepath.
Map::Map(std::string file) {

	isDefault = false;

	std::string line;
	std::vector<std::string> lineList;
	std::ifstream inputFile;
	inputFile.open(file);

	while (!inputFile.eof()) {
		getline(inputFile, line);
		lineList.push_back(line);
	}

	inputFile.close();

	int i = 0;

	//Iterate through entries until tag [Continents] is found
	while (lineList[i].compare("[Continents]") != 0) {
		i++;
	}

	//Move to next line which should be lines withthe correct structure
	i++;

	//As long as you don't hit an empty line
	while (lineList[i].compare("") != 0) {
		//If the line if not empty
		if (lineList[i].compare("") != 0)
			//Add the continent to your map
			addContinent(lineList[i]);
		//Move to the next line
		i++;
	}
	//Skip past the tag [Territories]
	i += 2;

	//For the rest of the lines
	while (i < lineList.size()) {
		//If line is not empty
		if (lineList[i].compare("") != 0)
			//Add country to your map
			addCountry(lineList[i]);
		//Move to next line
		i++;
	}

}

//This getter can be modified to return a pointer to the country object
Country* Map::getCountry(int i){
    if(i >= 0 && i < country.size())
        return &country[i];
    
    return NULL;
}

Continent* Map::getContinent(int i) {
	if (i >= 0 && i < continent.size())
		return &continent[i];

	return NULL;
}

int Map::numberOfContinents()
{
	return continent.size();
}

//Allows continents to be added to the map
void Map::addContinent(Continent cont){
    
    continent.push_back(cont);

}

//Returns the number of countries in the map
int Map::size(){
    
    return country.size();

}

//Allows countries to be added in the map
void Map::addCountry(Country coun){
    
    country.push_back(coun);
    
}


void Map::connectObjects() {

	//Empty all vectors in case mthod is called more often then once
	for (int i = 0; i < continent.size(); i++) {
		continent[i].emptyCountryList();
	}

	for (int i = 0; i < country.size(); i++) {
		country[i].emptyBorder();
	}

    //std::map<std::string, int> is used to fill continents with countries 
	//and country's adjancencies by linking names to an index value
	//This allows the creation of subgraphs to be of O(n) complexity
	//and adjancencies to be O(n^2) complexity
    
	std::map<std::string, int> continentIndex;
	std::map<std::string, int> countryIndex;

	for (int i = 0; i < continent.size(); i++) {
		continentIndex.insert(std::pair<std::string, int>(continent[i].getName(),i));
	}

	for (int i = 0; i < country.size(); i++) {
		countryIndex.insert(std::pair<std::string, int>(country[i].getName(), i));
	}
    
	int locat;

	std::string toLink;
	std::string holdBorderString;

    //Now we go through every country and connect all pointers
	for (int i = 0; i < country.size(); i++) {
		//this finds the index of the continent you want in the vector
		toLink = country[i].getContinentName();
		
		//check to make sure the continent name exists
		if (continentIndex.count(toLink) != 0) {
			locat = continentIndex.find(toLink)->second;
			continent[locat].addCountry(&country[i]);
		}

		//Here's the country border logic
		holdBorderString = country[i].getBorderString();

		//As long as there's something in the borderString
		while (holdBorderString.size()>0) {

			//If there's still a comma in your string
			if (holdBorderString.find(",") != std::string::npos) {

				//Get the next country name to link
				toLink = holdBorderString.substr(0, holdBorderString.find(","));

				//Find it's index if it exists and link otherwise ignore the country
				if (countryIndex.count(toLink) != 0) {
					locat = countryIndex.find(toLink)->second;
					holdBorderString.replace(0, holdBorderString.find(",") + 1, "");
				}
			}
			//If there's no comma in you string
			else {
				//Find it's index if it exists and link otherwise ignore the country
				if (countryIndex.count(holdBorderString) != 0) {
					locat = countryIndex.find(holdBorderString)->second;
					holdBorderString.replace(0, holdBorderString.size(), "");
				}
			}
			//Add the country to the current country's border
			country[i].addCountryToBorder(&country[locat]);

		}
	
	}
}

//This runs a subgraph DFS and a graph DFS
bool Map::validGraph(){

	if (isDefault)
		return false;

	for (int i = 0; i < continent.size(); i++) {
		if (!connectedSubGraph(continent[i]))
			return false;
	}

	if (country.size() == 0)
		return true;

	return connectedMap(country[0]);
}

bool Map::connectedMap(Country start){

	std::set<std::string> checked;
	std::vector<Country> unchecked;

	Country hold;

	//Add initial object to the unchecked list
	unchecked.push_back(start);
	
	//Begin DFS
	while (!unchecked.empty()) {
		//Hold the next object to be checked
		hold = unchecked.back();
		//Remove from unchecked stack
		unchecked.pop_back();
		//Add all objects not in checked or unchecked stack
		for (int i = 0; i < hold.getNumberOfBorderingCountries(); i++) {
			if (checked.count(hold.travel(i)->getName()) == 0 && !inVectorList(unchecked, hold))
				unchecked.push_back(*hold.travel(i));
		}

		checked.insert(hold.getName());

	}
	return checked.size()==country.size();
}

bool Map::connectedSubGraph(Continent target) {

	std::set<std::string> checked;
	std::vector<Country> unchecked;

	Country hold;

	unchecked.push_back(target.travel(0));

	while (!unchecked.empty()) {
		//Hold the next object to be checked
		hold = unchecked.back();
		//Remove from unchecked stack
		unchecked.pop_back();
		//Add all objects not in checked or unchecked stack as long as they are part of the continent to check
		for (int i = 0; i < hold.getNumberOfBorderingCountries(); i++) {
			if (hold.travel(i)->getContinentName().compare(target.getName()) == 0 && checked.count(hold.travel(i)->getName()) == 0 && !inVectorList(unchecked, hold))
				unchecked.push_back(*hold.travel(i));
		}

		checked.insert(hold.getName());

	}
	return checked.size() == target.size();
}

void Map::display() {

	for (int i = 0; i < continent.size(); i++) {
		continent[i].display();
	}
}

bool Map::allLinksAreTwoWay() {

	std::string name;
	bool foundLink;

	//Loop through all countries in map
	for (int countryToCheck = 0; countryToCheck < country.size(); countryToCheck++) {
		name = country[countryToCheck].getName();
		
		//Loop through all countries linked to countryToCheck
		for (int link = 0; link < country[countryToCheck].getNumberOfBorderingCountries(); link++) {
			foundLink = false;
			//Try to travel back to original country
			for (int otherLink = 0; otherLink < country[countryToCheck].travel(link)->getNumberOfBorderingCountries() && !foundLink; otherLink++) {
				//If original country is found
				if (name.compare(country[countryToCheck].travel(link)->travel(otherLink)->getName()) == 0)
					foundLink = true;
			}
			//If original country is not found, return false
			if (!foundLink)
				return false;
		}
		
	}

	return true;

}

bool Map::inVectorList(std::vector<Country> list, Country count) {

	for (int i = 0; i < list.size(); i++) {
		if (list[i].getName().compare(count.getName()) == 0)
			return true;
	}

	return false;
}
