//
//  Hand.hpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"
using namespace std;

class Hand
{
private:
    vector <Card> hand;
    int armyCount;
public:
    Hand();
    void newCard(Card c);
    Card exchange(int n);
    void armySize(int s);
    int getArmy();
    void displayHand();
    
    
};
#endif /* Hand_hpp */
