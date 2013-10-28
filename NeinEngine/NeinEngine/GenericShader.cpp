#include"GenericShader.h"
GenericShader* GenericShader::instance=NULL;
GenericShader::GenericShader(){
}
GenericShader::GenericShader(string vs,string fs){
	addVertexShaderFromFile(vs);
	addFragmentShaderFromFile(fs);
	compile();
}
GenericShader::~GenericShader(){
}
static unsigned char whitePixel[] = {0xFF,0xFF,0xFF,0xFF};
void GenericShader::updateUniforms(const Matrix4& world,const Matrix4& projection){
	setUniform("transform",projection);
}