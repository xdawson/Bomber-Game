#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity{
public:
	// Constructor
	Player(std::vector<float> vertices);
	// Player speed of movement
	float speed;
	// Movement for the Player model
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};
#endif