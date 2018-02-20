#include "Game.h"

// Renderer
SpriteRenderer *renderer;

Game::Game(int screenWidth, int screenHeight)
	:screenWidth(screenWidth), screenHeight(screenHeight), player()
{	
	// Load shader
	ResourceManager::loadShader("../shaders/vertex.vs", "../shaders/fragment.fs", nullptr, "sprite");
	// Configure shaders
	ResourceManager::getShader("sprite").use();

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);				
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
	projection = glm::ortho(0.0f, (float)this->screenWidth, (float)this->screenHeight, 0.0f, -1.0f, 1.0f);
	// set the uniform matrices in the vertex shader					
	ResourceManager::getShader("sprite").setMatrix4("view", view);
	ResourceManager::getShader("sprite").setMatrix4("projection", projection);

	// Load player texture
	this->player.texture = ResourceManager::loadTexture("../textures/bomber.png", true, "player");

	// Set render-specific controls
	Shader myShader = ResourceManager::getShader("sprite");
	renderer = new SpriteRenderer(myShader);
}

void Game::update(UserInput *inputs) {
	if(inputs->left) {
		player.moveLeft();
	}
	if(inputs->right) {
		player.moveRight();
	}
	if(inputs->up) {
		player.moveUp();
	}
	if(inputs->down) {
		player.moveDown();
	}
	if(inputs->space) {
		// Launch a bomb
	}

	renderer->DrawSprite(this->player.texture, this->player.position, this->player.size, this->player.rotationDeg, this->player.colour);
}