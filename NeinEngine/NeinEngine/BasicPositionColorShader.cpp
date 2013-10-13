#include"BasicPositionColorShader.h"
BasicPositionColorShader::BasicPositionColorShader(){
	addVertexShaderFromFile("basicPositionColorVertex.vs");
	addFragmentShaderFromFile("basicFragment.fs");
	compile();

	addUniform("transform");
	//addUniform("color");
}
BasicPositionColorShader::~BasicPositionColorShader(){
}
static unsigned char whitePixel[] = {0xFF,0xFF,0xFF,0xFF};
void BasicPositionColorShader::updateUniforms(const Matrix4& world,const Matrix4& projection){
	setUniform("transform",projection);
}