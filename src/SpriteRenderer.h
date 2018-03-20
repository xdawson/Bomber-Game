#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <vector>
#include "Texture2D.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class SpriteRenderer {
public:
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();

	void DrawSprite(Texture2D &texture, glm::vec2 position, 
					glm::vec2 size = glm::vec2(10, 10), float rotationDeg = 0.0f, 
					glm::vec3 colour = glm::vec3(1.0f));
private:	
	Shader shader;
	unsigned int quadVAO;

	void initRenderData();
};

#endif