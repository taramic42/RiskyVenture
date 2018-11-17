#pragma once
#include <vector>
#include <iostream>
#include <random>
#include "Player.h"
#include "Deck.h"
#include "Map.h"	
class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	void randomizeOrder();
	int getCurrentPlayer();
	void nextPlayer();
	void firstPlayer();
	void display();

	void setupBoard();

	Player* getPlayer(int id);
	vector <Player> getPlayerList();


private:
	int currentPlayer;
	std::vector<int> playerOrder;
	std::vector<Player> playerList;
	Map gameMap;
	Deck mapDeck;
};


