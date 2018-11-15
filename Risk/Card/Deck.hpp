//
//  Deck.hpp
//  Card2
//
//  Created by Katerina Tambakis on 2018-10-10.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include "Card.hpp"

class Deck
{
private:
    int size;
    vector <Card> deck;
    vector <Card> discard;
    
public:
	Deck();
    Deck(vector <Card> deck, long size);
    Card draw();
    int getSize();
    void setSize(int s);
    void initializeDeck(vector <string> deck);
    void discardDeck(Card c);
    void removeFromDeck();
    void shuffleDeck();
    void replenishDeck();
    bool isEmpty();
	void addCard(Card c);
	void displayDeck();
};


