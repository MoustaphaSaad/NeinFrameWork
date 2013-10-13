#ifndef PHONGSHADERH
#define PHONGSHADERH
#include"Shader.h"
#include"Light.h"

class PhongShader : public Shader{
public:
	static PhongShader* getInstance(){
		static PhongShader instance;
		return &instance;
	}

	virtual void updateUniforms(const Matrix4& worldMatrix,const Matrix4& projection);

	static Vector3& getAmbientLight();
	static DirectionalLight& getDirectionalLight();

	static void setAmbientLight(const Vector3& ambientLight);
	static void setDirectionalLight(const DirectionalLight& directionalLight);
private:
	static Vector3 m_ambientLight;
	static DirectionalLight m_directionalLight;

	PhongShader();
	~PhongShader();

	PhongShader(PhongShader const&){}
	void operator=(PhongShader const&){}
};

#endif