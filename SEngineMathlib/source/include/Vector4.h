#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include "Vector3.h"

namespace SEngine
{
	class Vector4
	{
	public: 
		//Constructor
		Vector4(); 
		explicit Vector4(float x, float y, float z, float w); 
		explicit Vector4(int8 x, int8 y, int8 z, int8 w); 
		explicit Vector4(int16 x, int16 y, int16 z, int16 w);
		explicit Vector4(int32 x, int32 y, int32 z, int32 w); 
		Vector4(const Vector4& vec0);
		explicit Vector4(SEVector3& vec0, float w);
		explicit Vector4(SEVector3& vec0, int8 w); 
		explicit Vector4(SEVector3& vec0, int16 w); 
		explicit Vector4(SEVector3& vec0, int32 w);

		//Getter functions
		__forceinline float GetX() const; 
		__forceinline float GetY() const; 
		__forceinline float GetZ() const; 
		__forceinline float GetW() const;

		//Setter functions
		__forceinline void SetX(float x); 
		__forceinline void SetY(float y); 
		__forceinline void SetZ(float z); 
		__forceinline void SetW(float w);
		__forceinline void SetX(int8 x); 
		__forceinline void SetY(int8 y); 
		__forceinline void SetZ(int8 z);
		__forceinline void SetW(int8 w);
		__forceinline void SetX(int16 x); 
		__forceinline void SetY(int16 y); 
		__forceinline void SetZ(int16 z);
		__forceinline void SetW(int16 w);
		__forceinline void SetX(int32 x); 
		__forceinline void SetY(int32 y); 
		__forceinline void SetZ(int32 z);
		__forceinline void SetW(int32 w);
		__forceinline void SetVector3(SEVector3& vec0, const float w);
		__forceinline void SetVector3(SEVector3& vec0, const int8 w);
		__forceinline void SetVector3(SEVector3& vec0, const int16 w);
		__forceinline void SetVector3(SEVector3& vec0, const int32 w);
		__forceinline void SetVector4(Vector4& vec0);

		//operation functions
		__forceinline float Length(); 
		__forceinline void Normalize(); 

		//Static funtions
		__forceinline static float DotProduct(const Vector4& vec0, const Vector4& vec1); 

		//operator overloading 
		//with Vector4
		__forceinline Vector4 operator*(const Vector4& vec0) const; 
		__forceinline Vector4 operator+(const Vector4& vec0) const; 
		__forceinline Vector4 operator-(const Vector4& vec0) const; 
		__forceinline Vector4 operator/(const Vector4& vec0) const; 
		__forceinline void operator*=(const Vector4& vec0); 
		__forceinline void operator+=(const Vector4& vec0); 
		__forceinline void operator-=(const Vector4& vec0); 
		__forceinline void operator/=(const Vector4& vec0);
		__forceinline void operator=(const Vector4& vec0);
		__forceinline bool operator==(const Vector4& vec0) const; 
		__forceinline bool operator!=(const Vector4& vec0) const;
		//with scalar 
		__forceinline Vector4 operator*(const float& scal) const; 
		__forceinline Vector4 operator+(const float& scal) const; 
		__forceinline Vector4 operator-(const float& scal) const; 
		__forceinline Vector4 operator/(const float& scal) const; 
		__forceinline void operator*=(const float& scal); 
		__forceinline void operator+=(const float& scal); 
		__forceinline void operator-=(const float& scal);
		__forceinline void operator/=(const float& scal); 
		//Destructor 
		~Vector4();

	private: 
		//private variables 
		float X; 
		float Y; 
		float Z; 
		float W; 





	};
}
#include "Vector4.hpp"
#endif //_VECTOR4_H_