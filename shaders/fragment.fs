#version 330 core

out vec4 FragColour;

in vec2 texCoords;

// texture sampler
uniform sampler2D tex;

void main()
{
	FragColour = texture(tex, texCoords);
}