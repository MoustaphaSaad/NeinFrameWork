#ifndef MYGAME
#define MYGAME
#include"NEngine.h"
#include"SDL.h"
class MyGame:public Game{
public :
	Transform transform;
	Camera cam;
	Sprite sprite;
	double s;
	void init(){
		cam = Camera();
		Transform::setProjection(70.0f,(float)Window::getWidth(),(float)Window::getHeight(),0.1f,1000.0f);
		Transform::setCamera(cam);
		s=0;
		sprite.setTexture(Texture("texture.png"));
		sprite.setRotation(Vector3(45,0,0));
	}
	void input(){
				cam.input();

		
		//printf("Input\n");
	}
	void update(){
		//printf("Update\n");

		s += gameTime::getDelta();
		sprite.setScale(.5);
		sprite.setPosition(Vector3(0,0,1));
	}
	void render(){
		sprite.Draw();

	}
};
#endif