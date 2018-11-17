#include "MapDirectory.h"
#include <experimental/filesystem>
#include <iostream>
#include "../GameUtility/MapValidator.h"

MapDirectory::MapDirectory()
{
}

MapDirectory::MapDirectory(std::string path) {
	//Found this online
	namespace fileFind = std::experimental::filesystem;

	MapValidator checker;
	Map tempMap;

	//Iterate through every entry in the directory
	for (auto &line : fileFind::directory_iterator(path)) {
		//Add only valid entries into the mapPaths member

		checker = MapValidator(line.path().string());
		tempMap = checker.loadMap();

		if(tempMap.validGraph())
			mapPaths.push_back(line.path().string());
	}

}

MapDirectory::~MapDirectory()
{
}

void MapDirectory::loadMapByUserChoice(Map& mapObject) {

	if (mapPaths.size() == 0) {
		std::cout << "Warning! No valid maps are in the Map directory." << std::endl;
		//should exit if no valid maps shown
		cin.get();
		exit(0);
	}
	else {
		std::cout << "Please select a map from the following list of valid files by inputing the number to the left of the desired entry: " << std::endl;
		std::cout << "Press enter to activate input." << std::endl;
		displayMaps();

		int index;
		do {
			std::cin.clear();
			std::cin.ignore();

			std::cin >> index;

			if (std::cin.fail() || index < 0 || index >= mapPaths.size())
				std::cout << "Please be sure to input a valid integer."<<std::endl;
			

		} while (std::cin.fail() || index < 0 || index >= mapPaths.size());
		
		mapObject = Map(mapPaths[index]);
		mapObject.connectObjects();
		
	}
}

void MapDirectory::displayMaps() {
	for (int i = 0; i < mapPaths.size(); i++) {
		std::cout << i <<" -> "<< mapPaths[i] << std::endl;
	}
}
