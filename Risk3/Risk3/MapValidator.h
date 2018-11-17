#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Map.h"
#include <algorithm>

using namespace std;

class MapValidator {

public:
	MapValidator();
	~MapValidator();
	MapValidator(string filePath);
	bool checkHeaders();
	bool validateFile();
	vector<string> getFileContents();
	bool checkCountrySection();
	void loadSections();
	bool checkConti();
	Map loadMap();

private:
	vector<string> fileContents;
	vector<string> mapSection;
	vector<string> contiSection;
	vector<string> countrySection;
};