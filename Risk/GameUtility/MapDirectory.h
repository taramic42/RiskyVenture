#pragma once
#include <vector>
#include "../MapClass/Map.h"

class MapDirectory
{
public:
	MapDirectory();
	MapDirectory(std::string path);
	~MapDirectory();

	void loadMapByUserChoice(Map& mapObject);
	void displayMaps();

private:
	std::vector<std::string> mapPaths;
};

