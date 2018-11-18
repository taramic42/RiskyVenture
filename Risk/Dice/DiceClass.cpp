//
//  DiceClass.cpp
//  dice
//
//  Created by Katerina Tambakis on 2018-09-21.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include "DiceClass.hpp"
#include <stdio.h>
#include <iostream>
#include <random>
using namespace std;


DiceRollingFacility::DiceRollingFacility()
{
    DiceRollingFacility::rollCount=0;
    for(int i=0;i<6;i++)
        DiceRollingFacility::roll[i]=0;
}//default constructor


bool DiceRollingFacility::valueCheck(int n)
{
    if(n>6||n<1)
    {cout<<n<<" invalid\n";
        return false;}
    else
        return true;
}//check if dice value is correct


void DiceRollingFacility::oneDice(int a)
{
    DiceRollingFacility::diceNum1[0]=a;
    cout<<"you rolled:"<<DiceRollingFacility::diceNum1[0]<<endl;
}//saving 1 dice


void DiceRollingFacility::twoDice(int a,int b)
{
    if(a<b)
    {
        DiceRollingFacility::diceNum2[0]=a;
        DiceRollingFacility::diceNum2[1]=b;
    }
    else
    {
        DiceRollingFacility::diceNum2[0]=b;
        DiceRollingFacility::diceNum2[1]=a;
    }
    cout<<"you rolled:"<<DiceRollingFacility::diceNum2[0]<<", "<<DiceRollingFacility::diceNum2[1]<<endl;
}//saving and sorting 2 dice


void DiceRollingFacility::threeDice(int a,int b,int c)
{
    
    if (a > b)
    {
        if (a > c)
        {
            if (b > c)
            {
                DiceRollingFacility::diceNum3[2] = a;
                DiceRollingFacility::diceNum3[1] = b;
                DiceRollingFacility::diceNum3[0] = c;
            }
            else
            {
                DiceRollingFacility::diceNum3[2] = a;
                DiceRollingFacility::diceNum3[1] = c;
                DiceRollingFacility::diceNum3[0] = b;
            }
        }
        else
        {
            DiceRollingFacility::diceNum3[2] = c;
            DiceRollingFacility::diceNum3[1] = a;
            DiceRollingFacility::diceNum3[0] = b;
        }
    }
    else
    {
        if (b > c)
        {
            if (a > c)
            {
                DiceRollingFacility::diceNum3[2] = b;
                DiceRollingFacility::diceNum3[1] = a;
                DiceRollingFacility::diceNum3[0] = c;
            }
            else
            {
                DiceRollingFacility::diceNum3[2] = b;
                DiceRollingFacility::diceNum3[1] = c;
                DiceRollingFacility::diceNum3[0] = a;
            }
        }
        else
        {
            DiceRollingFacility::diceNum3[2] = c;
            DiceRollingFacility::diceNum3[1] = b;
            DiceRollingFacility::diceNum3[0] = a;
        }
    }
    
    cout<<"you rolled:" << DiceRollingFacility::diceNum3[0] << ", " << DiceRollingFacility::diceNum3[1] << ", " << DiceRollingFacility::diceNum3[2] <<endl;
}//saving and sorting 3 dice


void DiceRollingFacility::increment(int n)
{
    //cout<<"n:"<<n<<endl;
    switch (n) {
        case 1:
        DiceRollingFacility::roll[0]++;
            break;
        case 2:
        DiceRollingFacility::roll[1]++;
            break;
        case 3:
        DiceRollingFacility::roll[2]++;
            break;
        case 4:
        DiceRollingFacility::roll[3]++;
            break;
        case 5:
        DiceRollingFacility::roll[4]++;
            break;
        case 6:
        DiceRollingFacility::roll[5]++;
            break;
        default:
            break;
    }
    DiceRollingFacility::rollCount++;
}//increment roll count of each dice value and total rolls


void DiceRollingFacility::percent()
{
    if(DiceRollingFacility::rollCount==0)
        cout<<"rolls havent been made!!\n";
    else
        for(int i=0;i<6;i++)
        {
            percentage[i]=(double(DiceRollingFacility::roll[i])/DiceRollingFacility::rollCount)*100;
            cout<<"percentage of dice value: "<<i+1<<": "<<DiceRollingFacility::percentage[i]<<"% ("<<DiceRollingFacility::roll[i]<<" roll(s))\n";
        }
    cout<<"\ntotal number of rolls:"<<DiceRollingFacility::rollCount<<endl;
}//saving percentages of each dice number rolled


void DiceRollingFacility::diceRolling(int num)
{
    int val1,val2,val3;
    
    //random generator
    random_device rd;
    mt19937 generate(rd());
    uniform_int_distribution<> rolling(1, 6);
    
    //random dice value
    val1=rolling(generate);
    val2=rolling(generate);
    val3=rolling(generate);
    
    if(valueCheck(val1)&&valueCheck(val2)&&valueCheck(val3))
    {
        if(num==1)//if 1 being rolled
        {
            oneDice(val1);
            increment(val1);
            //percent();
        }
        if(num==2)//if 2 being rolled
        {
            twoDice(val1, val2);
            increment(val1);
            increment(val2);
            //percent();
        }
        if(num==3)//if 3 being rolled
        {
            threeDice(val1, val2, val3);
            increment(val1);
            increment(val2);
            increment(val3);
            //percent();
        }
    }
}//implement rolling process

int DiceRollingFacility::resultOfBattle(int numberOfAttackers, int numberOfDefenders, DiceRollingFacility &defenderDice)
{

	int result = 0;

	vector<int> holdAttackerDice;
	vector<int> holdDefenderDice;

	switch (numberOfAttackers) {
	case 1:
		holdAttackerDice.push_back(DiceRollingFacility::diceNum1[0]);
		break;
	case 2:
		holdAttackerDice.push_back(DiceRollingFacility::diceNum2[1]);
		holdAttackerDice.push_back(DiceRollingFacility::diceNum2[0]);
		break;
	case 3:
		holdAttackerDice.push_back(DiceRollingFacility::diceNum3[2]);
		holdAttackerDice.push_back(DiceRollingFacility::diceNum3[1]);
		holdAttackerDice.push_back(DiceRollingFacility::diceNum3[0]);
		break;
	}

	switch (numberOfDefenders) {
	case 1:
		holdDefenderDice.push_back(defenderDice.getDiceResult(1)[0]);
		break;
	case 2:
		holdDefenderDice.push_back(defenderDice.getDiceResult(2)[1]);
		holdDefenderDice.push_back(defenderDice.getDiceResult(2)[0]);
		break;
	}

	for (int i = 0; i < holdAttackerDice.size() && i < holdDefenderDice.size(); i++) {
		if (holdAttackerDice[i] > holdDefenderDice[i])
			result++;
		else
			result--;
	
	}

	return result;
}

int * DiceRollingFacility::getDiceResult(int numOfDice)
{
	if (numOfDice == 1)
		return diceNum1;
	if (numOfDice == 2)
		return diceNum2;
	if (numOfDice == 3)
		return diceNum3;

	return nullptr;
}
