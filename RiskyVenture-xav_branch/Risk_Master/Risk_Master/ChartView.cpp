#include "ChartView.h"

void ChartView::removeDefeatedPlayers()
{
	for (int i = playerList.size() - 1; i >= 0; i--) {
		//remove defeated players
		if (playerList[i]->getNumberOfOwnedCountries() == 0) {
			int hold = playerList[i]->getId();
			defeatedPlayerOrder += " (Player "+std::to_string(hold)+") ";
			playerList[i]->removeObserver(this);
			playerList.erase(playerList.begin() + i);
			percentageOwnedByPlayer.erase(percentageOwnedByPlayer.begin() + i);
		}
	}
}

ChartView::ChartView()
{
	active = false;
	defeatedPlayerOrder = "Defeated Players: \n";
}

ChartView::ChartView(vector<Player*> list, int numOfCountries)
{
	mapSize = numOfCountries;

	for (int i = 0; i < list.size(); i++) {
		list[i]->addObserver(this);
		playerList.push_back(list[i]);
	}

	for (int i = 0; i < list.size(); i++) {
		percentageOwnedByPlayer.push_back(0.0f);
	}

	active = false;
	defeatedPlayerOrder = "Defeated Players: ";

}


ChartView::~ChartView()
{
	for (int i = 0; i < playerList.size(); i++)
		playerList[i]->removeObserver(this);
}

void ChartView::activateChart()
{
	active = true;
	update();
}

void ChartView::display()
{

	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;

	for (int i = 0; i < playerList.size(); i++) {
		cout << "Player " << playerList[i]->getId() << " owns " << playerList[i]->getNumberOfOwnedCountries() << " out of " << mapSize << " or ";
		cout << (int)(percentageOwnedByPlayer[i] * 100) << "% of the world." << endl << endl;
	}
	if (defeatedPlayerOrder.size() > 20)
		cout << defeatedPlayerOrder << endl;

	cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
}

void ChartView::congrats()
{
	cout << "Congratulations Player " << playerList[0]->getId() << " you have conquered the map." << endl;
	cout << defeatedPlayerOrder << endl;
	active = false;
}

void ChartView::update()
{
	//remove defeated players
	removeDefeatedPlayers();

	if(active)
		for (int i = playerList.size()-1; i >= 0; i--) {

			//calculate percentages otherwise
			percentageOwnedByPlayer[i] = playerList[i]->getNumberOfOwnedCountries() / mapSize;

			//check if someone has won
			if (playerList[i]->getNumberOfOwnedCountries() == mapSize) {
				display();
				congrats();
				active = false;
			}
			
	}

	if(active)
		display();
}
