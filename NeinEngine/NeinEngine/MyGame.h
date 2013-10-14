#ifndef MYGAME
#define MYGAME
#include"NEngine.h"
#include"SDL.h"
class MyGame:public Game{
public :
	Transform transform;
	Camera cam;
	Mesh<PositionVertex> mesh;
	BasicPositionShader shader;
	//Sprite sprite;
	double s;
	void init(){
		cam = Camera();
		Transform::setProjection(70.0f,(float)Window::getWidth(),(float)Window::getHeight(),0.1f,1000.0f);
		Transform::setCamera(cam);
		s=0;
		OBJLoader::LoadMesh("res//models//bunny.obj",&mesh);
		shader = BasicPositionShader::getInstance();
		/*sprite.setTexture("res//textures//texture.png");
		sprite.setRectangle(0,0,256,256);*/
		transform.setPosition(Vector3(0,0,3));
	}
	void input(){
		cam.input();

	}
	void update(){

		s += gameTime::getDelta();
		transform.setRotation(Vector3(0,s*10,0));
	}
	void render(){
		shader.bind();
		shader.updateUniforms(transform.getTransformation(),transform.getProjectedTransformation());
		mesh.draw();
	}
};
#endif