#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include<map>
#include<string>

#include "Texture2D.h"
#include "Shader.h"

// A static singleton ResourceManager class that hosts several functions to load Textures and Shaders.
// Each loaded Texture and/or Shader is also stored for future reference by string handles. All
// functions and resources are static and no public constructor is defined.
class ResourceManager
{
public:
	//Resource storage
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture2D> textures;
	// Loads (and generates) a shader program from file, loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr it loads a geometry shader
	static Shader loadShader(const char* vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
	// Retrieves a stored Shader
	static Shader getShader(std::string name);
	// Loads (and generates) a Texture from file
	static Texture2D loadTexture(const char *file, bool alpha, std::string name);
	// Retrieves a stored texture
	static Texture2D getTexture(std::string name);
	// Properly de-allocate all loaded resources
	static void clear();
private:
	// Private constructor since I don't want any actual ResourceManager objects.
	ResourceManager() { };
	// Loads and generates a Shader from file
	static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
	// Loads a single texture from file
	static Texture2D loadTextureFromFile(const char *file, bool alpha);
};

#endif