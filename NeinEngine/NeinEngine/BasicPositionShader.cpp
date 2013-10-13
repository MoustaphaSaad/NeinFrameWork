#include"BasicPositionShader.h"
BasicPositionShader::BasicPositionShader(){
	addVertexShaderFromFile("basicPositionVertex.vs");
	addFragmentShaderFromFile("basicFragment.fs");
	compile();

	addUniform("transform");
	//addUniform("color");
}
BasicPositionShader::~BasicPositionShader(){
}
static unsigned char whitePixel[] = {0xFF,0xFF,0xFF,0xFF};
void BasicPositionShader::updateUniforms(const Matrix4& world,const Matrix4& projection){
	setUniform("transform",projection);
}