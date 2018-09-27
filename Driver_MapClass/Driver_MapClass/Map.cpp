#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "Map.h"
#include "Continent.h"



Map::Map(){

}

void Map::addContinent(Continent cont){
    
    continent.push_back(cont);

}


void Map::addCountry(Country coun){
    
    country.push_back(coun);
    
}


void Map::connectObjects(){
    
    //std::map<std::string, int> use this to fill continents
    
    //same thing for countries
    
    //should have error catching for non existing countries/continents
}

bool Map::validGraph(){
    //use vector as a stack
    
    //if ever size of stack is != 1 at end of a loop, return false
    
    return true;
}

void Map::display() {

	for (int i = 0; i < country.size(); i++) {
		country[i].display();
	}

	for (int i = 0; i < continent.size(); i++) {
		continent[i].display();
	}

}


