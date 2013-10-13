#include"BasicPositionTextureShader.h"
BasicPositionTextureShader::BasicPositionTextureShader(){
	addVertexShaderFromFile("basicPositionTextureVertex.vs");
	addFragmentShaderFromFile("basicPositionTextureFragment.fs");
	compile();

	addUniform("transform");
	//addUniform("color");
}
BasicPositionTextureShader::~BasicPositionTextureShader(){
}
static unsigned char whitePixel[] = {0xFF,0xFF,0xFF,0xFF};
void BasicPositionTextureShader::updateUniforms(const Matrix4& world,const Matrix4& projection){
	setUniform("transform",projection);
}