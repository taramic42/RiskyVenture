// Risk_Master.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../Risk/Board/GameBoard.h"
#include "../../Risk/GameUtility/GameLoop.h"

int main()
{
	GameBoard game = GameBoard();
	game.setupBoard();

	game.giveAllCountriesToPlayer(0);

	system("pause");

    return 0;
}

