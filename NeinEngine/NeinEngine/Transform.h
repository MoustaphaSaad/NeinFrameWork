#ifndef TRANSFORM
#define TRANSFORM

#include"Matrix4.h"
#include"Vector3.h"
#include"Camera.h"

class Transform{
public :
	static Camera& getCamera();
	static void setCamera(Camera& camera);
	static void setProjection(float fov,float width,float height,float zNear,float zFar);

	Transform(Vector3 pos = Vector3(0,0,0), Vector3 rot = Vector3(0,0,0), Vector3 = Vector3(1,1,1));
	~Transform();

	Matrix4 getTransformation();
	Matrix4 getProjectedTransformation();

	Vector3 getPosition();
	Vector3 getRotation();
	Vector3 getScale();

	void setPosition(const Vector3& val);
	void setRotation(const Vector3& val);
	void setScale(const Vector3& val);

private:
	static Camera*m_camera;
	static float m_fov,m_width,m_height,m_zNear,m_zFar;

	Vector3 m_position,m_rotation,m_scale;
};

#endif