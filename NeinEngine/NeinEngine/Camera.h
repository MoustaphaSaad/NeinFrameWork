#ifndef CAMERAH
#define CAMERAH
#include"Vector3.h"

class Camera{
public :
	Camera(Vector3 pos = Vector3(0,0,0),Vector3 forward=Vector3(0,0,1),Vector3 up = Vector3(0,1,0));
	~Camera();

	void input();
	void move(const Vector3& dir,float amt);
	void rotateY(float angle);
	void rotateX(float angle);

	Vector3 getPosition();
	Vector3 getForward();
	Vector3 getUp();

	Vector3 getLeft();
	Vector3 getRight();

	void setPosition(const Vector3& pos);
	void setForward(const Vector3& forward);
	void setUp(const Vector3& up);
private:
	Vector3 m_position,m_forward,m_up;
};
#endif