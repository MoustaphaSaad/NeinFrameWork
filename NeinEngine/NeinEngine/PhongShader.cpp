#include"PhongShader.h"
#include"Transform.h"

#include<iostream>
#include"MathAssists.h"

Vector3 PhongShader::m_ambientLight = Vector3(0.1f,0.1f,0.1f);
DirectionalLight PhongShader::m_directionalLight = DirectionalLight(BaseLight(Vector3(0,0,0), 0),Vector3(0,0,0));