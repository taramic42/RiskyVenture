// Driver_MapClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Map.h"


int main()
{
	std::string line;
	std::vector<std::string> lineList;
	std::ifstream inputFile;
	inputFile.open("Alabama.map");

	while (!inputFile.eof()) {
		getline(inputFile, line);
		lineList.push_back(line);
	}

	Map validMap = Map(lineList);

	Map validMap2 = Map("Alabama.map");

	Map invalidMap1 = Map();
	invalidMap1.addCountry((std::string)"1,2,3,1,2,3");
	invalidMap1.addCountry((std::string)"2,2,3,1,1");
	invalidMap1.addCountry((std::string)"3,2,3,1,");
	invalidMap1.addContinent((std::string)"1=8");
	invalidMap1.addContinent((std::string)"2=4");

	Map invalidMap2 = Map();
	invalidMap2.addCountry((std::string)"1,2,3,1,2");
	invalidMap2.addCountry((std::string)"2,2,3,1,1");
	invalidMap2.addCountry((std::string)"3,2,3,2,");
	invalidMap2.addContinent((std::string)"1=8");
	invalidMap2.addContinent((std::string)"2=4");

	validMap.connectObjects();
	validMap2.connectObjects();
	invalidMap1.connectObjects();
	invalidMap2.connectObjects();
	//validMap.display();
	//invalidMap1.display();
	//invalidMap2.display();

	std::cout << validMap2.validGraph()<<" "<< invalidMap1.validGraph()<<" "<< invalidMap2.validGraph()<<std::endl;

	inputFile.close();
	system("pause");
    return 0;
}

