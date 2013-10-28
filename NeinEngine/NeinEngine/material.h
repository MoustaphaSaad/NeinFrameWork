#ifndef MATERIAL_H
#define MATERIAL_H

#include "texture.h"
#include "vector3.h"

struct Material
{
	Texture* texture;
	Vector3 color;

	Material(Texture* texture = NULL, const Vector3& color = Vector3(1,1,1), float specularIntensity = 2, float specularPower = 32)
	{
		this->texture = texture;
		this->color = color;
		
	}
};

#endif