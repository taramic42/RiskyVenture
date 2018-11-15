#include "MapValidator.h"

MapValidator::MapValidator() {

}

MapValidator::~MapValidator() {

}

//pass a file path and it fills the entire contents of the string into a string vector
MapValidator::MapValidator(string filePath) {
	
	//check file extension first txt and map files only

	size_t position;
	string temp;

	if (filePath.find_last_of(".") != string::npos) {
		position = filePath.find_last_of(".");
		temp = filePath.substr(position + 1);
		
	if (temp == "txt" || temp == "map") {

	fstream mapFile(filePath, ios::in);

	if (mapFile.is_open()) {

		string readLine;

		while (!mapFile.eof()) {
			getline(mapFile, readLine);
			fileContents.push_back(readLine);
		}
	}

	mapFile.close();

	}

	}
	else {
	cout << "Invalid file extension." << endl;
	}
}

//checks to see if all 3 headers exist
bool MapValidator::checkHeaders() {

	int counter = 0;

	for (auto i : fileContents) {
		if (i == "[Map]") {
			counter++;
		}
		if (i == "[Continents]") {
			counter++;
		}
		if (i == "[Territories]") {
			counter++;
		}
	}

	if (counter != 3) {
		cout << "There is an error in the file headers." << endl;
	}

	return counter == 3;
}

//break file up into sections
void MapValidator::loadSections() {

	for (int i = 0; i < fileContents.size(); i++) {
		//first load the map section part of the vector
		if (fileContents[i] == "[Map]") {
			i++;
			while (fileContents[i] != "") {
				mapSection.push_back(fileContents[i]);
				i++;
			}
		}
		if (fileContents[i] == "[Continents]") {
			i++;
			while (fileContents[i] != "") {
				contiSection.push_back(fileContents[i]);
				i++;
			}
		}
		if (fileContents[i] == "[Territories]") {
			i++;
			while (i < fileContents.size()) {
				countrySection.push_back(fileContents[i]);
				i++;
			}
		}
	}
}

//check continents section for validity
bool MapValidator::checkConti() {
	for (int i = 0; i < contiSection.size(); i++) {

		//checks for "="
		if (contiSection[i].find_last_of("=") != string::npos) {

			size_t position = contiSection[i].find_last_of("=");
			string temp = contiSection[i].substr(position + 1);

			//checks for digits after "="
			if (temp.find_first_not_of("0123456789") != string::npos) {
				cout << "Invalid bonus value must be digit. Error at continent: " << i << endl;
				return false;
			}
		}
		else {
			cout << "No \"=\" character at " << i << endl;
			return false;
		}
	}

	return true;
}
//check country section for validity
bool MapValidator::checkCountrySection() {
	for (auto country : countrySection) {

		//checks more than 4 commas
		if (count(country.begin(), country.end(), ',') < 4){
			cout << "Invalid country : " << country << endl;
			return false;
		}

		string temp = country.substr(country.find(",") + 1);
		string possibleInt = temp.substr(0, temp.find(","));
		
		//checks x coord is digit
		if (possibleInt.find_first_not_of("0123456789") != string::npos) {
			cout << "Invalid x coordinate at this line: " << country << endl;
			return false;
		}

		temp.replace(0, temp.find(",") + 1, "");
		possibleInt = temp.substr(0, temp.find(","));
		
		//checks y coord is digit
		if (possibleInt.find_first_not_of("0123456789") != string::npos) {
			cout << "Invalid y coordinate at this line: " << country << endl;
			return false;
		}
		//last check, checks for information after third comma
		return (temp.substr(temp.find(",")).size() > 0);
	}
}

//the main validator
bool MapValidator::validateFile() {
	
	if (checkHeaders()) {
		loadSections();
		if (checkConti()) {
			if (checkCountrySection()) {
				return true;
			}
		}
	}

	return false;
}

vector<string> MapValidator::getFileContents()
{
	return fileContents;
}

Map MapValidator::loadMap() {
	if (validateFile()) {
		Map map = Map(fileContents);
		map.connectObjects();
		return map;
	}
	return Map();
}