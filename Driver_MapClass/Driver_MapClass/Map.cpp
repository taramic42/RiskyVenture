#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include "Map.h"
#include "Continent.h"



Map::Map(){

}

Map::Map(std::vector<std::string> lineList) {

	int i = 0;

	while (lineList[i].compare("[Continents]") != 0) {
		i++;
	}

	i++;

	while (lineList[i].compare("") != 0) {
		if (lineList[i].compare("") != 0)
			addContinent(lineList[i]);
		i++;
	}

	i++;

	while (++i < lineList.size()) {

		addCountry(lineList[i]);
	}

}

Map::Map(std::string file) {
	std::string line;
	std::vector<std::string> lineList;
	std::ifstream inputFile;
	inputFile.open(file);

	while (!inputFile.eof()) {
		getline(inputFile, line);
		lineList.push_back(line);
	}

	int i = 0;

	while (lineList[i].compare("[Continents]") != 0) {
		i++;
	}

	i++;

	while (lineList[i].compare("") != 0) {
		if (lineList[i].compare("") != 0)
			addContinent(lineList[i]);
		i++;
	}

	i++;

	while (++i < lineList.size()) {

		addCountry(lineList[i]);
	}

}

void Map::addContinent(Continent cont){
    
    continent.push_back(cont);

}


void Map::addCountry(Country coun){
    
    country.push_back(coun);
    
}


void Map::connectObjects(){
    
    //std::map<std::string, int> use this to fill continents
	//by linking a continent name to an index value
	//This allows the creation of subgraphs to be of O(n) complexity
    
	std::map<std::string, int> continentIndex;
	std::map<std::string, int> countryIndex;

	for (int i = 0; i < continent.size(); i++) {
		continentIndex.insert(std::pair<std::string, int>(continent[i].getName(),i));
	}

    //same thing for countries

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

		//Here's the country border logic (it's pretty messy, but it's been tested to oblivion)
		holdBorderString = country[i].getBorderString();

		while (holdBorderString.size()>0) {

			if (holdBorderString.find(",") != std::string::npos) {

				toLink = holdBorderString.substr(0, holdBorderString.find(","));

				if (countryIndex.count(toLink) != 0) {
					locat = countryIndex.find(toLink)->second;
					holdBorderString.replace(0, holdBorderString.find(",") + 1, "");
				}
			}
			else {

				if (countryIndex.count(holdBorderString) != 0) {
					locat = countryIndex.find(holdBorderString)->second;
					holdBorderString.replace(0, holdBorderString.size(), "");
				}
			}

			country[i].addCountryToBorder(&country[locat]);

		}
	
	}
}

bool Map::validGraph(){
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
			if (checked.count(hold.travel(i).getName()) == 0 && !inVectorList(unchecked, hold))
				unchecked.push_back(hold.travel(i));
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
		//Add all objects not in checked or unchecked stack
		for (int i = 0; i < hold.getNumberOfBorderingCountries(); i++) {
			if (hold.travel(i).getContinentName().compare(target.getName()) == 0 && checked.count(hold.travel(i).getName()) == 0 && !inVectorList(unchecked, hold))
				unchecked.push_back(hold.travel(i));
		}

		checked.insert(hold.getName());

	}
	return checked.size() == target.size();
}

void Map::display() {

	for (int i = 0; i < continent.size(); i++) {
		continent[i].display();
	}

	//for (int i = 0; i < country.size(); i++) {
	//	country[i].display();
	//}

}

bool Map::inVectorList(std::vector<Country> list, Country count) {

	for (int i = 0; i < list.size(); i++) {
		if (list[i].getName().compare(count.getName()) == 0)
			return true;
	}

	return false;
}
