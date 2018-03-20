#include "Bomb.h"

Bomb::Bomb() 
	:position(glm::vec2(0.0f, 0.0f)), size(glm::vec2(20.0f, 10.0f)), rotationDeg(0.0f), colour(glm::vec3(1.0f)), 
	 AABBCentre(glm::vec2(10.0f, 5.0f)), AABBHalfLengths(glm::vec2(10.f, 5.0f))
{}