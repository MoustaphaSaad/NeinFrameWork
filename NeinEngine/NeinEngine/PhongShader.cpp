#include"PhongShader.h"
#include"Transform.h"

#include<iostream>
#include"MathAssists.h"

Vector3 PhongShader::m_ambientLight = Vector3(0.1f,0.1f,0.1f);
DirectionalLight PhongShader::m_directionalLight = DirectionalLight(BaseLight(Vector3(1,1,1), 0.5),Vector3(1,-1,-1));

PhongShader::PhongShader(){
	addVertexShaderFromFile("phongVertex.vs");
	addFragmentShaderFromFile("phongFragment.fs");

	compile();

	addUniform("transform");
	addUniform("trans");
	addUniform("baseColor");
	addUniform("ambientLight");

	addUniform("DirLight.base.color");
	addUniform("DirLight.base.intensity");
	addUniform("DirLight.direction");
}

PhongShader::~PhongShader()
{

}

void PhongShader::updateUniforms(const Matrix4& worldMatrix, const Matrix4& projectedMatrix,Material material)
{
	if(material.texture !=NULL)
		material.texture->bind();

	setUniform("transform", projectedMatrix);
	setUniform("trans",worldMatrix);
	setUniform("baseColor",material.color);
	setUniform("ambientLight",m_ambientLight);

	setUniformD("DirLight",m_directionalLight);
}

Vector3& PhongShader::getAmbientLight()
{
	return m_ambientLight;
}

DirectionalLight& PhongShader::getDirectionalLight()
{
	return m_directionalLight;
}

void PhongShader::setAmbientLight(const Vector3& ambientLight)
{
	PhongShader::m_ambientLight = ambientLight;
}

void PhongShader::setDirectionalLight(const DirectionalLight& directionalLight)
{
	PhongShader::m_directionalLight = directionalLight;
}

void PhongShader::setUniformD(std::string uniformName, DirectionalLight dirLight){
	setUniformB(uniformName +".base", dirLight.base);
	
	setUniform(uniformName +".direction", dirLight.direction);
}
void PhongShader::setUniformB(std::string uniformName, BaseLight Light){
	setUniform(uniformName +".color", Light.color);
	
	setUniform(uniformName +".intensity", Light.intensity);
}