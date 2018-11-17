#include "Subject.h"

#include<iostream>

Subject::Subject()
{
	observerList = vector<Observer*>();
}


Subject::~Subject()
{
	//observerList.clear();
}

void Subject::addObserver(Observer * o)
{
	for (int i = 0; i < observerList.size(); i++)
		if (o == observerList[i])
			return;
	observerList.push_back(o);
}

void Subject::removeObserver(Observer * o)
{
	for(int i =  0; i<observerList.size();i++)
		if (o == observerList[i]) {
			observerList.erase(observerList.begin() + i);
		}
}

void Subject::notify()
{
	for (int i = 0; i < observerList.size(); i++)
		observerList[i]->update();
}

