#pragma once
#include <vector>
#include <iostream>
#include <random>
#include "../Player/Player.h"
#include "../Card/Deck.hpp"
#include "../MapClass/Map.h"
#include "../../Risk_Master/Risk_Master/ChartView.h"
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
	std::vector<Player*> getPlayerList();
	Map* getMap();

	void giveAllCountriesToPlayer(int id);

private:
	int currentPlayer;
	std::vector<int> playerOrder;
	std::vector<Player> playerList;
	Map gameMap;
	Deck mapDeck;
	ChartView* statistics;
};

