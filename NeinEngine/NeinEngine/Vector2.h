#ifndef VECTOR2
#define VECTOR2
class Vector2{
public:
	float x,y;

	Vector2(float x=0.0f,float y=0.0f){
		this->x=x;
		this->y=y;
	}

	Vector2& operator+=(const Vector2& r);
	Vector2& operator-=(const Vector2& r);
	Vector2& operator*=(const Vector2& r);
	Vector2& operator/=(const Vector2& r);

	Vector2 operator+(const Vector2& r) const;
	Vector2 operator-(const Vector2& r) const;
	Vector2 operator*(float f) const;
	Vector2 operator/(float f) const;

	inline bool operator==(const Vector2&r)const;
	inline bool operator!=(const Vector2&r)const;
};
#endif