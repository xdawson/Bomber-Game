#include "Game.h"

// Renderer
SpriteRenderer *renderer;

Game::Game(int screenWidth, int screenHeight)
<<<<<<< HEAD
	:screenWidth(screenWidth), screenHeight(screenHeight), player(), bombs() 
=======
	:screenWidth(screenWidth), screenHeight(screenHeight), player()
>>>>>>> origin/master
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

<<<<<<< HEAD
	ResourceManager::loadTexture("../textures/bomb.png", false, "bomb");
	ResourceManager::loadTexture("../textures/border.png", false, "border");

=======
>>>>>>> origin/master
	// Set render-specific controls
	Shader myShader = ResourceManager::getShader("sprite");
	renderer = new SpriteRenderer(myShader);
}

<<<<<<< HEAD
void Game::update(UserInput *inputs, double deltaTime) {	
	// NOTE: temp static that should later be moved somewhere
	static float fireTime = 1.0f;
	fireTime += deltaTime;

	// Process the inputs
	// ------------------
=======
void Game::update(UserInput *inputs) {
>>>>>>> origin/master
	if(inputs->left) {
		player.moveLeft(deltaTime);
		player.isFacingLeft = true;
	}
	if(inputs->right) {
		player.moveRight(deltaTime);
		player.isFacingLeft = false;
	}
	if(inputs->up) {
		player.moveUp(deltaTime);
	}
	if(inputs->down) {
		player.moveDown(deltaTime);
	}
	if(inputs->space) {
		// Launch one bomb per second
		if(fireTime >= 1.0f) {
			Bomb newBomb;
			newBomb.position = this->player.position;
			newBomb.AABBCentre = newBomb.position + newBomb.AABBHalfLengths;		
			this->bombs.push_back(newBomb);	
			fireTime = 0.0f;
		}
	}
	
	// Process physics on all the game objects
	// ---------------------------------------
	for(auto& bomb : this->bombs) {
		bomb.position.y += 1.0f;
		bomb.AABBCentre.y += 1.0f;
	}

	// Process collision detection
	// ---------------------------
	// (just bomb vs ground for now)
	glm::vec2 borderAABBCentre(400.0f, 600.0f);
	glm::vec2 borderAABBHalfLengths(400.0f, 50.0f); 

	for(auto& bomb : this->bombs) {
		glm::vec2 cosDist = glm::abs(bomb.AABBCentre - borderAABBCentre) - (bomb.AABBHalfLengths + borderAABBHalfLengths);

		// Only need the y since right now bombs only fall so there will never be an x collision
		if(cosDist.y < 0) {
			// Move the bomb outside of the collision area
			bomb.position.y += cosDist.y;
			bomb.AABBCentre.y += cosDist.y;
		}
	}

<<<<<<< HEAD

	// Draw the game objects
	// ---------------------
	if(player.isFacingLeft) {
		renderer->DrawSprite(this->player.texture, this->player.position, glm::vec2(-this->player.size.x, this->player.size.y), this->player.rotationDeg, this->player.colour);
	} else {
		renderer->DrawSprite(this->player.texture, this->player.position, this->player.size, this->player.rotationDeg, this->player.colour);
	}

	// Draw all the bombs
	Texture2D bombTex = ResourceManager::getTexture("bomb");
	for(auto& bomb : this->bombs) {		
		renderer->DrawSprite(bombTex, bomb.position, bomb.size, bomb.rotationDeg, bomb.colour);
	}

	// Draw the border
	Texture2D borderTex = ResourceManager::getTexture("border");
	renderer->DrawSprite(borderTex, glm::vec2(0.0f, 550.0f), glm::vec2(800.0f, 100.0f), 0.0f, glm::vec3(1.0f));
	
=======
	renderer->DrawSprite(this->player.texture, this->player.position, this->player.size, this->player.rotationDeg, this->player.colour);
>>>>>>> origin/master
}