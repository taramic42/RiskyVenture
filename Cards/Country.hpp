//
//  Country.hpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-06.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#pragma once
#include <vector>
#include <string>
using namespace std;

class Country
{
public:
    Country();
    Country(std::string countryName,int x, int y, std::string continentName, std::string border);
    Country(std::string line);
    
    int getOwner() const;
    int getNumberOfBorderingCountries() const;
    std::string getContinentName() const;
    std::string getName() const;
    std::string getBorderString() const;
    
    Country travel(int index);
    Country travel(std::string name);
    void addCountryToBorder(Country* otherCountry);
    
    bool nextTo(Country otherCountry);
    
    void displayBorderCountries();
    
    void display();
    
private:
    string name;
    string continent;
    string borderString;
    int posX;
    int posY;
    int armyCount;
    int owner;
    int linkedCountries;
    std::vector<Country*> borderCountries;
    
};


