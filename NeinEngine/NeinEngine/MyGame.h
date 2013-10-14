#ifndef MYGAME
#define MYGAME
#include"NEngine.h"
#include"SDL.h"
class MyGame:public Game{
public :
	//Transform transform;
	//Camera cam;
	Sprite sprite;
	double s;
	void init(){
		/*cam = Camera();
		Transform::setProjection(70.0f,(float)Window::getWidth(),(float)Window::getHeight(),0.1f,1000.0f);
		Transform::setCamera(cam);*/
		s=0;
		sprite.setTexture("res//textures//texture.png");
		sprite.setRectangle(0,0,256,256);
	}
	void input(){
			//	cam.input();

		
		//printf("Input\n");
	}
	void update(){
		//printf("Update\n");

		s += gameTime::getDelta();
		//sprite.setScale(.1);
		//sprite.setRotation(45);
		//sprite.setPosition(Vector2(s*10,s*10));
	}
	void render(){
		sprite.Draw();

	}
};
#endif