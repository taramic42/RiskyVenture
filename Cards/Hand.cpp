//
//  Hand.cpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include "Hand.hpp"
#include <iostream>
using namespace std;

Hand::Hand()
{
    Hand::armyCount=0;
}
void Hand::newCard(Card c)
{
    Hand::hand.push_back(c);
}

Card Hand::exchange(int n)
{
    if(hand.size()==0)
    {cout<<"no more cards\n";
        exit(1);
    }
    Card card=hand.back();
    
    Hand::hand.pop_back();
   
    armySize(n);
    cout<<"army:"<<getArmy()<<endl;
   
    return card;
}

void Hand::armySize(int s)
{
    Hand::armyCount+=s;
}

int Hand::getArmy()
{
    return armyCount;
}

void Hand::displayHand()
{
    if(Hand::hand.size()==0)
        cout<<"no cards in hand\n";
    else
    {
        cout<<"your hand:\n";
        for(int i=0;i<Hand::hand.size();i++)
        {   string name=Hand::hand.at(i).getName();
            string type=Hand::hand.at(i).getType();
            cout<<"name: "<<name<<", type: "<<type<<endl;
        }
    }
}
