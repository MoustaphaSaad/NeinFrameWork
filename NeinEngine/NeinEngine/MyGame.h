#ifndef MYGAME
#define MYGAME
#include"NEngine.h"
#include"SDL.h"
#include<iostream>
using namespace std;
class MyGame:public Game{
public :
	Transform transform;
	Camera cam;
	Mesh<PositionVertex> mesh;
	Material mat;
	PhongShader shader;
	Skybox *sky;
	Sprite ss;
	GLuint fboId;

	// Z values will be rendered to this texture when using fboId framebuffer
	GLuint depthTextureId;

	double s;
	void init(){
		cam = Camera();
		Transform::setProjection(70.0f,(float)Window::getWidth(),(float)Window::getHeight(),0.1f,1000.0f);
		Transform::setCamera(cam);
		s=0;
		ss.setTexture("res//textures//texture.jpg");
		OBJLoader::LoadMesh("res//models//bunny.obj",&mesh);
		sky= new Skybox(Texture("res//textures//skybox//top.jpg"),
			Texture("res//textures//skybox//bottom.jpg"),
			Texture("res//textures//skybox//front.jpg"),
			Texture("res//textures//skybox//behind.jpg"),
			Texture("res//textures//skybox//right.jpg"),
			Texture("res//textures//skybox//left.jpg"));

		Texture x("res//textures//texture.jpg");
		transform.setPosition(Vector3(0,0,0));
		shader.setAmbientLight(Vector3(.2,.2,.2));
		mat.color = Vector3(1,1,1);
		ss.setScale(.5);
	}
	void input(){
		cam.input();
		//transform.setRotation(Vector3(1,-1,-1));
	}
	

	void update(){
		
		s += gameTime::getDelta();
		//transform.setRotation(Vector3(0,s*10,0));
	}

	void render(){
		ss.Draw(depthTextureId);
		sky->Render(cam.getPosition());
		shader.bind();
		shader.updateUniforms(transform.getTransformation(),transform.getProjectedTransformation(),mat);
		//plane.draw();
		mesh.draw();
	}
};
#endif