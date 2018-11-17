//
//  Hand.hpp
//  Card2
//
//  Created by Katerina Tambakis on 2018-10-10.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include "Card.hpp"
#include "Deck.hpp"
using namespace std;

class Hand
{
private:
    vector <Card> hand;
    int armyCount;
	void discardInfantry(Deck d);
	void discardCalvary(Deck d);
	void discardArtillery(Deck d);
	void discardOneOfEach(Deck d);
public:
    Hand();
    void newCard(Card c);
    int exchange(Deck d);
    void armySize();
    int getArmy();
    void displayHand();
	int handSize();
    
    
};
