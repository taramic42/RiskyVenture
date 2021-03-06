#include "GameBoard.h"
#include "../GameUtility/MapDirectory.h"
#include "../../Risk_Master/Risk_Master/Strategy.h"
#include "../../Risk_Master/Risk_Master/Aggressive.h"
#include "../../Risk_Master/Risk_Master/Passive.h"
#include "../../Risk_Master/Risk_Master/PlayerStrategy.h"

GameBoard::GameBoard()
{
	//Create the game map
	//Invalid maps are not listed
	MapDirectory mapList = MapDirectory("../../Risk/Maps");
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

	for (int i = 0; playerList.size() < players; i++) {
		playerList.push_back(new Player(i));
		playerOrder.push_back(i);
	}

	std::cout << "Here is the list of players: " << std::endl;
	for (int i = 0; i < playerList.size(); i++) {
		std::cout << i << " Player " << playerList[i]->getId() + 1 << std::endl;
		playerList[i]->addArmiesToPlaceOnBoard(0);
	}

	//you can use this logic or parts of it to build a method........
	/*std::cout << "By default, all players are set to Human" << std::endl;
	std::cout << "You can change the player type to:\nAggressive AI\nPassive AI" << std::endl;
	std::cout << "Select a player to change the type, or enter -1 to keep all players as Human" << std::endl;
	int sel;
	for(int i=0;i<playerList.size();i++)
	{
	cin.clear();
	cin.ignore();
	cin >> sel;
	if (sel < -1 || sel>playerList.size()) {
	std::cout << "Herp Derp...choose a valid number" << std::endl;
	continue;
	}
	if(sel==-1)
	{
	for (int j = 0;j<playerList.size();j++)
	{
	playerList[j]->setStrategy(new PlayerStrategy());
	}
	break;
	}
	else
	{
	std::cout << "You chose " << playerList[sel]->getId() + 1 << std::endl;
	std::cout << "To make the player an aggressive AI, enter 1" << std::endl;
	std::cout << "To make the player an Passive AI, enter 2" << std::endl;
	std::cout << "Enter 0 to keep default settings" << std::endl;
	cin >> sel;
	if(sel==1)
	{
	playerList[sel]->setStrategy(new Aggressive());
	cout << playerList[sel]->getId() + 1 << " is now aggressive\n";
	continue;
	}
	if (sel == 2)
	{
	playerList[sel]->setStrategy(new Passive());
	cout << playerList[sel]->getId() + 1 << " is now passive \n";
	continue;
	}
	if (sel == 0)
	{
	playerList[sel]->setStrategy(new PlayerStrategy());
	cout << playerList[sel]->getId() + 1 << " stays as default\n";
	continue;

	}

	}

	continue;
	}*/

	//added for aggressive testing
	//manually set this during demo
	//Aggressive *testStrat = new Aggressive();
	for (int i = 0; i < playerList.size(); i++) {
		playerList[0]->setStrategy(new Aggressive());
		playerList[1]->setStrategy(new Passive());
		if (i > 1)
		{
			playerList[i]->setStrategy(new PlayerStrategy());
		}
	}

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
	delete statistics;
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

	/*gameMap.display();
	std::cout << std::endl;
	mapDeck.displayDeck();

	for (int i = 0; i < playerList.size();i++) {
		playerList[i].display();
		std::cout << std::endl;
	}*/
	statistics->activateChart();
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

	vector<Player*> temp;

	for (int i = 0; i < playerList.size(); i++) {
		temp.push_back(playerList[i]);
	}

	statistics = new ChartView(temp, gameMap.size());
	statistics->activateChart();
}

Player * GameBoard::getPlayer(int id)
{
	if (id >= 0 && id < playerList.size())
		return playerList[id];

	return nullptr;
}

std::vector<Player*> GameBoard::getPlayerList()
{
	vector<Player*> temp;

	for (int i = 0; i < playerList.size(); i++) {
		temp.push_back(playerList[i]);
	}

	return temp;
}

Map& GameBoard::getMap()
{
	return gameMap;
}

void GameBoard::giveAllCountriesToPlayer(int id)
{
	vector<Country*>countryList;

	for (int i = 0; i < gameMap.size(); i++) {
		countryList.push_back(gameMap.getCountry(i));
		if (gameMap.getCountry(i)->getOwner() != id)
			playerList[gameMap.getCountry(i)->getOwner()]->removeCountry(gameMap.getCountry(i)->getName());
	}

	playerList[id]->setCountries(countryList);
}

Deck& GameBoard::getDeck()
{
	return mapDeck;
}