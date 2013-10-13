#ifndef LIGHTH
#define LIGHTH
#include"Vector3.h"
struct BaseLight{
	Vector3 color;
	float intensity;
	BaseLight(Vector3 color = Vector3(0,0,0),float intensity = 0){
		this->color = color;
		this->intensity = intensity;
	}
};
struct DirectionalLight{
	BaseLight base;
	Vector3 direction;

	DirectionalLight(BaseLight base = BaseLight(),Vector3 direction = Vector3(0,0,0)){
		this->base = base;
		this->direction = direction;
	}
};
#endif