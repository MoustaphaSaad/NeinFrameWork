#version 330


in vec3 POSITION;
in vec2 TEXCOORD;
in vec3 NORMAL;

out vec2 texCoord0;
out vec3 normal0;

uniform mat4 transform;

void main()
{
	//color=vec4(COIN,1.0);
    gl_Position = transform*vec4(POSITION, 1.0);
	texCoord0 = TEXCOORD;
	normal0 = NORMAL;
}