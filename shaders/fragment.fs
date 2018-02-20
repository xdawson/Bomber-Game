#version 330 core

in vec2 texCoords;
out vec4 FragColour;

// texture sampler
uniform sampler2D tex;
uniform vec3 spriteColour;

void main()
{
	FragColour = vec4(spriteColour, 1.0f) * texture(tex, texCoords);
}