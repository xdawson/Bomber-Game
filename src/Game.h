#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bomb.h"
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
	// The size of the window
	int screenWidth;
	int screenHeight;
	// The player
	Player player;
	// An array of bombs that can be fired
	std::vector<Bomb> bombs;
	// The game's camera (not currently written)
	// Camera camera;
	// Process the user's input and update the game world as a result
	void update(UserInput *inputs, double deltaTime);
};
#endif