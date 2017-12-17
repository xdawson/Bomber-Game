#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "ResourceManager.h"
#include "Player.h"

// function declarations
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processKeyboardInput(GLFWwindow* window, Player *player);
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

		std::vector<float> playerVertices = {
			// positions  // texture coords
			-0.5f,  0.5f, 0.0f, 1.0f,	// top left
			-0.5f, -0.5f, 0.0f, 0.0f,	// bottom left		
			 0.5f, -0.5f, 1.0f, 0.0f	// bottom right
		};

		// The Player
		Player *player = new Player(playerVertices);
		

		// build and compile the shader program
		// ------------------------------------
		Shader shaderProg = ResourceManager::loadShader("../shaders/vertex.vs", "../shaders/fragment.fs", nullptr, "default");

		// generate the player texture
		player->texture = ResourceManager::loadTexture("../textures/bomber.png", true, "player");

		

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO); 

		glBindBuffer(GL_ARRAY_BUFFER, VBO);  
		glBufferData(GL_ARRAY_BUFFER, player->vertices.size() * sizeof(float), &player->vertices[0], GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// texture attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));
		glEnableVertexAttribArray(1);

		// render loop
		// -----------
		while(!glfwWindowShouldClose(window)) {								
			// input
			// -----
			processKeyboardInput(window, player);	

			// render
			// ------
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);					

			// bind player texture
			glBindTexture(GL_TEXTURE_2D, player->texture.ID);
	
			shaderProg.use();

			// GLM camera work
			// ----------------			
			glm::mat4 view = glm::mat4(1.0f);
			glm::mat4 projection = glm::mat4(1.0f);				
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
			projection = glm::perspective(glm::radians(45.0f), ((float)SRC_WIDTH / (float)SRC_HEIGHT), 0.1f, 100.0f);
			// set the uniform matrices in the vertex shader					
			shaderProg.setMatrix4("view", view);
			shaderProg.setMatrix4("projection", projection);

			// render container
			glBindVertexArray(VAO);
						
			shaderProg.setMatrix4("model", player->model);

			glDrawArrays(GL_TRIANGLES, 0, 3);

			// glfw: swap buffers and poll IO events
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		// de-allocate all resources once they've outlived their purpose
		// -------------------------------------------------------------
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
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

void processKeyboardInput(GLFWwindow* window, Player *player)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		std::cout << "Esc key pressed, closing window" << std::endl;
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else {
		if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			player->moveLeft();
		}
		if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			player->moveRight();
		}
		if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			player->moveUp();
		}
		if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			player->moveDown();
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





















