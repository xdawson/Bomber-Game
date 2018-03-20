#include "Player.h"

Player::Player()
<<<<<<< HEAD
	:texture(), position(glm::vec2(1.0f)), size(glm::vec2(50.0f)), rotationDeg(0.0f), colour(glm::vec3(1.0f)), speed(350.0f), isFacingLeft(false)
{}

void Player::moveLeft(double deltaTime) {
	this->position += glm::vec2((-1.0f * this->speed * deltaTime), 0.0f);  
	//glm::translate(glm::vec3(position, 0.0f), glm::vec3((-1.0f * this->speed), 0.0f, 0.0f));
}

void Player::moveRight(double deltaTime) {
	this->position += glm::vec2((1.0f * this->speed * deltaTime), 0.0f);
}

void Player::moveUp(double deltaTime) {
	this->position += glm::vec2(0.0f, (-1.0f * this->speed * deltaTime));
}

void Player::moveDown(double deltaTime) {
	this->position += glm::vec2(0.0f, (1.0f * this->speed * deltaTime));
=======
	:texture(), position(glm::vec2(1.0f)), size(glm::vec2(100.0f)), rotationDeg(0.0f), colour(glm::vec3(1.0f)), speed(1.0f)
{}

void Player::moveLeft() {
	this->position += glm::vec2((-1.0f * this->speed), 0.0f);  
	//glm::translate(glm::vec3(position, 0.0f), glm::vec3((-1.0f * this->speed), 0.0f, 0.0f));
}

void Player::moveRight() {
	this->position += glm::vec2((1.0f * this->speed), 0.0f);
}

void Player::moveUp() {
	this->position += glm::vec2(0.0f, (-1.0f * this->speed));
}

void Player::moveDown() {
	this->position += glm::vec2(0.0f, (1.0f * this->speed));
>>>>>>> origin/master
}