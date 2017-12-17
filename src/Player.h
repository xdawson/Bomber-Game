#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Texture2D.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Player {
public:
	// Constructor
	Player(std::vector<float> vertices);
	// Contains the 2D coordinates of the Player's vertices and the Texture coordinates
	std::vector<float> vertices;
	// The Player's texture
	Texture2D texture;
	// The matrix corresponding to the Player position
	glm::mat4 model;
	// Player speed of movement
	float speed;
	// Movement for the Player model
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};
#endif