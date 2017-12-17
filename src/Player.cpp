#include "Player.h"

Player::Player(std::vector<float> vertices)
	:vertices(vertices), model(glm::mat4(1.0f)), speed(0.05)
{}

void Player::moveLeft() {
	this->model = glm::translate(model, glm::vec3((-1.0f * this->speed), 0.0f, 0.0f));
}

void Player::moveRight() {
	this->model = glm::translate(model, glm::vec3((1.0f * this->speed), 0.0f, 0.0f));
}

void Player::moveUp() {
	this->model = glm::translate(model, glm::vec3(0.0f, (1.0f * this->speed), 0.0f));
}

void Player::moveDown() {
	this->model = glm::translate(model, glm::vec3(0.0f, (-1.0f * this->speed), 0.0f));
}