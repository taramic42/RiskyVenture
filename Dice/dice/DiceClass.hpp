//
//  DiceClass.hpp
//  dice
//
//  Created by Katerina Tambakis on 2018-09-21.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#ifndef DiceClass_hpp
#define DiceClass_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class DiceRollingFacility
{
private:
    int rollCount;
    int diceNum1[1],diceNum2[2],diceNum3[3],percentage[6],roll[6];
public:
    DiceRollingFacility();
    void diceRolling(int num);//implement rolling process
    void percent();//saving percentages of each dice number
    void increment(int n);//increment roll count
    void oneDice(int a);//saving and sorting 1 dice
    void twoDice(int a,int b);//saving and sorting 2 dice
    void threeDice(int a,int b,int c);//saving and sorting 3 dice
    bool valueCheck(int n);//check if dice value is correct
};

#endif /* DiceClass_hpp */
