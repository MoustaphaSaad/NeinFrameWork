#include"Transform.h"
#include"Vector2.h"

Camera* Transform::m_camera = &Camera();
float Transform::m_fov=0;
float Transform::m_zNear=0;
float Transform::m_zFar=0;
float Transform::m_height=0;
float Transform::m_width=0;

Transform::Transform(Vector3 pos,Vector3 rot,Vector3 scale){
	m_position=pos;
	m_rotation=rot;
	m_scale=scale;
}
Transform::~Transform(){
}

Matrix4 Transform::getTransformation(){
	Matrix4 translation,rotation,scale;
	translation.initTranslationTransform(m_position.x,m_position.y,m_position.z);
	rotation.initRotateTransform(m_rotation.x,m_rotation.y,m_rotation.z);
	scale.initScaleTransform(m_scale.x,m_scale.y,m_scale.z);

	return translation*rotation*scale;
}
Matrix4 Transform::getProjectedTransformation(){
	Matrix4 transformationMatrix = getTransformation();
	Matrix4 projection;
	Matrix4 cameraRotation;
	Matrix4 cameraTranslation;

	projection.initPersProjTransform(m_fov,m_width,m_height,m_zNear,m_zFar);
	cameraRotation.initCameraTransform(m_camera->getForward(),m_camera->getUp());
	cameraTranslation.initTranslationTransform(-m_camera->getPosition().x,-m_camera->getPosition().y,-m_camera->getPosition().z);
	
	return projection* cameraRotation*cameraTranslation*transformationMatrix;
}
Vector3 Transform::getPosition(){
	return m_position;
}
Vector3 Transform::getRotation(){
	return m_rotation;
}
Vector3 Transform::getScale(){
	return m_scale;
}
void Transform::setPosition(const Vector3& val){
	m_position = val;
}
void Transform::setRotation(const Vector3& val){
	m_rotation = val;
}
void Transform::setScale(const Vector3& val){
	m_scale = val;
}

void Transform::setProjection(float fov, float width, float height, float zNear, float zFar)
{
	Transform::m_fov = fov;
	Transform::m_width = width;
	Transform::m_height = height;
	Transform::m_zNear = zNear;
	Transform::m_zFar = zFar;
}
Camera& Transform::getCamera()
{
	return *m_camera;
}

void Transform::setCamera(Camera& camera)
{
	Transform::m_camera = &camera;
}