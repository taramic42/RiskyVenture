//
//  Deck.hpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

class Deck
{
private:
    int size;
    int army;
    vector <Card> deck;
    vector <Card> discard;
    
public:
    Deck(vector <Card> deck);
    void increaseArmy();
    Card draw();
    int getSize();
    void setSize(int s);
    int getArmy();
    void initializeDeck(vector <Card> deck);
    void discardDeck(Card c);
    void removeFromDeck();
    void shuffleDeck();
    void replenishDeck();
    bool checkDeck();
};


#endif /* Deck_hpp */
