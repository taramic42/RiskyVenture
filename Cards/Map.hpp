//
//  Map.hpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-06.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#pragma once
#include <vector>
#include "Continent.hpp"

class Map
{
public:
    Map();
    Map(std::vector<std::string> lineList);
    Map(std::string file);
    Country getCountry(int i);
    int size();
    void addContinent(Continent cont);
    void addCountry(Country coun);
    void connectObjects();
    bool validGraph();
    bool connectedMap(Country start);
    bool connectedSubGraph(Continent target);
    void display();
    
private:
    std::vector<Continent> continent;
    std::vector<Country> country;
    
    bool inVectorList(std::vector<Country> list, Country count);
};
