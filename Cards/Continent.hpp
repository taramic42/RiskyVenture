//
//  Continent.hpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-06.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#pragma once
#include <vector>
#include "Country.hpp"
using namespace std;

class Continent
{
public:
    Continent();
    Continent(std::string str, int bonusVal);
    Continent(std::string line);
    
    int getBonus() const;
    std::string getName() const;
    
    Country travel(int index);
    int size();
    
    void addCountry(Country* coun);
    
    void display();
    
private:
    std::string name;
    int bonus;
    std::vector<Country*> countryList;
};
