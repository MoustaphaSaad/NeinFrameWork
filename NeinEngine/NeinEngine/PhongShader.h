#ifndef PHONGSHADERH
#define PHONGSHADERH
#include"Shader.h"
#include"material.h"
#include"Light.h"
#include<string>

class PhongShader : public Shader{
public:
	static PhongShader getInstance(){
		static PhongShader instance;
		return instance;
	}

	virtual void updateUniforms(const Matrix4& worldMatrix,const Matrix4& projection,Material material);

	static Vector3& getAmbientLight();
	static DirectionalLight& getDirectionalLight();

	static void setAmbientLight(const Vector3& ambientLight);
	static void setDirectionalLight(const DirectionalLight& directionalLight);
		PhongShader();
	~PhongShader();

	void setUniformD(std::string uniformName,DirectionalLight dirLight);
	void setUniformB(std::string uniformName,BaseLight Light);
private:
	static Vector3 m_ambientLight;
	static DirectionalLight m_directionalLight;


	PhongShader(PhongShader const&){}
};

#endif