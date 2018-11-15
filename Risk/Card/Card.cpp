//
//  Card.cpp
//  Card2
//
//  Created by Katerina Tambakis on 2018-10-10.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//
#include "Card.hpp"
using namespace std;

Card::Card() {
	type = "";
	name = "";
}

Card::Card(string t, string n)
{
    type=t;
    name=n;
}
void Card::setType(string t)
{
    type=t;
}
void Card::setName(string n)
{
    name=n;
}
string Card::getType()
{
    return type;
}
string Card::getName()
{
    return name;
}
