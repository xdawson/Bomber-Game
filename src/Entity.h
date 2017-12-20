#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "Texture2D.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// A superclass for other game entities. 
class Entity {
public:
	// Model vertices and texture coords
	std::vector<float> vertices;
	// The models texture
	Texture2D texture;
	// The entity's position
	glm::mat4 model;
protected:
	// Protected constructor, only subclasses can access the constructor
	Entity(std::vector<float> vertices, glm::mat4 model);
};

#endif