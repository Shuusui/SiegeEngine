#ifndef _MATRIX_H_
#error Do not include this file directly! 
#elif !defined _MATRIX_HPP_
#define _MATRIX_HPP_
//function which will return the identity matrix
__forceinline SEngine::Matrix SEngine::Matrix::Identity()
{
	return Matrix(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1); 
}
//function which will return the determinante of the matrix you put in
__forceinline float SEngine::Matrix::Determinante(const SEngine::Matrix& mat)
{
	float det = mat.m4x4[0] * mat.m4x4[5] * mat.m4x4[10] * mat.m4x4[15]
		+ mat.m4x4[1] * mat.m4x4[6] * mat.m4x4[11] * mat.m4x4[12]
		+ mat.m4x4[2] * mat.m4x4[7] * mat.m4x4[8] * mat.m4x4[13]
		+ mat.m4x4[3] * mat.m4x4[4] * mat.m4x4[9] * mat.m4x4[14]
		- mat.m4x4[12] * mat.m4x4[9] * mat.m4x4[6] * mat.m4x4[3]
		- mat.m4x4[13] * mat.m4x4[10] * mat.m4x4[7] * mat.m4x4[0]
		- mat.m4x4[14] * mat.m4x4[11] * mat.m4x4[4] * mat.m4x4[1]
		- mat.m4x4[15] * mat.m4x4[8] * mat.m4x4[5] * mat.m4x4[2];
	return det;
}
//function which will return the inverse of the Matrix you put in if there is an inverse Matrix of it
__forceinline SEngine::Matrix SEngine::Matrix::Inverse(const SEngine::Matrix& mat)
{
	float det = Determinante(mat);
	SEngine:Matrix identity = SEngine::Matrix::Identity();
	if (det != 0) // check if there is an inverse of the Matrix
	{
		SEngine::Vector4 vec0(mat.m4x4[0], mat.m4x4[1], mat.m4x4[2], mat.m4x4[3]); 
		SEngine::Vector4 vec1(mat.m4x4[4], mat.m4x4[5], mat.m4x4[6], mat.m4x4[7]);
		SEngine::Vector4 vec2(mat.m4x4[8], mat.m4x4[9], mat.m4x4[10], mat.m4x4[11]);
		SEngine::Vector4 vec3(mat.m4x4[12], mat.m4x4[13], mat.m4x4[14], mat.m4x4[15]);

		SEngine::Vector4 idenVec0(identity[0], identity[1], identity[2], identity[3]);
		SEngine::Vector4 idenVec1(identity[4], identity[5], identity[6], identity[7]); 
		SEngine::Vector4 idenVec2(identity[8], identity[9], identity[10], identity[11]);
		SEngine::Vector4 idenVec3(identity[12], identity[13], identity[14], identity[15]);

		vec0 /= vec0.GetX(); idenVec0 /= vec0.GetX();
		if (vec1.GetX() > 0)
		{
			vec1 -= (vec0*vec1.GetX()); idenVec1 -= (idenVec0*vec1.GetX());
			vec2 -= (vec0*vec2.GetX()); idenVec2 -= (idenVec0*vec2.GetX());
			vec3 -= (vec0*vec3.GetX()); idenVec3 -= (idenVec0*vec3.GetX());
		}
		else
		{
			vec1 += (vec0*vec1.GetX()); idenVec1 += (idenVec0*vec1.GetX());
			vec2 += (vec0*vec2.GetX()); idenVec2 += (idenVec0*vec2.GetX());
			vec3 += (vec0*vec3.GetX()); idenVec3 += (idenVec0*vec3.GetX());
		}
		vec1 /= vec1.GetY(); idenVec1 /= vec1.GetY();
		if (vec2.GetY() > 0)
		{
			vec2 -= (vec1*vec2.GetY()); idenVec2 -= (idenVec1*vec2.GetY());
			vec3 -= (vec1*vec3.GetY()); idenVec3 -= (idenVec1*vec3.GetY());
		}
		else
		{
			vec2 += (vec1*vec2.GetY()); idenVec2 += (idenVec1*vec2.GetY());
			vec3 += (vec1*vec3.GetY()); idenVec3 += (idenVec1*vec3.GetY());
		}
		vec2 /= vec2.GetZ(); idenVec2 /= vec2.GetZ();
		if (vec1.GetZ() > 0)
		{
			vec3 -= (vec2*vec3.GetZ()); idenVec3 -= (idenVec2*vec3.GetZ());
		}
		else
		{
			vec3 += (vec2*vec3.GetZ()); idenVec3 += (idenVec2*vec3.GetZ());
		}
		vec3 /= vec3.GetW(); idenVec3 /= vec3.GetW();
		if (vec2.GetW() > 0)
		{
			vec2 -= (vec3*vec2.GetW()); idenVec2 -= (idenVec3*vec2.GetW());
		}
		else
		{
			vec2 += (vec3*vec2.GetW()); idenVec2 += (idenVec3*vec2.GetW());
		}
		if (vec1.GetW() > 0)
		{
			vec1 -= (vec3*vec1.GetW()); idenVec1 -= (idenVec3*vec1.GetW());
		}
		else
		{
			vec1 += (vec3*vec1.GetW()); idenVec1 += (idenVec3*vec1.GetW());
		}
		if (vec1.GetZ() > 0)
		{
			vec1 -= (vec2*vec1.GetZ()); idenVec1 -= (idenVec2*vec1.GetZ());
		}
		else
		{
			vec1 += (vec2*vec1.GetZ()); idenVec1 += (idenVec2*vec1.GetZ());
		}
		if (vec0.GetW() > 0)
		{
			vec0 -= (vec3*vec0.GetW()); idenVec0 -= (idenVec3*vec0.GetW());
		}
		else
		{
		vec0 += (vec3*vec0.GetW()); idenVec0 += (idenVec3*vec0.GetW()); 
		}
		if (vec0.GetZ() > 0)
		{
			vec0 -= (vec2*vec0.GetZ()); idenVec0 -= (idenVec2*vec0.GetZ());
		}
		else
		{
		vec0 += (vec2*vec0.GetZ()); idenVec0 += (idenVec2*vec0.GetZ()); 
		}
		if (vec0.GetY() > 0)
		{
			vec0 -= (vec1*vec0.GetY()); idenVec0 -= (idenVec1*vec0.GetY());
		}
		else
		{
		vec0 += (vec1*vec0.GetY()); idenVec0 += (idenVec1*vec0.GetY());
		}
		return SEngine::Matrix(idenVec0, idenVec1, idenVec2, idenVec3);

	}
	else
	{
		printf("the matrix has no inverse!");
	}
}
//rotates the matrix around the x axis
__forceinline void SEngine::Matrix::rotationX(float scal)
{
	Matrix rotMat(1, 0, 0, 0,
		0, cos(scal), -sin(scal), 0,
		0, sin(scal), cos(scal), 0,
		0, 0, 0, 1); 
	*this *= rotMat;
}
//rotates the matrix around the y axis
__forceinline void SEngine::Matrix::rotationY(float scal)
{
	Matrix rotMat(cos(scal), 0, sin(scal), 0,
		0, 1, 0, 0,
		-sin(scal), 0, cos(scal), 0,
		0, 0, 0, 1);
	*this *= rotMat;
}
//rotates the matrix around the z axis
__forceinline void SEngine::Matrix::rotationZ(float scal)
{
	Matrix rotMat(cos(scal), -sin(scal), 0, 0,
		sin(scal), cos(scal), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	*this *= rotMat;
}
//translate the matrix across the vec3 you put in
__forceinline void SEngine::Matrix::translate(SEVector3& vec0)
{
	Matrix transMat(1, 0, 0, vec0.GetX(),
		0, 1, 0, vec0.GetY(),
		0, 0, 1, vec0.GetZ(),
		0, 0, 0, 1);
	*this *= transMat;
}
//scales the matrix with the input scalingfactor
__forceinline void SEngine::Matrix::scaling(SEVector3& vec0)
{
	Matrix scaleMat(vec0.GetX(), 0, 0, 0,
		0, vec0.GetY(), 0, 0,
		0, 0, vec0.GetZ(), 0,
		0, 0, 0, 1);
	*this *= scaleMat;
}
//operator '*' override with another matrix
__forceinline SEngine::Matrix SEngine::Matrix::operator*(const SEngine::Matrix& mat) const
{
	return SEngine::Matrix(
		Matrix::m4x4[0] * mat.m4x4[0] + Matrix::m4x4[1] * mat.m4x4[4] + Matrix::m4x4[2] * mat.m4x4[8] + Matrix::m4x4[3] * mat.m4x4[12],
		Matrix::m4x4[0] * mat.m4x4[1] + Matrix::m4x4[1] * mat.m4x4[5] + Matrix::m4x4[2] * mat.m4x4[9] + Matrix::m4x4[3] * mat.m4x4[13],
		Matrix::m4x4[0] * mat.m4x4[2] + Matrix::m4x4[1] * mat.m4x4[6] + Matrix::m4x4[2] * mat.m4x4[10] + Matrix::m4x4[3] * mat.m4x4[14],
		Matrix::m4x4[0] * mat.m4x4[3] + Matrix::m4x4[1] * mat.m4x4[7] + Matrix::m4x4[2] * mat.m4x4[11] + Matrix::m4x4[3] * mat.m4x4[15],
		Matrix::m4x4[4] * mat.m4x4[0] + Matrix::m4x4[5] * mat.m4x4[4] + Matrix::m4x4[6] * mat.m4x4[8] + Matrix::m4x4[7] * mat.m4x4[12],
		Matrix::m4x4[4] * mat.m4x4[1] + Matrix::m4x4[5] * mat.m4x4[5] + Matrix::m4x4[6] * mat.m4x4[9] + Matrix::m4x4[7] * mat.m4x4[13],
		Matrix::m4x4[4] * mat.m4x4[2] + Matrix::m4x4[5] * mat.m4x4[6] + Matrix::m4x4[6] * mat.m4x4[10] + Matrix::m4x4[7] * mat.m4x4[14],
		Matrix::m4x4[4] * mat.m4x4[3] + Matrix::m4x4[5] * mat.m4x4[7] + Matrix::m4x4[6] * mat.m4x4[11] + Matrix::m4x4[7] * mat.m4x4[15],
		Matrix::m4x4[8] * mat.m4x4[0] + Matrix::m4x4[9] * mat.m4x4[4] + Matrix::m4x4[10] * mat.m4x4[8] + Matrix::m4x4[11] * mat.m4x4[12],
		Matrix::m4x4[8] * mat.m4x4[1] + Matrix::m4x4[9] * mat.m4x4[5] + Matrix::m4x4[10] * mat.m4x4[9] + Matrix::m4x4[11] * mat.m4x4[13],
		Matrix::m4x4[8] * mat.m4x4[2] + Matrix::m4x4[9] * mat.m4x4[6] + Matrix::m4x4[10] * mat.m4x4[10] + Matrix::m4x4[11] * mat.m4x4[14],
		Matrix::m4x4[8] * mat.m4x4[3] + Matrix::m4x4[9] * mat.m4x4[7] + Matrix::m4x4[10] * mat.m4x4[11] + Matrix::m4x4[11] * mat.m4x4[15],
		Matrix::m4x4[12] * mat.m4x4[0] + Matrix::m4x4[13] * mat.m4x4[4] + Matrix::m4x4[14] * mat.m4x4[8] + Matrix::m4x4[15] * mat.m4x4[12],
		Matrix::m4x4[12] * mat.m4x4[1] + Matrix::m4x4[13] * mat.m4x4[5] + Matrix::m4x4[14] * mat.m4x4[9] + Matrix::m4x4[15] * mat.m4x4[13],
		Matrix::m4x4[12] * mat.m4x4[2] + Matrix::m4x4[13] * mat.m4x4[6] + Matrix::m4x4[14] * mat.m4x4[10] + Matrix::m4x4[15] * mat.m4x4[14],
		Matrix::m4x4[12] * mat.m4x4[3] + Matrix::m4x4[13] * mat.m4x4[7] + Matrix::m4x4[14] * mat.m4x4[11] + Matrix::m4x4[15] * mat.m4x4[15]);
}
//operator '*' override with a vec3
__forceinline SEngine::Matrix SEngine::Matrix::operator*(SEngine::Vector3& vec3) const
{
	float vec3X = vec3.GetX();
	float vec3Y = vec3.GetY(); 
	float vec3Z = vec3.GetZ(); 
	return SEngine::Matrix{
	Matrix::m4x4[0] * vec3X, Matrix::m4x4[1] * vec3Y, Matrix::m4x4[2] * vec3Z, Matrix::m4x4[3] * 1,
	Matrix::m4x4[4] * vec3X, Matrix::m4x4[5] * vec3Y, Matrix::m4x4[6] * vec3Z, Matrix::m4x4[7] * 1,
	Matrix::m4x4[8] * vec3X, Matrix::m4x4[9] * vec3Y, Matrix::m4x4[10] * vec3Z, Matrix::m4x4[11] * 1,
	Matrix::m4x4[12] * vec3X,Matrix::m4x4[13] * vec3Y, Matrix::m4x4[14] * vec3Z, Matrix::m4x4[15] * 1
	};
}
//operator '*' override with a vec4
__forceinline SEngine::Matrix SEngine::Matrix::operator*(const SEngine::Vector4& vec4) const
{
	float vec4x = vec4.GetX(); 
	float vec4y = vec4.GetY(); 
	float vec4z = vec4.GetZ(); 
	float vec4w = vec4.GetW(); 
	return SEngine::Matrix{
		Matrix::m4x4[0] * vec4x, Matrix::m4x4[1] * vec4y, Matrix::m4x4[2] * vec4z, Matrix::m4x4[3] * vec4w,
		Matrix::m4x4[4] * vec4x, Matrix::m4x4[5] * vec4y, Matrix::m4x4[6] * vec4z, Matrix::m4x4[7] * vec4w,
		Matrix::m4x4[8] * vec4x, Matrix::m4x4[9] * vec4y, Matrix::m4x4[10] * vec4z, Matrix::m4x4[11] * vec4w,
		Matrix::m4x4[12] * vec4x, Matrix::m4x4[13] * vec4y, Matrix::m4x4[14] * vec4z, Matrix::m4x4[15] * vec4w
	};
}
// operator '*=' override with another matrix
__forceinline void SEngine::Matrix::operator*=(const SEngine::Matrix& mat)
{
	Matrix::m4x4[0] = Matrix::m4x4[0] * mat.m4x4[0] + Matrix::m4x4[1] * mat.m4x4[4] + Matrix::m4x4[2] * mat.m4x4[8] + Matrix::m4x4[3] * mat.m4x4[12];
	Matrix::m4x4[1] = Matrix::m4x4[0] * mat.m4x4[1] + Matrix::m4x4[1] * mat.m4x4[5] + Matrix::m4x4[2] * mat.m4x4[9] + Matrix::m4x4[3] * mat.m4x4[13];
	Matrix::m4x4[2] = Matrix::m4x4[0] * mat.m4x4[2] + Matrix::m4x4[1] * mat.m4x4[6] + Matrix::m4x4[2] * mat.m4x4[10] + Matrix::m4x4[3] * mat.m4x4[14];
	Matrix::m4x4[3] = Matrix::m4x4[0] * mat.m4x4[3] + Matrix::m4x4[1] * mat.m4x4[7] + Matrix::m4x4[2] * mat.m4x4[11] + Matrix::m4x4[3] * mat.m4x4[15];
	Matrix::m4x4[4] = Matrix::m4x4[4] * mat.m4x4[0] + Matrix::m4x4[5] * mat.m4x4[4] + Matrix::m4x4[6] * mat.m4x4[8] + Matrix::m4x4[7] * mat.m4x4[12];
	Matrix::m4x4[5] = Matrix::m4x4[4] * mat.m4x4[1] + Matrix::m4x4[5] * mat.m4x4[5] + Matrix::m4x4[6] * mat.m4x4[9] + Matrix::m4x4[7] * mat.m4x4[13];
	Matrix::m4x4[6] = Matrix::m4x4[4] * mat.m4x4[2] + Matrix::m4x4[5] * mat.m4x4[6] + Matrix::m4x4[6] * mat.m4x4[10] + Matrix::m4x4[7] * mat.m4x4[14];
	Matrix::m4x4[7] = Matrix::m4x4[4] * mat.m4x4[3] + Matrix::m4x4[5] * mat.m4x4[7] + Matrix::m4x4[6] * mat.m4x4[11] + Matrix::m4x4[7] * mat.m4x4[15];
	Matrix::m4x4[8] = Matrix::m4x4[8] * mat.m4x4[0] + Matrix::m4x4[9] * mat.m4x4[4] + Matrix::m4x4[10] * mat.m4x4[8] + Matrix::m4x4[11] * mat.m4x4[12];
	Matrix::m4x4[9] = Matrix::m4x4[8] * mat.m4x4[1] + Matrix::m4x4[9] * mat.m4x4[5] + Matrix::m4x4[10] * mat.m4x4[9] + Matrix::m4x4[11] * mat.m4x4[13];
	Matrix::m4x4[10] = Matrix::m4x4[8] * mat.m4x4[2] + Matrix::m4x4[9] * mat.m4x4[6] + Matrix::m4x4[10] * mat.m4x4[10] + Matrix::m4x4[11] * mat.m4x4[14];
	Matrix::m4x4[11] = Matrix::m4x4[8] * mat.m4x4[3] + Matrix::m4x4[9] * mat.m4x4[7] + Matrix::m4x4[10] * mat.m4x4[11] + Matrix::m4x4[11] * mat.m4x4[15];
	Matrix::m4x4[12] = Matrix::m4x4[12] * mat.m4x4[0] + Matrix::m4x4[13] * mat.m4x4[4] + Matrix::m4x4[14] * mat.m4x4[8] + Matrix::m4x4[15] * mat.m4x4[12];
	Matrix::m4x4[13] = Matrix::m4x4[12] * mat.m4x4[1] + Matrix::m4x4[13] * mat.m4x4[5] + Matrix::m4x4[14] * mat.m4x4[9] + Matrix::m4x4[15] * mat.m4x4[13];
	Matrix::m4x4[14] = Matrix::m4x4[12] * mat.m4x4[2] + Matrix::m4x4[13] * mat.m4x4[6] + Matrix::m4x4[14] * mat.m4x4[10] + Matrix::m4x4[15] * mat.m4x4[14];
	Matrix::m4x4[15] = Matrix::m4x4[12] * mat.m4x4[3] + Matrix::m4x4[13] * mat.m4x4[7] + Matrix::m4x4[14] * mat.m4x4[11] + Matrix::m4x4[15] * mat.m4x4[15];
}
//operator '*=' override with a vec3
__forceinline void SEngine::Matrix::operator*=(const SEngine::Vector3& vec3)
{
	float x = vec3.GetX(); 
	float y = vec3.GetY(); 
	float z = vec3.GetZ(); 
	Matrix::m4x4[0] *= x; 
	Matrix::m4x4[1] *= y; 
	Matrix::m4x4[2] *= z; 
	//Matrix::m4x4[3] *= 1; Only for completeness
	Matrix::m4x4[4] *= x; 
	Matrix::m4x4[5] *= y; 
	Matrix::m4x4[6] *= z; 
	//Matrix::m4x4[7] *= 1; Only for completeness
	Matrix::m4x4[8] *= x; 
	Matrix::m4x4[9] *= y; 
	Matrix::m4x4[10] *= z; 
	//Matrix::m4x4[11] *= 1; Only for completeness
	Matrix::m4x4[12] *= x; 
	Matrix::m4x4[13] *= y; 
	Matrix::m4x4[14] *= z; 
	//Matrix::m4x4[15] *= 1; Only for completeness
}
//operator '*=' override with a vec4
__forceinline void SEngine::Matrix::operator*=(const SEngine::Vector4& vec4)
{
	float x = vec4.GetX();
	float y = vec4.GetY();
	float z = vec4.GetZ();
	float w = vec4.GetW();
	Matrix::m4x4[0] *= x;
	Matrix::m4x4[1] *= y;
	Matrix::m4x4[2] *= z;
	Matrix::m4x4[3] *= w;
	Matrix::m4x4[4] *= x;
	Matrix::m4x4[5] *= y;
	Matrix::m4x4[6] *= z;
	Matrix::m4x4[7] *= w;
	Matrix::m4x4[8] *= x;
	Matrix::m4x4[9] *= y;
	Matrix::m4x4[10] *= z;
	Matrix::m4x4[11] *= w;
	Matrix::m4x4[12] *= x;
	Matrix::m4x4[13] *= y;
	Matrix::m4x4[14] *= z;
	Matrix::m4x4[15] *= w; 
}
// operator '+' override with another matrix
__forceinline SEngine::Matrix SEngine::Matrix::operator+(const SEngine::Matrix& mat) const
{
	return SEngine::Matrix(
		Matrix::m4x4[0] + mat.m4x4[0], Matrix::m4x4[1] + mat.m4x4[1], Matrix::m4x4[2] + mat.m4x4[2], Matrix::m4x4[3] + mat.m4x4[3],
		Matrix::m4x4[4] + mat.m4x4[4], Matrix::m4x4[5] + mat.m4x4[5], Matrix::m4x4[6] + mat.m4x4[6], Matrix::m4x4[7] + mat.m4x4[7],
		Matrix::m4x4[8] + mat.m4x4[8], Matrix::m4x4[9] + mat.m4x4[9], Matrix::m4x4[10] + mat.m4x4[10], Matrix::m4x4[11] + mat.m4x4[11],
		Matrix::m4x4[12] + mat.m4x4[12], Matrix::m4x4[13] + mat.m4x4[13], Matrix::m4x4[14] + mat.m4x4[14], Matrix::m4x4[15] + mat.m4x4[15]);
}
// operator '+=' override with another matrix
__forceinline void SEngine::Matrix::operator+=(const SEngine::Matrix& mat)
{
	Matrix::m4x4[0] += mat.m4x4[0]; Matrix::m4x4[1] += mat.m4x4[1]; Matrix::m4x4[2] += mat.m4x4[2]; Matrix::m4x4[3] += mat.m4x4[3];
	Matrix::m4x4[4] += mat.m4x4[4]; Matrix::m4x4[5] += mat.m4x4[5]; Matrix::m4x4[6] += mat.m4x4[6]; Matrix::m4x4[7] += mat.m4x4[7];
	Matrix::m4x4[8] += mat.m4x4[8]; Matrix::m4x4[9] += mat.m4x4[9]; Matrix::m4x4[10] += mat.m4x4[10]; Matrix::m4x4[11] += mat.m4x4[11];
	Matrix::m4x4[12] += mat.m4x4[12]; Matrix::m4x4[13] += mat.m4x4[13]; Matrix::m4x4[14] += mat.m4x4[14]; Matrix::m4x4[15] += mat.m4x4[15];
	
}
// operator '-' override with another matrix
__forceinline SEngine::Matrix SEngine::Matrix::operator-(const SEngine::Matrix& mat) const
{
	return SEngine::Matrix(
		Matrix::m4x4[0] - mat.m4x4[0], Matrix::m4x4[1] - mat.m4x4[1], Matrix::m4x4[2] - mat.m4x4[2], Matrix::m4x4[3] - mat.m4x4[3],
		Matrix::m4x4[4] - mat.m4x4[4], Matrix::m4x4[5] - mat.m4x4[5], Matrix::m4x4[6] - mat.m4x4[6], Matrix::m4x4[7] - mat.m4x4[7],
		Matrix::m4x4[8] - mat.m4x4[8], Matrix::m4x4[9] - mat.m4x4[9], Matrix::m4x4[10] - mat.m4x4[10], Matrix::m4x4[11] - mat.m4x4[11],
		Matrix::m4x4[12] - mat.m4x4[12], Matrix::m4x4[13] - mat.m4x4[13], Matrix::m4x4[14] - mat.m4x4[14], Matrix::m4x4[15] - mat.m4x4[15]);
}
// operator '-=' override with another matrix
__forceinline void SEngine::Matrix::operator-=(const SEngine::Matrix& mat)
{
	Matrix::m4x4[0] -= mat.m4x4[0]; Matrix::m4x4[1] -= mat.m4x4[1]; Matrix::m4x4[2] -= mat.m4x4[2]; Matrix::m4x4[3] -= mat.m4x4[3];
	Matrix::m4x4[4] -= mat.m4x4[4]; Matrix::m4x4[5] -= mat.m4x4[5]; Matrix::m4x4[6] -= mat.m4x4[6]; Matrix::m4x4[7] -= mat.m4x4[7];
	Matrix::m4x4[8] -= mat.m4x4[8]; Matrix::m4x4[9] -= mat.m4x4[9]; Matrix::m4x4[10] -= mat.m4x4[10]; Matrix::m4x4[11] -= mat.m4x4[11]; 
	Matrix::m4x4[12] -= mat.m4x4[12]; Matrix::m4x4[13] -= mat.m4x4[13]; Matrix::m4x4[14] -= mat.m4x4[14]; Matrix::m4x4[15] -= mat.m4x4[15]; 
	
}
//operator '[]' override with an index. Returns the value on the index position
__forceinline float SEngine::Matrix::operator[](int8 index) const
{
	return Matrix::m4x4[index];
}
// operator '=' override with another matrix
__forceinline void SEngine::Matrix::operator=(const SEngine::Matrix& mat)
{
	Matrix::m4x4[0] = mat.m4x4[0];
	Matrix::m4x4[1] = mat.m4x4[1]; 
	Matrix::m4x4[2] = mat.m4x4[2]; 
	Matrix::m4x4[3] = mat.m4x4[3]; 
	Matrix::m4x4[4] = mat.m4x4[4]; 
	Matrix::m4x4[5] = mat.m4x4[5]; 
	Matrix::m4x4[6] = mat.m4x4[6]; 
	Matrix::m4x4[7] = mat.m4x4[7]; 
	Matrix::m4x4[8] = mat.m4x4[8]; 
	Matrix::m4x4[9] = mat.m4x4[9]; 
	Matrix::m4x4[10] = mat.m4x4[10]; 
	Matrix::m4x4[11] = mat.m4x4[11]; 
	Matrix::m4x4[12] = mat.m4x4[12]; 
	Matrix::m4x4[13] = mat.m4x4[13]; 
	Matrix::m4x4[14] = mat.m4x4[14]; 
	Matrix::m4x4[15] = mat.m4x4[15]; 
}
//operator '==' override with another matrix
__forceinline bool SEngine::Matrix::operator==(const SEngine::Matrix& mat)const
{
	if (Matrix::m4x4[0] == mat.m4x4[0] && Matrix::m4x4[1] == mat.m4x4[1] && Matrix::m4x4[2] == mat.m4x4[2] && Matrix::m4x4[3] == mat.m4x4[3]
		&& Matrix::m4x4[4] == mat.m4x4[4] && Matrix::m4x4[5] == mat.m4x4[5] && Matrix::m4x4[6] == mat.m4x4[6] && Matrix::m4x4[7] == mat.m4x4[7]
		&& Matrix::m4x4[8] == mat.m4x4[8] && Matrix::m4x4[9] == mat.m4x4[9] && Matrix::m4x4[10] == mat.m4x4[10] && Matrix::m4x4[11] == mat.m4x4[11]
		&& Matrix::m4x4[12] == mat.m4x4[12] && Matrix::m4x4[13] == mat.m4x4[13] && Matrix::m4x4[14] == mat.m4x4[14] && Matrix::m4x4[15] == mat.m4x4[15])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//operator '!=' override with another matrix
__forceinline bool SEngine::Matrix::operator!=(const SEngine::Matrix& mat) const
{
	if (Matrix::m4x4[0] == mat.m4x4[0] && Matrix::m4x4[1] == mat.m4x4[1] && Matrix::m4x4[2] == mat.m4x4[2] && Matrix::m4x4[3] == mat.m4x4[3]
		&& Matrix::m4x4[4] == mat.m4x4[4] && Matrix::m4x4[5] == mat.m4x4[5] && Matrix::m4x4[6] == mat.m4x4[6] && Matrix::m4x4[7] == mat.m4x4[7]
		&& Matrix::m4x4[8] == mat.m4x4[8] && Matrix::m4x4[9] == mat.m4x4[9] && Matrix::m4x4[10] == mat.m4x4[10] && Matrix::m4x4[11] == mat.m4x4[11]
		&& Matrix::m4x4[12] == mat.m4x4[12] && Matrix::m4x4[13] == mat.m4x4[13] && Matrix::m4x4[14] == mat.m4x4[14] && Matrix::m4x4[15] == mat.m4x4[15])
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



#endif