#ifndef _VECTOR4_H_
#error Do not include this file directly! 
#elif !defined _VECTOR4_HPP_
#define _VECTOR4_HPP_

//#include "Vector4.h"



__forceinline float SEngine::Vector4::GetX() const
{											 
	return Vector4::X;						 
}											 
__forceinline float SEngine::Vector4::GetY() const
{											 
	return Vector4::Y;						 
}											 
__forceinline float SEngine::Vector4::GetZ() const
{											 
	return Vector4::Z;						 
}											 
__forceinline float SEngine::Vector4::GetW() const
{
	return Vector4::W;
}

__forceinline void SEngine::Vector4::SetX(float x)
{
	Vector4::X = x;
}
__forceinline void SEngine::Vector4::SetY(float y)
{
	Vector4::Y = y;
}
__forceinline void SEngine::Vector4::SetZ(float z)
{
	Vector4::Z = z; 
}
__forceinline void SEngine::Vector4::SetW(float w)
{
	Vector4::W = w; 
}
__forceinline void SEngine::Vector4::SetX(int8 x)
{
	Vector4::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector4::SetY(int8 y)
{
	Vector4::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector4::SetZ(int8 z)
{
	Vector4::Z = static_cast<float>(z);
}
__forceinline void SEngine::Vector4::SetW(int8 w)
{
	Vector4::W = static_cast<float>(w);
}
__forceinline void SEngine::Vector4::SetX(int16 x)
{
	Vector4::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector4::SetY(int16 y)
{
	Vector4::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector4::SetZ(int16 z)
{
	Vector4::Z = static_cast<float>(z);
}
__forceinline void SEngine::Vector4::SetW(int16 w)
{
	Vector4::W = static_cast<float>(w);
}
__forceinline void SEngine::Vector4::SetX(int32 x)
{
	Vector4::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector4::SetY(int32 y)
{
	Vector4::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector4::SetZ(int32 z)
{
	Vector4::Z = static_cast<float>(z);
}
__forceinline void SEngine::Vector4::SetW(int32 w)
{
	Vector4::W = static_cast<float>(w);
}
__forceinline void SEngine::Vector4::SetVector3(SEVector3& vec0, const float w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY(); 
	Vector4::Z = vec0.GetZ(); 
	Vector4::W = w;
}
__forceinline void SEngine::Vector4::SetVector3(SEVector3& vec0, const int8 w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY(); 
	Vector4::Z = vec0.GetZ(); 
	Vector4::W = w; 
}
__forceinline void SEngine::Vector4::SetVector3(SEVector3& vec0, const int16 w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY();
	Vector4::Z = vec0.GetZ();
	Vector4::W = w;
}
__forceinline void SEngine::Vector4::SetVector3(SEVector3& vec0, const int32 w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY();
	Vector4::Z = vec0.GetZ();
	Vector4::W = w;
}
__forceinline void SEngine::Vector4::SetVector4(SEngine::Vector4& vec0)
{
	Vector4::X = vec0.GetX(); 
	Vector4::Y = vec0.GetY(); 
	Vector4::Z = vec0.GetZ(); 
	Vector4::W = vec0.GetW(); 
}
__forceinline float SEngine::Vector4::Length()
{
	float length = sqrt(pow(Vector4::X, 2) + pow(Vector4::Y, 2) + pow(Vector4::Z, 2) + pow(Vector4::W, 2));
	return length; 
}
__forceinline void SEngine::Vector4::Normalize()
{
	float length = SEngine::Vector4::Length(); 
	Vector4::X /= length; 
	Vector4::Y /= length; 
	Vector4::Z /= length; 
	Vector4::W /= length; 
}
__forceinline float SEngine::Vector4::DotProduct(const SEngine::Vector4& vec0, const SEngine::Vector4& vec1)
{
	float dot = vec0.X + vec1.X + vec0.Y + vec1.Y + vec0.Z*vec1.Z + vec0.W*vec1.W;
	return dot;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator*(const SEngine::Vector4& vec0) const
{
	SEngine::Vector4 product(SEngine::Vector4::X * vec0.X, SEngine::Vector4::Y * vec0.Y, SEngine::Vector4::Z * vec0.Z, SEngine::Vector4::W * vec0.W);
	return product;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator+(const SEngine::Vector4& vec0) const
{
	SEngine::Vector4 sum(SEngine::Vector4::X + vec0.X, SEngine::Vector4::Y + vec0.Y, SEngine::Vector4::Z + vec0.Z, SEngine::Vector4::W + vec0.W);
	return sum;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator-(const SEngine::Vector4& vec0) const
{
	SEngine::Vector4 difference(SEngine::Vector4::X - vec0.X, SEngine::Vector4::Y - vec0.Y, SEngine::Vector4::Z - vec0.Z, SEngine::Vector4::W - vec0.W);
	return difference;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator/(const SEngine::Vector4& vec0) const
{
	SEngine::Vector4 quotient(SEngine::Vector4::X / vec0.X, SEngine::Vector4::Y / vec0.Y, SEngine::Vector4::Z / vec0.Z, SEngine::Vector4::W / vec0.W);
	return quotient;
}
__forceinline void SEngine::Vector4::operator*=(const SEngine::Vector4& vec0)
{
	Vector4::X *= vec0.X;
	Vector4::Y *= vec0.Y;
	Vector4::Z *= vec0.Z;
	Vector4::W *= vec0.W;
	
}
__forceinline void SEngine::Vector4::operator+=(const SEngine::Vector4& vec0)
{
	Vector4::X += vec0.X;
	Vector4::Y += vec0.Y;
	Vector4::Z += vec0.Z;
	Vector4::W += vec0.W;
}
__forceinline void SEngine::Vector4::operator-=(const SEngine::Vector4& vec0)
{
	Vector4::X -= vec0.X;
	Vector4::Y -= vec0.Y;
	Vector4::Z -= vec0.Z;
	Vector4::W -= vec0.W;
}
__forceinline void SEngine::Vector4::operator/=(const SEngine::Vector4& vec0)
{
	Vector4::X /= vec0.X;
	Vector4::Y /= vec0.Y;
	Vector4::Z /= vec0.Z;
	Vector4::W /= vec0.W;
}
__forceinline void SEngine::Vector4::operator=(const SEngine::Vector4& vec0)
{
	Vector4::X = vec0.X;
	Vector4::Y = vec0.Y;
	Vector4::Z = vec0.Z;
	Vector4::W = vec0.W;
}
__forceinline bool SEngine::Vector4::operator==(const SEngine::Vector4& vec0) const
{
	if (Vector4::X == vec0.X && Vector4::Y == vec0.Y && Vector4::Z == vec0.Z && Vector4::W == vec0.W)
	{
		return 1;
	}
	else
	{
		return 0; 
	}
}
__forceinline bool SEngine::Vector4::operator!=(const SEngine::Vector4& vec0) const
{
	if (Vector4::X == vec0.X && Vector4::Y == vec0.Y && Vector4::Z == vec0.Z && Vector4::W == vec0.W)
	{
		return 0;
	}
	else
	{
		return 1; 
	}
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator*(const float& scal) const
{
	Vector4 product(SEngine::Vector4::X*scal, SEngine::Vector4::Y*scal, SEngine::Vector4::Z*scal, SEngine::Vector4::W*scal);
	return product;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator+(const float& scal) const
{
	Vector4 sum(SEngine::Vector4::X + scal, SEngine::Vector4::Y + scal, SEngine::Vector4::Z + scal, SEngine::Vector4::W + scal);
	return sum;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator-(const float& scal) const
{
	Vector4 difference(SEngine::Vector4::X - scal, SEngine::Vector4::Y - scal, SEngine::Vector4::Z - scal, SEngine::Vector4::W - scal);
	return difference;
}
__forceinline SEngine::Vector4 SEngine::Vector4::operator/(const float& scal) const
{
	Vector4 quotient(SEngine::Vector4::X / scal, SEngine::Vector4::Y / scal, SEngine::Vector4::Z / scal, SEngine::Vector4::W / scal);
	return quotient;
}
__forceinline void SEngine::Vector4::operator*=(const float& scal) 
{
	SEngine::Vector4::X *= scal;
	SEngine::Vector4::Y *= scal;
	SEngine::Vector4::Z *= scal;
	SEngine::Vector4::W *= scal;
}
__forceinline void SEngine::Vector4::operator+=(const float& scal) 
{
	SEngine::Vector4::X += scal;
	SEngine::Vector4::Y += scal;
	SEngine::Vector4::Z += scal;
	SEngine::Vector4::W += scal;
}
__forceinline void SEngine::Vector4::operator-=(const float& scal)
{
	SEngine::Vector4::X -= scal;
	SEngine::Vector4::Y -= scal;
	SEngine::Vector4::Z -= scal;
	SEngine::Vector4::W -= scal;
}
__forceinline void SEngine::Vector4::operator/=(const float& scal)
{
	SEngine::Vector4::X /= scal; 
	SEngine::Vector4::Y /= scal; 
	SEngine::Vector4::Z /= scal; 
	SEngine::Vector4::W /= scal; 
}



#endif //_VECTOR4_HPP_