#ifndef SKYBOXH
#define SKYBOXH
#include"Texture.h"
#include"Transform.h"
#include"Vector3.h"
#include"Mesh.h"
#include"Vertex.h"
class Skybox{
	Vector3 position,scale,rotation;
	Transform transform;
	Texture texture[6];
	Mesh<PositionTextureVertex> mesh[6];
	BasicPositionTextureShader shader;
	void setMesh(){
		int Cont=1;
		PositionTextureVertex data[]={
			PositionTextureVertex(Vector3(-1,-1,Cont),Vector2(1,1)),
			PositionTextureVertex(Vector3(-1,1,Cont),Vector2(1,0)),
			PositionTextureVertex(Vector3(1,1,Cont),Vector2(0,0)),
			PositionTextureVertex(Vector3(1,-1,Cont),Vector2(0,1))
		};
		int idx[]={0,1,2,2,3,0};
		mesh[0].addVertices(data,ARRAY_SIZE(data),idx,ARRAY_SIZE(idx),false);

		PositionTextureVertex data2[]={
			PositionTextureVertex(Vector3(-1,-1,-Cont),Vector2(1,1)),
			PositionTextureVertex(Vector3(-1,1,-Cont),Vector2(1,0)),
			PositionTextureVertex(Vector3(1,1,-Cont),Vector2(0,0)),
			PositionTextureVertex(Vector3(1,-1,-Cont),Vector2(0,1))
		};
		int idx2[]={0,1,2,2,3,0};
		mesh[1].addVertices(data2,ARRAY_SIZE(data2),idx2,ARRAY_SIZE(idx2),false);


		PositionTextureVertex data3[]={
			PositionTextureVertex(Vector3(-Cont,-1,-1),Vector2(1,1)),
			PositionTextureVertex(Vector3(-Cont,1,-1),Vector2(1,0)),
			PositionTextureVertex(Vector3(-Cont,1,1),Vector2(0,0)),
			PositionTextureVertex(Vector3(-Cont,-1,1),Vector2(0,1))
		};
		int idx3[]={0,1,2,2,3,0};
		mesh[2].addVertices(data3,ARRAY_SIZE(data3),idx3,ARRAY_SIZE(idx3),false);

		PositionTextureVertex data4[]={
			PositionTextureVertex(Vector3(1,Cont,-1),Vector2(1,1)),
			PositionTextureVertex(Vector3(1,Cont,1),Vector2(1,0)),
			PositionTextureVertex(Vector3(-1,Cont,1),Vector2(0,0)),
			PositionTextureVertex(Vector3(-1,Cont,-1),Vector2(0,1))
		};
		int idx4[]={0,1,2,2,3,0};
		mesh[3].addVertices(data4,ARRAY_SIZE(data4),idx4,ARRAY_SIZE(idx4),false);

		PositionTextureVertex data5[]={
			PositionTextureVertex(Vector3(1,-Cont,-1),Vector2(1,1)),
			PositionTextureVertex(Vector3(1,-Cont,1),Vector2(1,0)),
			PositionTextureVertex(Vector3(-1,-Cont,1),Vector2(0,0)),
			PositionTextureVertex(Vector3(-1,-Cont,-1),Vector2(0,1))
		};
		int idx5[]={0,1,2,2,3,0};
		mesh[4].addVertices(data5,ARRAY_SIZE(data5),idx5,ARRAY_SIZE(idx5),false);

		PositionTextureVertex data6[]={
			PositionTextureVertex(Vector3(Cont,-1,-1),Vector2(1,1)),
			PositionTextureVertex(Vector3(Cont,1,-1),Vector2(1,0)),
			PositionTextureVertex(Vector3(Cont,1,1),Vector2(0,0)),
			PositionTextureVertex(Vector3(Cont,-1,1),Vector2(0,1))
		};
		int idx6[]={0,1,2,2,3,0};
		mesh[5].addVertices(data6,ARRAY_SIZE(data6),idx6,ARRAY_SIZE(idx6),false);
	}
	void update(Vector3 pos){
		position = pos;
		scale.x=100;
		scale.z=100;
		scale.y=100;
		transform.setPosition(position);
		transform.setRotation(rotation);
		transform.setScale(scale);
	}
public:
	Skybox(Texture top,Texture bottom,Texture front,Texture back,Texture right,Texture left){
		texture[0] = top;
		texture[1] = bottom;
		texture[2] = front;
		texture[3] = back;
		texture[4] = right;
		texture[5] = left;
		setMesh();
		shader=BasicPositionTextureShader::getInstance();
		position=Vector3(0,0,0);
		rotation=Vector3(0,0,0);
		scale=Vector3(1,1,1);
	}

	void Render(Vector3 pos){
		glDisable(GL_CULL_FACE);
		update(pos);
		shader.bind();
		shader.updateUniforms(transform.getTransformation(),transform.getProjectedTransformation());
		texture[2].bind();
		mesh[0].draw();
		texture[3].bind();
		mesh[1].draw();
		texture[4].bind();
		mesh[2].draw();
		texture[0].bind();
		mesh[3].draw();
		texture[1].bind();
		mesh[4].draw();
		texture[5].bind();
		mesh[5].draw();
		glEnable(GL_CULL_FACE);
	}
};

#endif