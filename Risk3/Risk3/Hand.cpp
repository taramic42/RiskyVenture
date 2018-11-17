//
//  Hand.cpp
//  Card2
//
//  Created by Katerina Tambakis on 2018-10-10.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//
#include "Hand.h"
#include <iostream>
#include"Deck.h"
using namespace std;

Hand::Hand()
{
	Hand::armyCount = 0;
}
void Hand::newCard(Card c)
{
	Hand::hand.push_back(c);
}

int Hand::exchange(Deck d)
{
	if (hand.size() == 0)
	{
		cout << "no more cards\n";
		return 0;
	}

	int inf = 0;
	int cal = 0;
	int art = 0;

	for (int i = 0; i < hand.size(); i++) {
		if (hand[i].getType().compare("infantry") == 0)
			inf++;
		if (hand[i].getType().compare("cavalry") == 0)
			cal++;
		if (hand[i].getType().compare("artillery") == 0)
			art++;
	}

	if (inf > 2) {
		discardInfantry(d);
		armySize();
		return armyCount;
	}
	else if (cal > 2) {
		discardCalvary(d);
		armySize();
		return armyCount;
	}
	else if (art > 2) {
		discardArtillery(d);
		armySize();
		return armyCount;
	}
	else if (inf > 0 && cal > 0 && art > 0) {
		discardOneOfEach(d);
		armySize();
		return armyCount;
	}
	cout << "You do not have 3 of one type or one of each type." << endl;
	return 0;
}

void Hand::armySize()
{
	Hand::armyCount += 5;
}

int Hand::getArmy()
{
	return armyCount;
}

void Hand::displayHand()
{
	if (Hand::hand.size() == 0)
		cout << "no cards in hand\n";
	else
	{
		cout << "your hand:\n";
		for (int i = 0; i < Hand::hand.size(); i++)
		{
			string name = Hand::hand.at(i).getName();
			string type = Hand::hand.at(i).getType();
			cout << "name: " << name << ", type: " << type << endl;
		}
	}
}

int Hand::handSize()
{
	return hand.size();
}

void Hand::discardInfantry(Deck d) {
	int count = 0;
	vector<Card> hold;

	//For every card in hand
	while (hand.size() > 0) {

		//If more infantry are needed and the next card is infantry
		if (count < 3 && hand.back().getType().compare("infantry") == 0) {
			//Send card to discard
			d.addCard(hand.back());
			count++;
		}
		else {
			//Hold onto card
			hold.push_back(hand.back());
		}
		hand.pop_back();
	}

	//Put all remaining cards back in hand
	while (hold.size() > 0) {
		hand.push_back(hold.back());
		hold.pop_back();
	}

}

void Hand::discardCalvary(Deck d) {
	int count = 0;
	vector<Card> hold;

	//For every card in hand
	while (hand.size() > 0) {

		//If more infantry are needed and the next card is infantry
		if (count < 3 && hand.back().getType().compare("calvary") == 0) {
			//Send card to discard
			d.addCard(hand.back());
			count++;
		}
		else {
			//Hold onto card
			hold.push_back(hand.back());
		}
		hand.pop_back();
	}

	//Put all remaining cards back in hand
	while (hold.size() > 0) {
		hand.push_back(hold.back());
		hold.pop_back();
	}

}

void Hand::discardArtillery(Deck d) {
	int count = 0;
	vector<Card> hold;

	//For every card in hand
	while (hand.size() > 0) {

		//If more infantry are needed and the next card is infantry
		if (count < 3 && hand.back().getType().compare("artillery") == 0) {
			//Send card to discard
			d.addCard(hand.back());
			count++;
		}
		else {
			//Hold onto card
			hold.push_back(hand.back());
		}
		hand.pop_back();
	}

	//Put all remaining cards back in hand
	while (hold.size() > 0) {
		hand.push_back(hold.back());
		hold.pop_back();
	}

}

void Hand::discardOneOfEach(Deck d) {

	bool art = false;
	bool cal = false;
	bool inf = false;

	vector<Card> hold;

	while (hand.size() > 0) {

		if (inf == false & hand.back().getType().compare("infantry") == 0) {
			d.addCard(hand.back());
			inf = true;
		}
		else if (cal == false & hand.back().getType().compare("cavalry") == 0) {
			d.addCard(hand.back());
			cal = true;
		}
		else if (art == false & hand.back().getType().compare("artillery") == 0) {
			d.addCard(hand.back());
			art = true;
		}
		else
			hold.push_back(hand.back());


		hand.pop_back();
	}

	//Put all remaining cards back in hand
	while (hold.size() > 0) {
		hand.push_back(hold.back());
		hold.pop_back();
	}
}