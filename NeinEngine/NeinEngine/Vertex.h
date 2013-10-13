#ifndef POSITIONVERTEX
#define POSITIONVERTEX
#include"Vector3.h"
#include"Vector2.h"
#include"IVertex.h"
#include<GL\glew.h>
class PositionVertex{
public:
	Vector3 position;
	static const int SIZE = sizeof(Vector3);
	static VertexDefinition Definition;
	PositionVertex(Vector3 pos=Vector3(0,0,0)){
		this->position = pos;

		Definition.disableVertexAttribArray = &disableVertexAttribArrayX;
		Definition.enableVertexAttribArray = &enableVertexAttribArrayX;
		Definition.vertexAttribPointer = &vertexAttribPointerX;
	}

	static void enableVertexAttribArrayX(){
		glEnableVertexAttribArray(0);
	}
	static void disableVertexAttribArrayX(){
		glDisableVertexAttribArray(0);
	}
	static void vertexAttribPointerX(){
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,SIZE,0);
	}
};
VertexDefinition PositionVertex::Definition = VertexDefinition();
class PositionColorVertex{

public:
	Vector3 position;
	Vector3 color;
	static const int SIZE = sizeof(Vector3)+sizeof(Vector3);
	static VertexDefinition Definition;
	PositionColorVertex(Vector3 pos=Vector3(0,0,0),Vector3 col = Vector3(0,0,0)){
		this->position = pos;
		this->color = col;

		Definition.disableVertexAttribArray = &disableVertexAttribArrayX;
		Definition.enableVertexAttribArray = &enableVertexAttribArrayX;
		Definition.vertexAttribPointer = &vertexAttribPointerX;
	}
	static void enableVertexAttribArrayX(){
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	}
	static void disableVertexAttribArrayX(){
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
	static void vertexAttribPointerX(){
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,SIZE, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, SIZE,(GLvoid*)(12));
	}
};
VertexDefinition PositionColorVertex::Definition = VertexDefinition();
class PositionTextureVertex {
public:
	Vector3 position;
	Vector2 texCoord;
	static const int SIZE = sizeof(Vector3)+sizeof(Vector2);
	static VertexDefinition Definition;
	PositionTextureVertex(Vector3 pos = Vector3(0,0,0),Vector2 tex = Vector2(0,0),Vector3 normal = Vector3(0,0,0))
	{
		this->position = pos;
		this->texCoord = tex;

		Definition.disableVertexAttribArray = &disableVertexAttribArrayX;
		Definition.enableVertexAttribArray = &enableVertexAttribArrayX;
		Definition.vertexAttribPointer = &vertexAttribPointerX;
	}

	static void enableVertexAttribArrayX(){
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

	}
	static void disableVertexAttribArrayX(){
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

	}
	static void vertexAttribPointerX(){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, SIZE,0);
		glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,SIZE,(GLvoid*)12);

	}
};
VertexDefinition PositionTextureVertex::Definition = VertexDefinition();
#endif
