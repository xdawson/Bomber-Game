#ifndef BOMB_H
#define BOMB_H

#include "Texture2D.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Bomb {
public:
	Bomb();
	//Texture2D texture;
	glm::vec2 position;
	glm::vec2 size;
	float rotationDeg;
	glm::vec3 colour;

	glm::vec2 AABBCentre;
	glm::vec2 AABBHalfLengths;
};

#endif