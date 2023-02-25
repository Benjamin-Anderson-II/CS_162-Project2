#include "Game.h"

using namespace std;

int main(int argc, char const *argv[]) {
	Game* game = new Game();
	game->start();
	while(true){
		if(game->userTurn()) break;
		if(game->compTurn()) break;
	}
	game->end();
	delete game;
}