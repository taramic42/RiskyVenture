//
//  Continent.cpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-06.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include "Continent.hpp"
#include <sstream>
#include <iostream>

using namespace std;

Continent::Continent() {
    bonus = 0;
}

Continent::Continent(string str, int bonusVal){
    
    name = str;
    bonus = bonusVal;
    
}

Continent::Continent(string line) {
    
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
