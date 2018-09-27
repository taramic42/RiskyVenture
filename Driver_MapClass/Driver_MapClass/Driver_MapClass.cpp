// Driver_MapClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Map.h"


int main()
{

	int test[8] = {1,2,3,4,5,6,7,8};
	int size = sizeof(test) / sizeof(int);

	Country first = Country("test",9,9,"Nada", "One,two,Three");
	Country other = Country("This,1,2,had better,work,otherwise,I'll,freak");
	Continent second = Continent("other", 16);

	Map testMap = Map();

	second.addCountry(&first);
	second.addCountry(&other);

	testMap.addContinent(second);
	testMap.addCountry(first);
	testMap.addCountry(other);

	first.display();
	second.display();
	testMap.display();

	

	system("pause");
    return 0;
}

