#include"Shader.h"
#include<cassert>
#include<memory>
#include<fstream>
#include<iostream>
#include<GL\glew.h>
#include"MathAssists.h"

static void checkShaderError(int shader,int flag, bool isProgram,const std::string& errorMsg);
static std::shared_ptr<std::string> loadShader(const std::string& fileName);

Shader::Shader(){
	this->m_program = glCreateProgram();
	if(m_program == 0){
		fprintf(stderr,"Error Creating Shader Program\n");
		exit(1);
	}
}

Shader::~Shader(){
	for(std::vector<int>::iterator it = m_shaders.begin();it != m_shaders.end();++it){
		glDetachShader(m_program,*it);
		glDeleteShader(*it);
	}
	glDeleteProgram(m_program);
}
void Shader::bind(){
	glUseProgram(m_program);
}
void Shader::addUniform(const std::string& uniformName){
	int location = glGetUniformLocation(m_program,uniformName.c_str());
	assert(location != INVALID_VALUE);
	m_uniforms.emplace(uniformName,location);
}
void Shader::addVertexShaderFromFile(const std::string& fileName){
	addVertexShader(*loadShader(fileName));
}
void Shader::addGeometryShaderFromFile(const std::string& fileName){
	addGeometryShader(*loadShader(fileName));
}
void Shader::addFragmentShaderFromFile(const std::string& fileName){
	addFragmentShader(*loadShader(fileName));
}
void Shader::addVertexShader(const std::string& text){
	addProgram(text,GL_VERTEX_SHADER);
}
void Shader::addFragmentShader(const std::string& text){
	addProgram(text,GL_FRAGMENT_SHADER);
}
void Shader::addGeometryShader(const std::string& text){
	addProgram(text,GL_GEOMETRY_SHADER);
}
void Shader::addProgram(const std::string& text,int type){
	int shader=glCreateShader(type);

	if(shader==0){
		fprintf(stderr,"ERROR creating Shader type %d\n",type);
		exit(1);
	}
	const GLchar*p[1];
	p[0] = text.c_str();
	GLint lengths[1];
	lengths[0] = text.length();

	glShaderSource(shader,1,p,lengths);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
	if(!success){
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shader,1024,NULL,InfoLog);
		fprintf(stderr,"Error Compiling Shader Type %d : '%s'\n",shader,InfoLog);
		exit(1);
	}
	glAttachShader(m_program,shader);
	m_shaders.push_back(shader);
}
void Shader::compile(){
	glLinkProgram(m_program);
	checkShaderError(m_program,GL_LINK_STATUS,true,"ERROR LINKING");

	glValidateProgram(m_program);
	checkShaderError(m_program,GL_LINK_STATUS,true,"ERROR Validating");

}
void Shader::setUniform(const std::string& name,int val){
	glUniform1i(m_uniforms.at(name),val);
}
void Shader::setUniform(const std::string& name,float val){
	glUniform1f(m_uniforms.at(name),val);
}
void Shader::setUniform(const std::string& name,const Vector3& val){
	glUniform3f(m_uniforms.at(name),val.x,val.y,val.z);
}
void Shader::setUniform(const std::string& name,const Matrix4& val){
	glUniformMatrix4fv(m_uniforms.at(name),1,GL_TRUE,&(val[0][0]));
}
static void checkShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
    GLchar error[1024] = { 0 };

	if(isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if(!success)
	{
		if(isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		fprintf(stderr, "%s: '%s'\n", errorMessage, error);
	}
}
static std::shared_ptr<std::string> loadShader(const std::string& fileName){
	std::ifstream file;
	file.open("./res/shaders/"+fileName);

	std::shared_ptr<std::string> output(new std::string());
	std::string line;
	if(file.is_open()){
		while(file.good()){
			getline(file,line);
			output->append(line+"\n");
		}
	}else{
		std::cerr<<"UNABLE TO LOAD FILE : "<<fileName<<std::endl;
	}
	return output;
}