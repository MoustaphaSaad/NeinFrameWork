#version 330

//in vec2 texCoord0;

out vec4 fragColor;

in vec3 normal0;

uniform vec3 baseColor;
uniform vec3 ambientLight;
//uniform sampler2D sampler;

struct BaseLight{
	vec3 color;
	float intensity;
};

struct DirectionalLight{
	BaseLight base;
	vec3 direction;
};


uniform DirectionalLight DirLight;


vec4 calcLight(BaseLight base, vec3 dir, vec3 normal){
	float diffuseFactor= dot(-dir,normal);
	vec4 diffuseColor = vec4(0,0,0,0);
	
	if(diffuseFactor>0)
		diffuseColor = vec4(base.color,1.0)*diffuseFactor*base.intensity;
		
		
	return diffuseColor;
}

vec4 calcDirectionalLight(DirectionalLight dirLight, vec3 normal){
	return calcLight(dirLight.base,dirLight.direction, normal);
}

void main()
{
	vec4 totalLight = vec4(ambientLight,1.0);
	vec3 normal = normalize(normal0);
	totalLight += calcDirectionalLight(DirLight,normal);
	fragColor =  vec4(baseColor,1.0)*totalLight;
    //fragColor = texture(sampler, texCoord0.xy) * vec4(color, 1);
}