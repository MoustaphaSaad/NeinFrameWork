#include"Camera.h"
#include"input.h"
#include"gameTime.h"

Camera::Camera(Vector3 pos,Vector3 forward,Vector3 up){
	m_position = pos;
	m_forward = forward;
	m_up = up;
	rot=Vector3(0,0,0);
}
Camera::~Camera(){
}
#include"Window.h"
bool mouseLocked=false;

void Camera::input(){
	float sensitivity = 0.5f;
	float movAmt= (float)(50*gameTime::getDelta());
	float rotAmt=(float)(100* gameTime::getDelta());

	if(Input::getKeyDown(KEY::KEY_ESCAPE)){
		Input::setCursor(true);
		mouseLocked=false;
	}
	if(mouseLocked){
		Vector2 centerPosition = Vector2((float)Window::getWidth()/2.0f,(float)Window::getHeight()/2.0f);
		Vector2 deltaPos = Input::getMousePosition()-centerPosition;

		bool rotY = deltaPos.x !=0;
		bool rotX = deltaPos.y !=0;



		if(rotY)
			rotateY(deltaPos.x*sensitivity);
		if(rotX)
			rotateX(deltaPos.y*sensitivity);

		if(rotY||rotX)
			Input::setMousePosition(centerPosition);

	}
	if(Input::getMouseDown(MOUSE::LEFT_MOUSE)){
		Vector2 centerPosition = Vector2((float)Window::getWidth()/2.0f,(float)Window::getHeight()/2.0f);
		Input::setMousePosition(centerPosition);
		Input::setCursor(false);
		mouseLocked=true;
	}
	if(Input::getKeyDown(KEY::KEY_W))
		move(getForward(),movAmt);
	if(Input::getKeyDown(KEY::KEY_S))
		move(getForward(),-movAmt);
	if(Input::getKeyDown(KEY::KEY_A))
		move(getLeft(),-movAmt);
	if(Input::getKeyDown(KEY::KEY_D))
		move(getRight(),-movAmt);
}
void Camera::move(const Vector3& dir,float amt){
	m_position +=(dir*amt);
}
void Camera::rotateY(float angle){
	rot.y+=angle;
	Vector3 hAxis=Vector3::UP.cross(m_forward).normalize();
	m_forward = m_forward.rotate(angle,Vector3::UP).normalize();
	m_up = m_forward.cross(hAxis).normalize();
}
void Camera::rotateX(float angle){
	rot.x+=angle;
	Vector3 hAxis=Vector3::UP.cross(m_forward).normalize();
	m_forward = m_forward.rotate(angle,hAxis).normalize();
	m_up = m_forward.cross(hAxis).normalize();
}

Vector3 Camera::getPosition(){
	return m_position;
}
Vector3 Camera::getForward(){
	return m_forward;
}
Vector3 Camera::getUp(){
	return m_up;
}
void Camera::rotate(Vector3 amt){
	rotateX(amt.x);
	rotateY(amt.y);
}
void Camera::setPosition(const Vector3& val){
	m_position= val;
}
void Camera::setForward(const Vector3& val){
	m_forward= val;
}
void Camera::setUp(const Vector3& val){
	m_up= val;
}
Vector3 Camera::getLeft(){
	return m_forward.cross(m_up).normalize();
}
Vector3 Camera::getRight(){
	return m_up.cross(m_forward).normalize();
}

