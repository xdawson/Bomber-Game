#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <glad/glad.h>

// Texture2D is able to store and configure a texture in OpenGL.
// It also hosts utility functions for easy management
class Texture2D {
public:
	// Holds the ID of this texture, used in all texture operations
	unsigned int ID;
	// Texture image dimensions
	unsigned int width, height;
	// Texture format
	unsigned int internalFormat; // Format of the texture object
	unsigned int imageFormat; // Format of loaded image
	// Texture configuration
	unsigned int wrapS; // Wrapping mode of S axis
	unsigned int wrapT; // Wrapping mode of T axis
	unsigned int filterMin; // Filtering mode when scaling a texture down
	unsigned int filterMag; // Filtering moe when scaling  a texture up
	// Constructor (sets default texture modes)
	Texture2D();
	// Generates a texture from image data
	void generate(unsigned int width, unsigned int height, unsigned char *data);
	// Binds the texture as the current active GL_TEXTURE_2D object
	void bind() const;
private:
};

#endif