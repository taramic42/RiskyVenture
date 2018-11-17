#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class Subject
{
private:
	vector<Observer *> observerList;
public:
	Subject();
	~Subject();
	void addObserver(Observer *o);
	void removeObserver(Observer *o);
	void notify();
};

