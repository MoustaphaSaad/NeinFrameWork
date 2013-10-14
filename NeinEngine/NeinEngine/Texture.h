#ifndef TEXTUREH
#define TEXTUREH
#include<GL\glew.h>
#include<string>

class Texture{
public :
	Texture(const std::string& filename,GLenum textureTraget = GL_TEXTURE_2D,GLfloat filter = GL_LINEAR);
	Texture(int width=0,int height=0,unsigned char* data = 0,GLenum textureTarget=GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);
	~Texture();

	void bind(GLenum textureUnit = GL_TEXTURE0);
	Texture(Texture& texture);
	void operator=(Texture& texture);
	int getWidth(){
		return Width;
	}
	int getHeight(){
		return Height;
	}
	GLenum getTarget(){
		return m_textureTarget;
	}
	GLuint getID(){
		return m_textureID;
	}
	unsigned char* getData(){
		return Data;
	}
private:
	static Texture* m_lastBind;
	GLenum m_textureTarget;
	GLuint m_textureID;
	bool m_freeTexture;
	int Width,Height;
	unsigned char* Data;

	void initTexture(int width,int height,unsigned char* data,GLenum textureTarget,GLfloat filter);

};

#endif