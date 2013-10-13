#include"Vector2.h"

Vector2& Vector2::operator+=(const Vector2& r){
	x+=r.x;
	y+=r.y;
	return *this;
}
Vector2& Vector2::operator-=(const Vector2& r){
	x-=r.x;
	y-=r.y;
	return *this;
}
Vector2& Vector2::operator*=(const Vector2& r){
	x*=r.x;
	y*=r.y;
	return *this;
}
Vector2& Vector2::operator/=(const Vector2& r){
	x/=r.x;
	y/=r.y;
	return *this;
}
Vector2 Vector2::operator+(const Vector2&r)const{
	Vector2 ret(x+r.x,y+r.y);
	return ret;
}
Vector2 Vector2::operator-(const Vector2&r)const{
	Vector2 ret(x-r.x,y-r.y);
	return ret;
}
Vector2 Vector2::operator*(float f)const{
	Vector2 ret(x*f,y*f);
	return ret;
}
Vector2 Vector2::operator/(float f)const{
	Vector2 ret(x/f,y/f);
	return ret;
}
inline bool Vector2::operator==(const Vector2& r)const{
	return x==r.x && y==r.y;
}
inline bool Vector2::operator!=(const Vector2& r)const{
	return !operator==(r);
}