#include <iostream>
#include "Player.h"
#include "Map.h"
#include "AttackPhase.h"
#include "ReinforcePhase.h"
#include "Fortify.h"
#include "Deck.h"
#include "Hand.h"
#include <fstream>
#include <vector>
#include "PlayerStrategy.h"
#include "Strategy.h"
#include "GameBoard.h"
#include "Passive.h"
using namespace std;

int main()
{
	string line;
	vector<string> lineList;
	ifstream inputFile;
	inputFile.open("Alabama.map");

	while (!inputFile.eof()) {
		getline(inputFile, line);
		lineList.push_back(line);
	}

	//Test constructor using a vector
	Map validMap = Map(lineList);
	inputFile.close();

	//Connect the nodes of every map
	validMap.connectObjects();
	Deck d;

	vector <string> countryList;

	for (int i = 0; i < validMap.size(); i++)
		countryList.push_back(validMap.getCountry(i)->getName());
	d.initializeDeck(countryList);
	 


	vector <Country*> list1;
	vector<Country*> list2;
	vector <Country*> list3;

	for (int i=0; i<validMap.size(); i++)
	{
		if(i%3==0)
			list1.push_back(validMap.getCountry(i));
		else if(i%3==1)
			list2.push_back(validMap.getCountry(i));
		else list3.push_back(validMap.getCountry(i));
	}

	//setting initial countries
	
	 
	vector <Player*> list;
	
	Player *p1=new Player(list2,40);
	p1->setId(0);
	p1->setStrategy(new PlayerStrategy() );
	Strategy *human = new PlayerStrategy();
	human->setPlayer(p1);
	

	
	Player *p2 = new Player(list1,40);
	p2->setId(1);
	p2->setStrategy(new Passive());
	Strategy *passive = new Passive();
	passive->setPlayer(p2);
	p2->setStrategy(passive);


	list.push_back(p1);
	list.push_back(p2);

	human->setPlayerList(list);
	p1->setStrategy(human);
	
	int totalCountries = validMap.size();

	
	while (p1->getNumberOfOwnedCountries() != totalCountries || p2->getNumberOfOwnedCountries() != totalCountries)
	{
		if (p1->getNumberOfOwnedCountries() == totalCountries)
		{
			cout << "user wins\n";
			break;
		}
		else if (p2->getNumberOfOwnedCountries() == totalCountries)
		{
			cout << "passive wins\n";
			break;
		}
		else 
		{
			
				p1->execute();
				p2->execute();
		
		
		}
	}



	delete human, passive, p1, p2;
	system("pause");
	return 0;
}