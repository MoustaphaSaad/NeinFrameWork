#ifndef BASICPOSITIONTEXTURESHADER
#define BASICPOSITIONTEXTURESHADER

#include"Shader.h"
class BasicPositionTextureShader : public Shader{
public:
	BasicPositionTextureShader();
	~BasicPositionTextureShader();
	BasicPositionTextureShader(BasicPositionTextureShader const&){}
	void operator=(BasicPositionTextureShader const&){}
	static BasicPositionTextureShader getInstance(){
		static BasicPositionTextureShader instance;
		return instance;
	}
	void updateUniforms(const Matrix4& world,const Matrix4& projection);
private:
};
#endif