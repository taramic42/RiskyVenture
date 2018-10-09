//
//  Card.hpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Card
{
private:
    string type;
    string name;
    
public:
    Card(string t,string n);
    string getName();
    void setName(string n);
    string getType();
    void setType(string t);
};
#endif /* Card_hpp */
