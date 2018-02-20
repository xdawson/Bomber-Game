#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"

// user input (to be moved somewhere else)
struct UserInput {
	bool up;
	bool down;
	bool left;
	bool right;
	bool space;
};

class Game {
public:	
	Game(int screenWidth, int screenHeight);
	void init();
	// The size of the window
	int screenWidth;
	int screenHeight;
	// The player
	Player player;
	// The game's camera (not currently written)
	// Camera camera;
	// Process the user's input and update the game world as a result
	void update(UserInput *inputs);
};
#endif