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

int Continent::getBonus() const{
	return bonus;
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
