#ifndef BASICPOSITIONSHADER
#define BASICPOSITIONSHADER

#include"Shader.h"
class BasicPositionShader : public Shader{
public:
	BasicPositionShader();
	~BasicPositionShader();
	BasicPositionShader(BasicPositionShader const&){}
	void operator=(BasicPositionShader const&){}
	static BasicPositionShader getInstance(){
		static BasicPositionShader instance;
		return instance;
	}
	void updateUniforms(const Matrix4& world,const Matrix4& projection);
private:
};
#endif