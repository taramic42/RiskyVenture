#include "stdafx.h"
#include "Continent.h"
#include <sstream>
#include <iostream>



Continent::Continent() {
	bonus = 0;
}

Continent::Continent(std::string str, int bonusVal){

    name = str;
	bonus = bonusVal;

}

Continent::Continent(std::string line) {

	int delim = line.find("=");

	name = line.substr(0,delim);

	bonus = stoi(line.substr(delim + 1, line.size()));

}

int Continent::getBonus() const{
	return bonus;
}

std::string Continent::getName() const { 
	return name; 
}

Country Continent::travel(int index) {
	if (index >= 0 && index<countryList.size())
		return *countryList[index];
	return Country();
}

int Continent::size() {
	return countryList.size();
}

void Continent::addCountry(Country* coun){

	countryList.push_back(coun);

}

void Continent::display(){
    
    std::cout << name << " " << bonus << std::endl;

	for (int i = 0; i < countryList.size(); i++) {
		countryList[i]->display();
	}
    
}
