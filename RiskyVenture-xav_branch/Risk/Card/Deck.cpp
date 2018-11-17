//
//  Deck.cpp
//  Card2
//
//  Created by Katerina Tambakis on 2018-10-10.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//
#include "Deck.hpp"
#include "Card.hpp"
#include "../MapClass/Map.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

Deck::Deck() {

}

Deck::Deck(vector <Card> adeck, long size)
{
    deck=adeck;
    deck.reserve(size);
    discard.reserve(size);
    for(int i=0;i<deck.size();i++)
        cout<<"name:"<<deck.at(i).getName()<<" type: "<<deck.at(i).getType()<<endl;
}

void Deck::setSize(int s)
{
    Deck::deck.reserve(s);
}

void Deck::initializeDeck(vector <string> names)
{
    for(int i=0;i<names.size();i+=3)
    {
        
        Card c=Card("infantry",names[i]);
            deck.push_back(c);
        if(i+1<names.size())
        {
            Card c=Card("artillery",names[i+1]);
            deck.push_back(c);
        }

        if(i+2<names.size())
        {
            Card c=Card("cavalry",names[i+2]);
            deck.push_back(c);
        }
    }
        
}

int Deck::getSize() {
	return deck.size();
}

void Deck::removeFromDeck()
{
    deck.pop_back();
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
        return Card();
    }
    Card last=deck.back();
    removeFromDeck();
    return last;
}

bool Deck::isEmpty()
{
    if(deck.size()!=0)
        return false;

    return true;
}
void Deck::shuffleDeck()
{
	
    random_shuffle(deck.begin(), deck.end());
    
}

void Deck::replenishDeck()
{
   
        for(int i=0;i<discard.size();i++)
        {  Card card=discard.back();
            discard.pop_back();
            deck.push_back(card);
        }
   
}

void Deck::addCard(Card c) {
	discard.push_back(c);
}

void Deck::displayDeck()
{
	if (deck.size() == 0)
		cout << "no cards in hand\n";
	else
	{
		cout << "your hand:\n";
		for (int i = 0; i<deck.size(); i++)
		{
			string name = deck.at(i).getName();
			string type = deck.at(i).getType();
			cout << "name: " << name << ", type: " << type << endl;
		}
	}
}