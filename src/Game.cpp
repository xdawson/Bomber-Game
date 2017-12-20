#include "Game.h"

Game::Game(Player player)
	:player(player)
{}
void Game::update(UserInput *inputs) {
	if(inputs->left) {
		player.moveLeft();
	}
	if(inputs->right) {
		player.moveRight();
	}
	if(inputs->up) {
		player.moveUp();
	}
	if(inputs->down) {
		player.moveDown();
	}
	if(inputs->space) {
		// Launch a bomb
	}
}