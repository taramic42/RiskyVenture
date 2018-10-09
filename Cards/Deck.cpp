//
//  Deck.cpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"
#include "Map.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Deck::Deck(vector <Card> adeck)
{
    Deck::deck=adeck;
   // initializeDeck(adeck);
    Deck::army=0;
    cout<<deck.size()<<endl;
}

void Deck::setSize(int s)
{
    Deck::deck.reserve(s);
}

void Deck::initializeDeck(vector <Card> deck)
{
    cout<<"initializing deck\n";
    /* Map m;
    setSize(m.size());
    for(int i=0;i<m.size();i++)
    {
        deck.at(i).setName(m.getCountry(i).getName());
    }*/
    
   setSize(9);
    //cout<<Deck::deck.size()<<endl;
    
 /*   int first=deck.size()/3;
    int second=2*first;
    int third=deck.size();
    
    for(int j=0;j<first;j++)
        {
            deck.at(j).setType("infatry");
            cout<<deck.at(j).getType()<<endl;
        }
    for(int j=first;j<second;j++)
    {
        deck.at(j).setType("artillery");
        cout<<deck.at(j).getType()<<endl;
    }
    for(int j=second;j<third;j++)
    {
        deck.at(j).setType("cavalry");
        cout<<deck.at(j).getType()<<endl;
    }*/
}

void Deck::removeFromDeck()
{
    deck.pop_back();
}
void Deck::increaseArmy()
{
    Deck::army+=5;
}
int Deck::getArmy()
{
    return army;
}
void Deck::discardDeck(Card c)
{
    Deck::discard.push_back(c);
    cout<<"discard"<<discard.size()<<endl;
    for(int j=0;j<discard.size();j++)
    {
        cout<<discard.at(j).getType()<<endl;
        cout<<discard.at(j).getName()<<endl;
    }
}

Card Deck::draw()
{
    if(deck.size()==0)
    {cout<<"no more cards in deck\n";
        exit(0);
    }
    Card last=deck.back();
    removeFromDeck();
    increaseArmy();
    return last;
}

bool Deck::checkDeck()
{
    if(deck.size()!=0)
        return false;
    else return true;
}
void Deck::shuffleDeck()
{
    random_shuffle(deck.begin(), deck.end(),[&](int i) {return rand() % i;});
    
    /*for(int j=0;j<deck.size();j++)
    {
        cout<<deck.at(j).getType()<<endl;
        cout<<deck.at(j).getName()<<endl;
    }*/
    
    
}

void Deck::replenishDeck()
{
    if(checkDeck())
    {
        for(int i=0;i<discard.size();i++)
        {  Card card=discard.back();
           discard.pop_back();
            deck.push_back(card);
        }
    }
}


