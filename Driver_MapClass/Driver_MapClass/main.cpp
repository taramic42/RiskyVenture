#include <string>
#include <string>
#include <iostream>
#pragma once
#include "Player.h"


int main() {

	Player p1 = Player("a", "b");
	p1.attack();
	p1.reinforce();
	
	p1.attack();
	while (1) {}

}