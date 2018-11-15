#include "ChartView.h"

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
	defeatedPlayerOrder = "Defeated Players: \n";

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
	for (int i = 0; i < playerList.size(); i++) {
		cout << "Player " << playerList[i]->getId() << " owns " << playerList[i]->getNumberOfOwnedCountries() << " out of " << mapSize << " or ";
		cout << (int)(percentageOwnedByPlayer[i] * 100) << "% of the world." << endl << endl;
	}
	if (defeatedPlayerOrder.size() > 20)
		cout << defeatedPlayerOrder << endl;
}

void ChartView::congrats()
{
	cout << "Congratulations Player " << playerList[0]->getId() << " you have conquered the map." << endl;
	cout << defeatedPlayerOrder << endl;
	active = false;
}

void ChartView::update()
{

	if(active)
		for (int i = playerList.size()-1; i >= 0; i--) {
			//remove defeated players
			if (playerList[i]->getNumberOfOwnedCountries() == 0) {
				defeatedPlayerOrder += "Player " + (playerList[i]->getId());
				defeatedPlayerOrder += "\n";
				playerList[i]->removeObserver(this);
				playerList.erase(playerList.begin() + i);
				percentageOwnedByPlayer.erase(percentageOwnedByPlayer.begin() + i);
			}
			//check if someone has won
			else if (playerList[i]->getNumberOfOwnedCountries() == mapSize) {
				congrats();
				active = false;
			}
			//calculate percentages otherwise
			else {
				percentageOwnedByPlayer[i] = playerList[i]->getNumberOfOwnedCountries() / mapSize;
			}
	}

	if(active)
		display();
}
