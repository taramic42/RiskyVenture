//
//  Card.cpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include "Card.hpp"
using namespace std;

Card::Card(string t, string n)
{
    Card::type=t;
    Card::name=n;
}
void Card::setType(string t)
{
    Card::type=t;
}
void Card::setName(string n)
{
    Card::name=n;
}
string Card::getType()
{
    return Card::type;
}
string Card::getName()
{
    return Card::name;
}

