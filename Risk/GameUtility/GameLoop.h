#pragma once
#include "../Player/Player.h"
#include "../MapClass/Map.h"
#include <iostream>

class GameLoop {
private:
	//player turns will the position in the players vector
	Map* map;
	Deck* deck;
	vector<Player*> players;
	int currentPlayer;
	int turnsPlayed;

public:
	GameLoop();
	~GameLoop();
	GameLoop(vector<Player*> Players, Map &Map, Deck &Deck);
	//will prompt the player for inputs for reinforcement, attack and fortification
	void gameLoop();
	bool playerWon();
	void prompt();
	void giveAllCountries(int playerLoc);
	void display();
};

