#ifndef PLAYER_H
#define PLAYER_H

#include "Texture2D.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Player {
public:
	// Constructor
	Player();
	// The model's texture
	Texture2D texture;
	// The player's position
	glm::vec2 position;
	// The player's size
	glm::vec2 size;
	// The player's rotation in degrees
	float rotationDeg;
	// The player's colour
	glm::vec3 colour;
	// Player speed of movement
	float speed;
	// The direction the player is facing
	bool isFacingLeft;
	// Movement for the Player model
	void moveLeft(double deltaTime);
	void moveRight(double deltaTime);
	void moveUp(double deltaTime);
	void moveDown(double deltaTime);
};
#endif