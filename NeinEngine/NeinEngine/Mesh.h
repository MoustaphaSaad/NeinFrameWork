#ifndef MESHV
#define MESHV

#include "Vertex.h"
#include<memory>
#include<GL\glew.h>

template<class T>
class Mesh{
public :
	Mesh(){
		glGenBuffers(1,&m_vbo);
		glGenBuffers(1,&m_ibo);
		m_size=0;
	}
	~Mesh(){
		glDeleteBuffers(1,&m_vbo);
		glDeleteBuffers(1,&m_ibo);
	}

	void addVertices(T* vertices, int vertSize,int* indices,int indexSize,bool CN){

		m_size = indexSize;

		if(CN)
			this->calcNormals(vertices,vertSize,indices,indexSize);

		glBindBuffer(GL_ARRAY_BUFFER,m_vbo);
		glBufferData(GL_ARRAY_BUFFER,vertSize*T::SIZE,vertices,GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * sizeof(int), indices, GL_STATIC_DRAW);
	}
	void draw(){
		/*glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);*/
		T::Definition.enableVertexAttribArray();

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		T::Definition.vertexAttribPointer();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

		T::Definition.disableVertexAttribArray();
		/*glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);*/
	}
private:
	void calcNormals(T* vertices,int vertSize,int* indices, int indexSize){
		for(int i=0;i<indexSize;i+=3){
			int i0=indices[i];
			int i1=indices[i+1];
			int i2=indices[i+2];

			Vector3 v1 = vertices[i1].position - vertices[i0].position;
			Vector3 v2 = vertices[i2].position - vertices[i0].position;

			Vector3 normal = v1.cross(v2).normalize();

			vertices[i0].normal += normal;
			vertices[i1].normal += normal;
			vertices[i2].normal += normal;

		}
		for(int i = 0; i < vertSize; i++)
			vertices[i].normal.normalize();
	}

	unsigned int m_vbo;
	unsigned int m_ibo;
	int m_size;
};
#endif