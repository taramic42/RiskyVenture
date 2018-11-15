#pragma once
#include "Observer.h"
#include "../../Risk/Player/Player.h"
#include <vector>
#include <iostream>

using namespace std;

class ChartView: public Observer
{
private:
	//To have access to player objects
	vector<Player*> playerList;
	//To avoid bombing the command line with massive amounts of text at game start
	bool active;

	//To hold values that make displaying the chart easier
	float mapSize;
	vector<float> percentageOwnedByPlayer;

	string defeatedPlayerOrder;
public:
	ChartView();
	ChartView(vector<Player*> list, int numOfCountries);
	~ChartView();

	void activateChart();

	void display();

	void congrats();

	void update();
};

