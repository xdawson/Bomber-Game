#include "Entity.h"

Entity::Entity(std::vector<float> vertices, glm::mat4 model) 
	:vertices(vertices), model(model)
{}