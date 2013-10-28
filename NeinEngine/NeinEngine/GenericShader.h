#ifndef GENERIXSHADERH
#define GENERIXSHADERH

#include"Shader.h"
#include<string>
using namespace std;
class GenericShader : public Shader{
public:
	GenericShader(string vs,string fs);
	GenericShader();
	~GenericShader();
	GenericShader(GenericShader const&){}
	void operator=(GenericShader const&){}
	static GenericShader getInstance(){
		if(instance == NULL);
			instance=new GenericShader();
		return *instance;
	}
	void updateUniforms(const Matrix4& world,const Matrix4& projection);
private:
	static GenericShader *instance;
};
#endif