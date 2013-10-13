#ifndef SPRITEH
#define SPRITEH
#include"Texture.h"
#include"Mesh.h"
#include"Transform.h"
#include"Vertex.h"
#include"BasicPositionTextureShader.h"
class Sprite{
	BasicPositionTextureShader shader;
	Texture texture;
	Mesh<PositionTextureVertex> mesh;
	Transform transform;
	Vector3 position,rotation,scale;
	void setRectangle(){
		mesh = Mesh<PositionTextureVertex>();
		PositionTextureVertex data[] = {
			PositionTextureVertex(Vector3(-1,-1,1),Vector2(0,1),Vector3(0,0,0)),
			PositionTextureVertex(Vector3(-1,1,1),Vector2(0,0),Vector3(0,0,0)),
			PositionTextureVertex(Vector3(1,1,1),Vector2(1,0),Vector3(0,0,0)),
			PositionTextureVertex(Vector3(1,-1,1),Vector2(1,1),Vector3(0,0,0)),
		};
		int IData[] = {0,1,2,2,3,0};
		mesh.addVertices(data,ARRAY_SIZE(data),IData,ARRAY_SIZE(IData));
	}
	void update(){
		transform.setPosition(position);
		transform.setRotation(rotation);
		transform.setScale(scale);
	}
public:
	Sprite(Vector3 position=Vector3(0,0,0),Vector3 rotation=Vector3(0,0,0),Vector3 scale = Vector3(1,1,1)){
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		setRectangle();
		shader = BasicPositionTextureShader::getInstance();
	}
	void setPosition(Vector3 val){
		this->position = val;
	}
	void setRotation(Vector3 val){
		this->rotation = val;
	}
	void setScale(float val){
		this->scale = Vector3(val,val,1);
	}
	void setTexture(Texture val){
		this->texture = val;
	}
	Vector3 getPosition(){
		return position;
	}
	Vector3 getRotation(){
		return rotation;
	}
	float getScale(){
		return scale.x;
	}
	void Draw(){
		update();
		shader.bind();
		shader.updateUniforms(transform.getTransformation(),transform.getProjectedTransformation());
		texture.bind();
		mesh.draw();
	}
};
#endif