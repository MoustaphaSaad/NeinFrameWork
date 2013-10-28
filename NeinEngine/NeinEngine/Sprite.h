#ifndef SPRITEH
#define SPRITEH
#include"Texture.h"
#include"Mesh.h"
#include"Transform.h"
#include"Vertex.h"
#include"BasicPositionTextureShader.h"
#include"SDL.h"
class Sprite{
	Texture* texture;
	int W,H;
	Vector2 position;float rotation,scale;
	Quaternion rect;
public:
	Sprite(Vector2 position=Vector2(0,0),float rotation = 0,float scale = 1,Quaternion RECT=Quaternion(0,0,0,0)){
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		rect = RECT;
	}
	void setPosition(Vector2 val){
		this->position = val;
	}
	void setRotation(float val){
		this->rotation = val;
	}
	void setScale(float val){
		this->scale = val;
	}
	void setTexture(char* filename){
		texture = new Texture(filename);
		rect=Quaternion(0,0,texture->getWidth(),texture->getHeight());
	}
	void setTexture(Texture *filename){
		texture = filename;
	}
	Vector2 getPosition(){
		return position;
	}
	float getRotation(){
		return rotation;
	}
	float getScale(){
		return scale;
	}
	void setRectangle(int x,int y,int W,int H){
		rect = Quaternion(x,y,W,H);
	}
	Quaternion getRectangle(){
		return rect;
	}
	
	void Draw(GLuint ID=0){
		glUseProgram(0);
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluOrtho2D (0, Window::getWidth(), Window::getHeight(),0);
		glEnable(GL_TEXTURE_2D);
		if(!ID)
			texture->bind();
		else
			glBindTexture(GL_TEXTURE_2D,ID);
		glScalef(scale,scale,0);
		glRotatef(rotation,0,0,1);
		glBegin(GL_QUADS);
		

		glTexCoord2f(rect.x/texture->getWidth()+0,rect.y/texture->getHeight()+0); 
		glVertex2f(position.x,position.y);
		glTexCoord2f(rect.z/texture->getWidth(),0); 
		glVertex2f(texture->getWidth()+position.x,position.y);
		glTexCoord2f(rect.z/texture->getWidth(),rect.w/texture->getHeight()); 
		glVertex2f(texture->getWidth()+position.x,texture->getHeight()+position.y);
		glTexCoord2f(0,rect.w/texture->getHeight()); 
		glVertex2f(position.x,texture->getHeight()+position.y);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glMatrixMode (GL_MODELVIEW);
	}
};
#endif