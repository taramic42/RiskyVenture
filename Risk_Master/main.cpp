#include "../../Risk/Board/GameBoard.h"
#include "../../Risk/GameUtility/GameLoop.h"

int main() {

	GameBoard newGame = GameBoard();

	newGame.setupBoard();

	GameLoop newGameLoop = GameLoop(newGame.getPlayerList(), newGame.getMap(), newGame.getDeck());

	newGameLoop.gameLoop();
	

	cin.get();
}