#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Map.h"
#include "Player.h"
using namespace std;

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

	//Test constructor using a vector
	Map validMap = Map(lineList);
	inputFile.close();

	//Connect the nodes of every map
	validMap.connectObjects();

	//Display the full map breakdown
	//validMap.display();

		
	//creating vectors
		vector <Country*> pc1;
		vector <Country*> pc2;

	//creating players
		Player *p1=new Player(1);
		Player *p2 =new Player(2);

		//giving armies
		p1->setTotalArmies(10);
		p2->setTotalArmies(10);

		//assigning countries to players
		bool t = true;
		for (int i = 0; i < validMap.size(); i++)
		{
			if (t)
			{
				Country* c = validMap.getCountry(i);
				c->setOwner(p1->getId());
				p1->addCountry(c);
				t = false;
			}
			else
			{
				Country* c = validMap.getCountry(i);
				p2->addCountry(c);
				c->setOwner(p2->getId());
				t = true;
			}
			
		}


		int menu;
		do
		{
			cout << "Player 1\n\n";
			cout<<"1.view your list of countries\n2.set origin country\n3.fortify\n0.exit\n";
			cin>>menu;

			//EXIT
			if(menu==0)
			{cout<<"goodbye";
				break;
			}

			//DISPLAY INITIAL INFO
			if(menu==1)
			{
				cout<<"Your countries:\n";
				if (p1->getNumberOfOwnedCountries() == 0)
					cout << "No countries\n";
				else
				{
					p1->display();
					cout << "\nsize:" << p1->getNumberOfOwnedCountries() << endl;
					cout << "\nyou have a total of " << p1->getTotalArmies() << " armies\n";
				}
			}

			//SETTING ORIGIN
			if(menu==2)
			{
				pc1 = p1->returnAll();
				string countryName;
				cout<<"enter which country you would like to originate from\n";
				cin>>countryName;
				bool c = false;
				for (int i = 0; i < pc1.size(); i++)
				{
					if (pc1[i]->getName() == countryName)
					{
						p1->setOrigin(pc1[i]);
						cout << "Origin set to: " << countryName<<endl<<endl;
						c = true;
					}
				}
				if(!c)
				{
					cout << "You do not have this country try again!\n";
					cin >> countryName;
					for (int i = 0; i < pc1.size(); i++)
					{
						if (pc1[i]->getName() == countryName)
						{
							p1->setOrigin(pc1[i]);
							cout << "Origin set to: " << countryName<<endl<<endl;
							c = true;
						}
					}
				}
			}

			//FORTIFY
			if (menu == 3)
			{


				Country* origin = p1->getOrigin();
				if (origin == NULL)
				{
					cout << "no origin set, return to option 2\n";
					continue;
				}
				if (p1->getTotalArmies() <= 1)
				{
					cout << "Not enough armies to fortify!\n";
					continue;
				}

				cout << "Adjacent countries to " << origin->getName() << endl << endl;
				pc1 = p1->returnAll();
				for (int j=0;j<pc1.size();j++)
				{
					for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
					{
						if(pc1[j]->getName()==origin->travel(i)->getName())
						cout << origin->travel(i)->getName() << endl;
						else continue;
					}
				}

				cout << "\nEnter which country you would like to fortify\n";
				string fcountry;
				cin >> fcountry;

					int army;
					cout << "\nEnter how many armies you would like to send:\n";
					cin >> army;
					while (army > p1->getTotalArmies()-1) {
						cout << "Not enough armied. Try again\n";
						cin >> army;
					}

				bool c = false;
				for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
				{
					if(origin->travel(i)->getName()==fcountry )
					{
						p1->fortify(origin->travel(i),army);
						p1->setTarget(origin->travel(i));
						cout << army << " armies has been sent to " << fcountry<<endl;
						c = true;
					}

				}
			
				if (!c)
				{
					cout << "this country is not adjacent try again!\n";
					cin >> fcountry;
					for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
					{
						if (origin->travel(i)->getName() == fcountry)
						{
							p1->fortify(origin->travel(i), army);
							p1->setTarget(origin->travel(i));
							cout << army << " armies has been sent to " << fcountry << endl;
							c = true;

						}
					}
				}

				cout << "You now have a total of " << p1->getTotalArmies() << " left.\n\n";
			}

		}while(menu!=0);
	

		//int menu;
		do
		{
			cout << "\n\nPlayer 2\n\n";
			cout << "1.view your list of countries\n2.set origin country\n3.fortify\n0.exit\n";
			cin >> menu;

			//EXIT
			if (menu == 0)
			{
				cout << "\ngoodbye";
				return 0;
			}

			//DISPLAY INITIAL INFO
			if (menu == 1)
			{
				cout << "\nYour countries:\n";
				if (p2->getNumberOfOwnedCountries() == 0)
					cout << "No countries\n";
				else
				{
					p2->display();
					cout << "\nsize:" << p2->getNumberOfOwnedCountries() << endl;
					cout << "\nyou have a total of " << p2->getTotalArmies() << " armies\n\n";
				}
			}

			//SETTING ORIGIN
			if (menu == 2)
			{
				pc2 = p2->returnAll();
				string countryName;
				cout << "enter which country you would like to originate from\n";
				cin >> countryName;
				bool c = false;
				for (int i = 0; i < pc2.size(); i++)
				{
					if (pc2[i]->getName() == countryName)
					{
						p2->setOrigin(pc2[i]);
						cout << "Origin set to: " << countryName << endl<<endl;
						c = true;
					}
				}
				if (!c)
				{
					cout << "You do not have this country try again!\n";
					cin >> countryName;
					for (int i = 0; i < pc2.size(); i++)
					{
						if (pc2[i]->getName() == countryName)
						{
							p2->setOrigin(pc2[i]);
							cout << "Origin set to: " << countryName << endl;
							c = true;
						}
					}
				}
			}

			//FORTIFY
			if (menu == 3)
			{

				Country* origin = p2->getOrigin();
				if (origin == NULL)
				{
					cout << "no origin set, return to option 2\n";
					continue;
				}
				if (p2->getTotalArmies() <= 1)
				{
					cout << "Not enough armies to fortify!\n";
					continue;
				}

				cout << "\nAdjacent countries to " << origin->getName() << endl;
				pc2 = p2->returnAll();
				for (int j = 0; j < pc2.size(); j++)
				{
					for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
					{
						if (pc2[j]->getName() == origin->travel(i)->getName())
							cout << origin->travel(i)->getName() << endl;
						else continue;
					}
				}

				cout << "\nEnter which country you would like to fortify\n";
				string fcountry;
				cin >> fcountry;

				int army;
				cout << "Enter how many armies you would like to send:\n";
				cin >> army;
				while (army > p2->getTotalArmies()-1) {
					cout << "Not enough armies to fortify. Try again\n";
					cin >> army;
				}

				bool c = false;
				for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
				{
					if (origin->travel(i)->getName() == fcountry)
					{
						p2->fortify(origin->travel(i), army);
						p2->setTarget(origin->travel(i));
						cout << army << " armies has been sent to " << fcountry << endl;
						c = true;
					}

				}

				if (!c)
				{
					cout << "this country is not adjacent try again!\n";
					cin >> fcountry;
					for (int i = 0; i < origin->getNumberOfBorderingCountries(); i++)
					{
						if (origin->travel(i)->getName() == fcountry)
						{
							p2->fortify(origin->travel(i), army);
							p2->setTarget(origin->travel(i));
							cout << army << " armies has been sent to " << fcountry << endl;
							c = true;

						}
					}
				}

				cout << "You now have a total of " << p2->getTotalArmies() << " left.\n\n";
			}

		} while (menu != 0);
	
		delete p1;
		delete p2;

	return 0;
}
