//
//  Card.hpp
//  Card2
//
//  Created by Katerina Tambakis on 2018-10-10.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>
using namespace std;

class Card
{
private:
    string type;
    string name;
    
public:
	Card();
    Card(string t,string n);
    string getName();
    void setName(string n);
    string getType();
    void setType(string t);
};

