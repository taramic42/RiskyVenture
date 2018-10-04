#pragma once

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//created methods
vector<string> split(string str, string delim);

//basic continents container
class Continents {
public:
	string name;
	int score;

	Continents(string Name, int Score){
		name = Name;
		score = Score;
	}
};

//basic countries container
//the attributes vector has these attributes in this order
//name, x cord, y cord, continent, {remaining elements are adjacent countries}
class Countries {
public:
	vector<string> attributes;

	Countries(vector<string> Attributes) {
		attributes = Attributes;
	}
};


int main() {
	
	//open file for reading only
	fstream map_file("../maps/D-Day/D-Day.map", ios::in);
	
	//checks to see if the file succesfully opened
	if (map_file.is_open()) {
		
		//temporary string to store the line being loaded from the file
		//approach loads one line at a time and parses it based on what it is
		string line;

		//Map attributes that are standard between all maps
		string author;
		string image;
		string wrap;
		string scroll;
		string warn;

		//Continents vector that contains some continent objects which hold the name and score for owning such continent
		vector<Continents> continents_list;
		
		//Countries Vector containing continents
		vector<Countries> countries_list;

		//loop to load each line
		while (!map_file.eof()) {

			getline(map_file, line);

			//checks the file headers
			if (line.compare("[Map]") == 0) {
				//go to next line
				//loop inside the map heading section
				while (1) {

					getline(map_file, line);

					if (line.find("author=") != string::npos) {
						author = line.substr(7);
					}
					else if (line.find("image=") != string::npos) {
						image = line.substr(6);
					}
					else if (line.find("wrap=") != string::npos) {
						wrap = line.substr(5);
					}
					else if (line.find("scroll=") != string::npos) {
						scroll = line.substr(7);
					}
					else if (line.find("warn=") != string::npos) {
						warn = line.substr(5);
						break;
					}
				}
			}
			//load the continents string names
			else if (line.compare("[Continents]")==0) {

				while (1) {
				
					getline(map_file, line);
					
					//find() returns the position of the first occurence of matching string, returns -1 if not found
					//string::npos is -1 meaning no position found
					if (line.find("=") != string::npos) {
						
						size_t position = line.find("=");
						string temp_name = line.substr(0, position);
						
						int temp_score = stoi(line.substr(position + 1));
						
						//fill the vector with newly created objects the objects are located with the continents_list vector
						continents_list.push_back(Continents(temp_name, temp_score));
					}
					else {
						break;
					}
				}
			}
			else if (line.compare("[Territories]") == 0) {
				
				//loop until end of file
				while (!map_file.eof()) {
					getline(map_file, line);
					countries_list.push_back(Countries (split(line, ",")));
				}
			}
		}
		map_file.close();

		cout << "Success" << endl;
		std::cin.get();

	}
	else {
		cout << "There was an error opening your file." << endl;
	}

};


//returns a vector of strings split by the delimeter
vector<string> split(string str, string delim) {

	vector<string> temp_container;

	while (str.find(delim) != string::npos) {
		
		size_t position = str.find(delim);
		temp_container.push_back(str.substr(0, position));
		string temp = str.substr(position+1);
		
		str = temp;
		
		if (str.find(delim) == string::npos) {
			temp_container.push_back(str);
		}
	}

	return temp_container;
}