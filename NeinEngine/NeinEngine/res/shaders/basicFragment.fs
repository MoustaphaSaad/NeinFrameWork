#version 330

//in vec2 texCoord0;

out vec4 fragColor;
in vec4 color;
//uniform vec3 color;
//uniform sampler2D sampler;

void main()
{
	fragColor = color;
    //fragColor = texture(sampler, texCoord0.xy) * vec4(color, 1);
}