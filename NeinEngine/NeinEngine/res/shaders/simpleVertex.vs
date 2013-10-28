#version 330

in vec3 POSITION;

uniform mat4 transform;

void main(){
	gl_Position=transform*vec4(POSITION,1.0);
}