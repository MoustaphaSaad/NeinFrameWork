#ifndef BASICPOSITIONCOLORSHADER
#define BASICPOSITIONCOLORSHADER

#include"Shader.h"
class BasicPositionColorShader : public Shader{
public:
	BasicPositionColorShader();
	~BasicPositionColorShader();
	BasicPositionColorShader(BasicPositionColorShader const&){}
	void operator=(BasicPositionColorShader const&){}
	static BasicPositionColorShader getInstance(){
		static BasicPositionColorShader instance;
		return instance;
	}
	void updateUniforms(const Matrix4& world,const Matrix4& projection);
private:
};
#endif