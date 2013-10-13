#version 330

in vec3 POSITION;

out vec4 color;

uniform mat4 transform;

void main()
{
	color = vec4(1,1,1,1.0);
	//color=vec4(COIN,1.0);
    gl_Position = transform*vec4(POSITION, 1.0);
}