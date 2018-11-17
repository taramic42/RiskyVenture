#pragma once
#include <vector>
#include <iostream>
#include <random>
#include "../Player/Player.h"
#include "../Card/Deck.hpp"
#include "../MapClass/Map.h"


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
	
	//added for game loop
	std::vector<Player*> getPlayerList();
	Map& getMap();
	Deck& getDeck();


private:
	int currentPlayer;
	std::vector<int> playerOrder;
	std::vector<Player*> playerList;
	Map gameMap;
	Deck mapDeck;
};

