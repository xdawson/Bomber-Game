#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "ResourceManager.h"
#include "Player.h"
#include "Game.h"


// function declarations
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processKeyboardInput(GLFWwindow* window, UserInput *inputs);
GLFWwindow *openGLInit(int windowWidth, int windowHeight);

// settings
const unsigned int SRC_WIDTH = 800;
const unsigned int SRC_HEIGHT = 600;

int main(int argc, char **argv) {							
	GLFWwindow *window = openGLInit(SRC_WIDTH, SRC_HEIGHT);
	if(window) {
		// configure global opengl state
		// -----------------------------
		glEnable(GL_DEPTH_TEST);

		// The user inputs
		UserInput inputs = {false, false, false, false, false};


		// The game
		Game game(SRC_WIDTH, SRC_HEIGHT);

		// render loop
		// -----------
		while(!glfwWindowShouldClose(window)) {								
			// input
			// -----
			processKeyboardInput(window, &inputs);	

			// Render the results
			// ------------------

			// render
			// ------
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

			// Pass control to the game to update the game world
			// -------------------------------------------------
			game.update(&inputs);				

			// glfw: swap buffers and poll IO events
			glfwSwapBuffers(window);
			glfwPollEvents();

			// Clear the inputs struct
			inputs = {false, false, false, false, false};
		}
	}
	else {

	}
	// glfw: terminate, clearing all previously allocated GLFW resources
	// -----------------------------------------------------------------
	glfwTerminate();
	return 0;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processKeyboardInput(GLFWwindow* window, UserInput *inputs)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		std::cout << "Esc key pressed, closing window" << std::endl;
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else {
		if((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) || (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)) {
			inputs->left = true;
		}
		if((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) ||  (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)) {
			inputs->right = true;
		}
		if((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) || (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)) {
			inputs->up = true;
		}
		if((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ||(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)) {
			inputs->down = true;
		}
		if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			inputs->space = true;
		}
	}		
}

// Use GLFW to open a window, make the opengl context current on this thread and use GLAD to load opengl functions
GLFWwindow *openGLInit(int windowWidth, int windowHeight) {
	if(glfwInit()) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Space Bomber", NULL, NULL);

	    if(window != nullptr) {
	    	glfwMakeContextCurrent(window);
			glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

			if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				return window;
			}
			else {
				std::cout << "Failed to initialise GLAD" << std::endl;
				return nullptr;
			}
	    }
	    else {
	    	std::cout << "Window failed to create" << std::endl;
	    	return nullptr;
	    }
	}
	else {
		std::cout << "GLFW failed to initialise" << std::endl;
		return nullptr;
	}
}





















