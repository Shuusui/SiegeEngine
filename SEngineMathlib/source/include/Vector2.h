#ifndef _VECTOR2_H_
#define _VECTOR2_H_
#include "MakroDefines.h"
#include <cmath>

namespace SEngine
{
	class Vector2
	{
	public:
		//Constructor
		Vector2(); 
		explicit Vector2(float x, float y); 
		explicit Vector2(int8 x, int8 y); 
		explicit Vector2(int16 x, int16 y); 
		explicit Vector2(int32 x, int32 y); 
		Vector2(const Vector2& vec0); 
		//Getter functions
		__forceinline float GetX() const; 
		__forceinline float GetY() const; 

		//Setter functions
		__forceinline void SetX(float x); 
		__forceinline void SetY(float y); 
		__forceinline void SetX(int8 x); 
		__forceinline void SetY(int8 y); 
		__forceinline void SetX(int16 x); 
		__forceinline void SetY(int16 y); 
		__forceinline void SetX(int32 x); 
		__forceinline void SetY(int32 y);
		__forceinline void SetVector2(Vector2& vec0); 

		//operation functions
		__forceinline float Length(); 
		__forceinline void Normalize(); 

		//Static functions
		__forceinline float CrossProduct(const Vector2& vec0, const Vector2& vec1);
		__forceinline float DotProduct(const Vector2& vec0, const Vector2& vec1); 

		//operator overloading 
		__forceinline Vector2 operator*(const Vector2& vec0) const; 
		__forceinline Vector2 operator+(const Vector2& vec0) const; 
		__forceinline Vector2 operator-(const Vector2& vec0) const; 
		__forceinline Vector2 operator/(const Vector2& vec0) const; 
		__forceinline void operator*=(const Vector2& vec0); 
		__forceinline void operator+=(const Vector2& vec0);
		__forceinline void operator-=(const Vector2& vec0); 
		__forceinline void operator/=(const Vector2& vec0); 
		__forceinline void operator=(const Vector2& vec0);
		__forceinline bool operator==(const Vector2& vec0)const; 
		__forceinline bool operator!=(const Vector2& vec0)const;

		//Destructor 
		~Vector2();
	private: 
		float X; 
		float Y; 
	};
}
#include "Vector2.hpp"
#endif // _VECTOR2_H_