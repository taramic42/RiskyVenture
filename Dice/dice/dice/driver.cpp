//
//  main.cpp
//  dice
//
//  Created by Katerina Tambakis on 2018-09-21.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <random>
#include "DiceClass.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    //creating players
    DiceRollingFacility p1;
    DiceRollingFacility p2;
    
    int val1,val2;
    
    cout<<"Welcome to Dice!\nTo quit press\'0\'"<<endl;
    
    do {
        //player 1 input
        cout<<"\n\nPlayer 1 please enter how many dice you want to roll(no more than 3):\n";
        cin>>val1;
        while(val1<0||val1>3)
        {
            cout<<"invalid amount try again\n";
            cin>>val1;
        }
        if(val1==0)
            break;
      
        //player 2 input
       cout<<"\nPlayer 2 please enter how many dice you want to roll(no more than 3):\n";
        cin>>val2;
        while(val2<0||val2>3)
        {
            cout<<"invalid amount try again\n";
            cin>>val2;
        }
        
        //displaying result of rolls
        cout<<"\nPlayer 1:\n"<<endl;
        p1.diceRolling(val1);
        cout<<"\nPlayer 2:\n"<<endl;
        p2.diceRolling(val2);
    } while (val1!=0||val2!=0);
    
    //exit
    cout<<"\nThanks for playing!\n\n";

    return 0;
}
