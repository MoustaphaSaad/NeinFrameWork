#ifndef SHADER
#define SHADER
#include<string>
#include"Matrix4.h"
#include"Vector3.h"
#include<unordered_map>
class Shader{
public:
	Shader();
	~Shader();
	
	void bind();
	void addUniform(const std::string& uniform);
	void addVertexShaderFromFile(const std::string& fileName);
	void addGeometryShaderFromFile(const std::string& fileName);
	void addFragmentShaderFromFile(const std::string& fileName);
	void addVertexShader(const std::string& text);
	void addGeometryShader(const std::string& text);
	void addFragmentShader(const std::string& text);
	void compile();

	//virtual void updateUniforms(const Matrix4& worldMatrix,const Matrix4& projectionMatrix);

	void setUniform(const std::string& name,int val);
	void setUniform(const std::string& name,float val);
	void setUniform(const std::string& name,const Vector3& val);
	void setUniform(const std::string& name,const Matrix4& val);

private:
	int m_program;
	std::unordered_map<std::string,int> m_uniforms;
	std::vector<int> m_shaders;

	void addProgram(const std::string& text, int type);
};
#endif