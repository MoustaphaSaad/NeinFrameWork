#ifndef VECTOR3
#define VECTOR3
class Vector3{
public:
	static const Vector3 UP;
	static const Vector3 DOWN;
	static const Vector3 LEFT;
	static const Vector3 RIGHT;
	static const Vector3 FORWARD;
	static const Vector3 BACK;
	static const Vector3 ONE;
	static const Vector3 ZERO;

	float x,y,z;
	Vector3(float x=0.0f,float y=0.0f,float z=0.0f);

	float length() const;
	float dot(const Vector3& v) const;

	Vector3 cross(const Vector3& v) const;
	Vector3 rotate(float angle,const Vector3& axis)const;

	Vector3& normalize();

	Vector3& operator+=(const Vector3& r);
	Vector3& operator-=(const Vector3& r);
	Vector3& operator*=(float f);
	Vector3& operator/=(float f);

	Vector3 operator+(const Vector3& r)const;
	Vector3 operator-(const Vector3& r)const;
	Vector3 operator*(float f)const;
	Vector3 operator/(float f)const;

	inline bool operator==(const Vector3& r)const;
	inline bool operator!=(const Vector3& r)const;
};
#endif