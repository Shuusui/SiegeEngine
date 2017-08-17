#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <cstdint>
#include "MakroDefines.h"
#include "Vector2.h"
#include <cmath>

namespace SEngine
{
	class Vector3
	{
	public: 

		//Constructor types
		Vector3(); //Set everything default 0 
		explicit Vector3(float x, float y, float z);
		explicit Vector3(int8 x, int8 y, int8 z);
		explicit Vector3(int16 x, int16 y, int16 z); 
		explicit Vector3(int32 x, int32 y, int32 z); 
		Vector3(const Vector3& vec0);

		//Getter functions
		__forceinline float GetX() const; 
		__forceinline float GetY() const; 
		__forceinline float GetZ() const; 
								   
		//Setter functions
		__forceinline void SetX(float x); 
		__forceinline void SetY(float y); 
		__forceinline void SetZ(float z); 
		__forceinline void SetX(int8 x);
		__forceinline void SetY(int8 y);
		__forceinline void SetZ(int8 z);
		__forceinline void SetX(int16 x); 
		__forceinline void SetY(int16 y); 
		__forceinline void SetZ(int16 z); 
		__forceinline void SetX(int32 x); 
		__forceinline void SetY(int32 y); 
		__forceinline void SetZ(int32 z); 
		__forceinline void SetVector(Vector3& vec0);

	  //normal functions
		__forceinline float Length();
		__forceinline void Normalize();

		//static functions
		__forceinline static Vector3 CrossProduct(const Vector3& vec0, const Vector3& vec1);
		__forceinline static float DotProduct(const Vector3& vec0, const Vector3& vec1);
		

		//operator overloading 
		//with other vectors
		__forceinline Vector3 operator*(const Vector3& vec0) const;
		__forceinline Vector3 operator+(const Vector3& vec0) const; 
		__forceinline Vector3 operator-(const Vector3& vec0) const; 
		__forceinline Vector3 operator/(const Vector3& vec0) const; 
		__forceinline void operator*=(const Vector3& vec0);
		__forceinline void operator/=(const Vector3& vec0); 
		__forceinline void operator+=(const Vector3& vec0); 
		__forceinline void operator=(const Vector3& vec0);
		__forceinline bool operator==(const Vector3& vec0)const; 
		__forceinline bool operator!=(const Vector3& vec0)const;
		//with scalar
		__forceinline Vector3 operator*(const float& scal) const; 
		__forceinline Vector3 operator+(const float& scal) const; 
		__forceinline Vector3 operator-(const float& scal) const; 
		__forceinline Vector3 operator/(const float& scal) const; 
		__forceinline void operator-=(const Vector3& vec0); 
		__forceinline void operator/=(const float& scal); 
		__forceinline void operator*=(const float& scal); 
		__forceinline void operator+=(const float& scal); 
		__forceinline void operator-=(const float& scal); 



		//Destructor
		~Vector3(); 


	private: 
		//private variables
		float X; 
		float Y; 
		float Z; 



	};
}

#include "Vector3.hpp"
#endif //_VECTOR3_H_