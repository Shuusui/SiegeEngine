#ifndef _VECTOR2_H_
#error Do not include this file directly! 
#elif !defined _VECTOR2_HPP_
#define _VECTOR2_HPP_

//#include "Vector2.h"



__forceinline float SEngine::Vector2::GetX() const
{
	return Vector2::X;
}
__forceinline float SEngine::Vector2::GetY() const
{
	return Vector2::Y;
}
__forceinline void SEngine::Vector2::SetX(float x)
{
	Vector2::X = x;
}
__forceinline void SEngine::Vector2::SetY(float y)
{
	Vector2::Y = y;
}
__forceinline void SEngine::Vector2::SetX(int8 x)
{
	Vector2::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector2::SetY(int8 y)
{
	Vector2::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector2::SetX(int16 x)
{
	Vector2::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector2::SetY(int16 y)
{
	Vector2::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector2::SetX(int32 x)
{
	Vector2::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector2::SetY(int32 y)
{
	Vector2::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector2::SetVector2(Vector2& vec0)
{
	Vector2::X = vec0.X;
	Vector2::Y = vec0.Y;
}
__forceinline float SEngine::Vector2::Length()
{
	float length = sqrt(pow(Vector2::X, 2) + pow(Vector2::Y, 2));
	return length;
}
__forceinline void SEngine::Vector2::Normalize()
{
	float length = SEngine::Vector2::Length();
	Vector2::X /= length; 
	Vector2::Y /= length;
}
__forceinline float SEngine::Vector2::CrossProduct(const Vector2& vec0, const Vector2& vec1)
{
	float cross = vec0.X*vec1.Y - vec0.Y*vec1.X;
	return cross;
}
__forceinline float SEngine::Vector2::DotProduct(const Vector2& vec0, const Vector2& vec1)
{
	float dot = (vec0.X*vec1.X) + (vec0.Y*vec1.Y);
	return dot;
}
__forceinline SEngine::Vector2 SEngine::Vector2::operator*(const Vector2& vec0) const
{
	SEngine::Vector2 product(SEngine::Vector2::X*vec0.X, SEngine::Vector2::Y*vec0.Y);
	return product;
}
__forceinline SEngine::Vector2 SEngine::Vector2::operator+(const Vector2& vec0) const
{
	SEngine::Vector2 sum(SEngine::Vector2::X + vec0.X, SEngine::Vector2::Y + vec0.Y);
	return sum;
}
__forceinline SEngine::Vector2 SEngine::Vector2::operator-(const Vector2& vec0) const
{
	SEngine::Vector2 difference(Vector2::X - vec0.X, Vector2::Y - vec0.Y);
	return difference;
}
__forceinline SEngine::Vector2 SEngine::Vector2::operator/(const Vector2& vec0) const
{
	SEngine::Vector2 quotient(Vector2::X / vec0.X, Vector2::Y / vec0.Y); 
	return quotient;
}
__forceinline void SEngine::Vector2::operator*=(const Vector2& vec0)
{
	Vector2::X *= vec0.X; 
	Vector2::Y *= vec0.Y; 
}
__forceinline void SEngine::Vector2::operator+=(const Vector2& vec0)
{
	Vector2::X += vec0.X;
	Vector2::Y += vec0.Y;
}
__forceinline void SEngine::Vector2::operator-=(const Vector2& vec0)
{
	Vector2::X -= vec0.X;
	Vector2::Y -= vec0.Y;
}
__forceinline void SEngine::Vector2::operator/=(const Vector2& vec0)
{
	Vector2::X /= vec0.X;
	Vector2::Y /= vec0.Y;
}
__forceinline void SEngine::Vector2::operator=(const Vector2& vec0)
{
	Vector2::X = vec0.X; 
	Vector2::Y = vec0.Y; 
}
__forceinline bool SEngine::Vector2::operator==(const Vector2& vec0) const
{
	if (Vector2::X == vec0.X && Vector2::Y == vec0.Y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
__forceinline bool SEngine::Vector2::operator!=(const Vector2& vec0)const 
{
	if (Vector2::X != vec0.X && Vector2::Y != vec0.Y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

#endif