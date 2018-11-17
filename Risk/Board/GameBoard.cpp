#include "GameBoard.h"
#include "../GameUtility/MapDirectory.h"
#include "../../Risk_Master/Risk_Master/Strategy.h"
#include "../../Risk_Master/Risk_Master/Aggressive.h"

GameBoard::GameBoard()
{
	//Create the game map
	//Invalid maps are not listed
	MapDirectory mapList = MapDirectory("D:\\COMP345\\Risk\\Maps");
	mapList.loadMapByUserChoice(gameMap);

	//Ask the users for the number of players
	int players;

	std::cout << "How many players?(2 to 6)" << std::endl;

	do {
		//Reset the input stream
		std::cin.clear();
		std::cin.ignore();
		std::cin >> players;

		if (std::cin.fail()||(players < 2 || players > 6))
			std::cout << "There must be between 2 to 6 players." << std::endl;

	} while (std::cin.fail()||players < 2 || players>6);

	//TODO add ASK HOW MANY AIS

	for (int i = 0; playerList.size() < players; i++) {
		playerList.push_back(new Player(i));
		playerOrder.push_back(i);
	}

	//added for aggressive testing

	//Aggressive *testStrat = new Aggressive();

	playerList[0]->setStrategy(new Aggressive());

	//end of aggressive testing

	//Create the deck based on the map
	mapDeck = Deck();

	vector<std::string> tempNames;

	for (int i = 0; i < gameMap.size(); i++) {
		tempNames.push_back(gameMap.getCountry(i)->getName());
	}

	mapDeck.initializeDeck(tempNames);
}


GameBoard::~GameBoard()
{
}

void GameBoard::randomizeOrder() {
	std::random_shuffle(playerOrder.begin(), playerOrder.end());
	if (playerOrder.size() > 0)
		currentPlayer = playerOrder[0];
}

int GameBoard::getCurrentPlayer() {
	return currentPlayer;
}

void GameBoard::nextPlayer() {
	
	int nextToPlay = -1;

	for (int i = 0; i < playerOrder.size() && nextToPlay < 0; i++) {
		if (currentPlayer == playerOrder[i]) {
			if (i + 1 != playerOrder.size())
				nextToPlay = playerOrder[i + 1];
			else
				nextToPlay = playerOrder[0];
		}
	}
	currentPlayer = nextToPlay;

}

void GameBoard::firstPlayer() {
	if(playerOrder.size()>0)
		currentPlayer = playerOrder[0];
}

void GameBoard::display() {

	gameMap.display();
	std::cout << std::endl;
	mapDeck.displayDeck();

	for (auto player : playerList) {
		player->display();
		std::cout << std::endl;
	}

}

void GameBoard::setupBoard() {

	//Randomly determine order of players
	randomizeOrder();

	vector<int> countryIndex;

	for (int i = 0; i < gameMap.size(); i++) {
		countryIndex.push_back(i);
	}

	std::random_shuffle(countryIndex.begin(), countryIndex.end());

	//Assign countries in round robin fashion
	while (countryIndex.size() > 0) {
		//Set the owner of the country
		gameMap.getCountry(countryIndex.back())->setOwner(getCurrentPlayer());
		//Add the country pointer to the player object
		playerList[getCurrentPlayer()]->addCountry(gameMap.getCountry(countryIndex.back()));
		//remove it from the temp index
		countryIndex.pop_back();
		//Go to next player
		nextPlayer();
	}

	//Back to first player in the player order
	firstPlayer();

	int armiesToPlace = 50 - 5 * playerList.size();

	int target;

	//For every army
	for (int i = 0; i < armiesToPlace; i++) {
		//For every player
		for (int j = 0; j < playerList.size(); j++) {

			target = std::rand() % playerList[getCurrentPlayer()]->getNumberOfOwnedCountries();

			playerList[getCurrentPlayer()]->placeOneArmy(target);

			nextPlayer();

		}

	}
}

Player* GameBoard::getPlayer(int id)
{
	if (id >= 0 && id < playerList.size())
		return playerList[id];

	return nullptr;
}

vector<Player*> GameBoard::getPlayerList()
{
	return playerList;
}

Map& GameBoard::getMap()
{
	return gameMap;
}

Deck& GameBoard::getDeck()
{
	return mapDeck;
}
