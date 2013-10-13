#ifndef IVERTEXH
#define IVERTEXH
#include"Vertex.h"
class VertexDefinition{
public :
	VertexDefinition(){

	}
	void (*enableVertexAttribArray)();
	void (*disableVertexAttribArray)();
	void (*vertexAttribPointer)();
};
class IVertex{
public:
	static VertexDefinition Definition;

};
VertexDefinition IVertex::Definition = VertexDefinition();
#endif