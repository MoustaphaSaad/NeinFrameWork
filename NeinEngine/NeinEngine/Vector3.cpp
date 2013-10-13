#include"Vector3.h"
#include<math.h>
#include"MathAssists.h"
#include"Quaternion.h"
const Vector3 Vector3::UP(0,1,0);
const Vector3 Vector3::DOWN(0,-1,0);
const Vector3 Vector3::LEFT(-1,0,0);
const Vector3 Vector3::RIGHT(1,0,0);
const Vector3 Vector3::FORWARD(0,0,1);
const Vector3 Vector3::BACK(0,0,1);
const Vector3 Vector3::ONE(1,1,1);
const Vector3 Vector3::ZERO(0,0,0);

Vector3::Vector3(float x,float y,float z){
	this->x=x;
	this->y=y;
	this->z=z;
}

float Vector3::length() const{
	return sqrtf(x*x+y*y+z*z);
}

float Vector3::dot(const Vector3& v) const{
	return x*v.x + y*v.y + z*v.z;
}
Vector3 Vector3::cross(const Vector3& v) const{
	const float _x=y*v.z - z*v.y;
	const float _y=z*v.x - x*v.z;
	const float _z=x*v.y - y*v.x;

	return Vector3(_x,_y,_z);
}
Vector3& Vector3::normalize(){
	const float vectorLength= length();
	x/=vectorLength;
	y/=vectorLength;
	z/=vectorLength;
	return *this;
}

Vector3 Vector3::rotate(float angle,const Vector3& axis) const{
	const float sinHalfAngle = sinf(ToRadian(angle/2));
	const float cosHalfAngle = cosf(ToRadian(angle/2));

	const float Rx = axis.x * sinHalfAngle;
	const float Ry = axis.y * sinHalfAngle;
	const float Rz = axis.z * sinHalfAngle;
	const float Rw = cosHalfAngle;

	Quaternion rotationQ(Rx,Ry,Rz,Rw);

	Quaternion conjugateQ = rotationQ.conjugate();
	Quaternion w = rotationQ *(*this) * conjugateQ;

	Vector3 ret(w.x,w.y,w.z);

	return ret;
}


Vector3& Vector3::operator+=(const Vector3& r)
{
    x += r.x;
    y += r.y;
    z += r.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& r)
{
    x -= r.x;
    y -= r.y;
    z -= r.z;

    return *this;
}

Vector3& Vector3::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

Vector3& Vector3::operator/=(float f)
{
    x /= f;
    y /= f;
    z /= f;

    return *this;
}

Vector3 Vector3::operator+(const Vector3& r) const 
{
	Vector3 ret(x + r.x,
				 y + r.y,
				 z + r.z);

	return ret;
}

Vector3 Vector3::operator-(const Vector3& r) const 
{
	Vector3 ret(x - r.x,
				 y - r.y,
				 z - r.z);
	return ret;
}

Vector3 Vector3::operator*(float f) const
{
	Vector3 ret(x * f,
				 y * f,
				 z * f);
	return ret;
}

Vector3 Vector3::operator/(float f) const 
{
	Vector3 ret(x / f,
				 y / f,
				 z / f);
	return ret;
}

inline bool Vector3::operator==(const Vector3& r) const
{
	return x == r.x && y == r.y && z == r.z;
}

inline bool Vector3::operator!=(const Vector3& r) const
{
	return !operator==(r);
}