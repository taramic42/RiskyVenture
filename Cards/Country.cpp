//
//  Country.cpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-06.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//


#include "Country.hpp"
#include <sstream>
#include <iostream>


Country::Country(){
    name = "";
    continent = "";
    borderString = "";
    owner = 0;
    linkedCountries = 0;
    armyCount = 1;
}

Country::Country(std::string countryName, int x, int y, std::string continentName, std::string borders){
    name = countryName;
    continent = continentName;
    posX = x;
    posY = y;
    borderString = borders;
    owner = 0;
    linkedCountries = 0;
    armyCount = 1;
}

Country::Country(std::string line){
    
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
    
    owner = 0;
    linkedCountries = 0;
    armyCount = 1;
}


int Country::getOwner() const{
    return owner;
}

int Country::getNumberOfBorderingCountries() const{
    return linkedCountries;
}

std::string Country::getContinentName() const{
    return continent;
}

std::string Country::getName() const {
    return name;
}

std::string Country::getBorderString() const {
    return borderString;
}

Country Country::travel(int index){
    if(index>=0 && index<linkedCountries)
        return *borderCountries[index];
    return Country();
}

Country Country::travel(std::string name){
    
    for (int i = 0; i < borderCountries.size(); i++) {
        if (name.compare(borderCountries[i]->name))
            return *borderCountries[i];
    }
    
    return Country();
}

void Country::addCountryToBorder(Country* otherCountry){
    //Adds a pointer to the vector list that points to the location of a defined Country object
    borderCountries.push_back(otherCountry);
    linkedCountries++;
}

bool Country::nextTo(Country otherCountry){
    
    for (int i = 0; i < borderCountries.size(); i++) {
        if (otherCountry.name.compare(borderCountries[i]->name))
            return true;
    }
    
    return false;
}

void Country::displayBorderCountries(){
    std::cout << borderString << std::endl;
}

void Country::display(){
    std::cout<<name<<" "<<continent<<" "<<armyCount<<" "<<owner<<" ";
    for (int i = 0; i < borderCountries.size(); i++) {
        std::cout << borderCountries[i]->name << "+";
    }
    std::cout << std::endl;
}
