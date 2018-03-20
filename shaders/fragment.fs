#version 330 core

in vec2 texCoords;
out vec4 FragColour;

// texture sampler
uniform sampler2D tex;
uniform vec3 spriteColour;

void main()
{
	vec4 texel = texture(tex, texCoords);
	if(texel.a < 0.5)
		discard;
	FragColour = vec4(spriteColour, 1.0f) * texel;

	//FragColour = vec4(spriteColour, 1.0f) * texture(tex, texCoords);
}