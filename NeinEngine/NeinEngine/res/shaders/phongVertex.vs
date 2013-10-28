#version 330

in vec3 POSITION;
in vec3 NORMAL;

out vec3 normal0;

uniform mat4 transform;
uniform mat4 trans;

void main()
{
	//color=vec4(COIN,1.0);
    gl_Position = transform*vec4(POSITION, 1.0);
	normal0=(trans*vec4(NORMAL,0.0)).xyz;
}