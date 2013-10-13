#ifndef QUATERNION
#define QUATERNION
#include"Vector3.h"
class Quaternion{
public:
	float x,y,z,w;

	Quaternion(float _x,float _y,float _z,float _w);
	Quaternion();
	void normalize();
	Quaternion conjugate();

	Quaternion operator*(const Quaternion& r);
	Quaternion operator*(const Vector3& v);
};
#endif