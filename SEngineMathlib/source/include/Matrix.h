#ifndef _MATRIX_H_
#define _MATRIX_H_
///internal includes
#pragma region Internal includes
#include "Vector3.h"
#include "Vector4.h"
#pragma endregion 
///external includes
#pragma region External includes
#include <cstdint>
#include <fstream>
#pragma endregion

///
///
///Matrix class which will handle all 4x4 matrices you will put in 
///
///

namespace SEngine
{

	class Matrix
	{
	public:
		///
		///Constructors 
		///
		Matrix();
		explicit Matrix(float scal1, float scal2, float scal3, float scal4, float scal5, float scal6, float scal7, float scal8, float scal9, float scal10, float scal11, float scal12, float scal13, float scal14, float scal15, float scal16);
		explicit Matrix(SEVector4& vec0, SEVector4& vec1, SEVector4& vec2, SEVector4& vec3);
		Matrix(Matrix& mat);
		///
		///static functions
		///
		__forceinline static Matrix Identity(); 
		__forceinline static float Determinante(const Matrix& mat);
		__forceinline static Matrix Inverse(const Matrix& mat);
		///
		///operation functions 
		///
		__forceinline void rotationX(float scal); 
		__forceinline void rotationY(float scal); 
		__forceinline void rotationZ(float scal); 
		__forceinline void translate(SEVector3& vec0);
		__forceinline void scaling(SEVector3& vec0);
		///
		///operator functions
		///
		__forceinline Matrix operator*(const Matrix& mat) const; 
		__forceinline Matrix operator+(const Matrix& mat) const; 
		__forceinline Matrix operator-(const Matrix& mat) const;
		__forceinline Matrix operator*(Vector3& vec3) const; 
		__forceinline Matrix operator*(const Vector4& vec4) const; 
		__forceinline void operator*=(const Matrix& mat);
		__forceinline void operator+=(const Matrix& mat);
		__forceinline void operator-=(const Matrix& mat);
		__forceinline void operator*=(const Vector3& vec3); 
		__forceinline void operator*=(const Vector4& vec4);
		__forceinline float operator[](int8 index) const;
		__forceinline void operator=(const Matrix& mat); 
		__forceinline bool operator==(const Matrix& mat) const; 
		__forceinline bool operator!=(const Matrix& mat) const; 
		///
		///Destructor
		///
		~Matrix();




	private: 
		///Member variables
		float m4x4[16];

	};

}

#include "Matrix.hpp"
#endif 