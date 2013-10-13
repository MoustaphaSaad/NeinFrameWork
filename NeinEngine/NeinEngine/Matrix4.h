#ifndef MATRIX4
#define MATRIX4
#include"Vector3.h"
class Matrix4 
{
public:
	void initIdentity();
	void initScaleTransform(float scaleX, float scaleY, float scaleZ);
    void initRotateTransform(float rotateX, float rotateY, float rotateZ);
    void initTranslationTransform(float x, float y, float z);
    void initCameraTransform(const Vector3& target, const Vector3& up);
    void initPersProjTransform(float fov, float width, float height, float zNear, float zFar);

	inline Matrix4 operator*(const Matrix4& right) const;
	const float* operator[](int index) const;
	float* operator[](int index);

	void print();
protected:
private:
	float m[4][4];
	
};
#endif