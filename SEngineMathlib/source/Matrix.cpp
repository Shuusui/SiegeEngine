#include "include\Matrix.h"

SEngine::Matrix::Matrix()
{
	Matrix::m4x4[0] = 0;
	Matrix::m4x4[1] = 0;
	Matrix::m4x4[2] = 0;
	Matrix::m4x4[3] = 0;
	Matrix::m4x4[4] = 0;
	Matrix::m4x4[5] = 0;
	Matrix::m4x4[6] = 0;
	Matrix::m4x4[7] = 0;
	Matrix::m4x4[8] = 0;
	Matrix::m4x4[9] = 0;
	Matrix::m4x4[10] = 0;
	Matrix::m4x4[11] = 0;
	Matrix::m4x4[12] = 0;
	Matrix::m4x4[13] = 0;
	Matrix::m4x4[14] = 0;
	Matrix::m4x4[15] = 0;
}
SEngine::Matrix::Matrix(float scal1, float scal2, float scal3, float scal4, float scal5, float scal6, float scal7, float scal8, float scal9, float scal10, float scal11, float scal12, float scal13, float scal14, float scal15, float scal16)
{
	Matrix::m4x4[0] = scal1;
	Matrix::m4x4[1] = scal2;
	Matrix::m4x4[2] = scal3;
	Matrix::m4x4[3] = scal4;
	Matrix::m4x4[4] = scal5;
	Matrix::m4x4[5] = scal6;
	Matrix::m4x4[6] = scal7;
	Matrix::m4x4[7] = scal8;
	Matrix::m4x4[8] = scal9;
	Matrix::m4x4[9] = scal10;
	Matrix::m4x4[10] = scal11;
	Matrix::m4x4[11] = scal12;
	Matrix::m4x4[12] = scal13;
	Matrix::m4x4[13] = scal14;
	Matrix::m4x4[14] = scal15;
	Matrix::m4x4[15] = scal16;
}
SEngine::Matrix::Matrix(SEVector4& vec0, SEVector4& vec1, SEVector4& vec2, SEVector4& vec3)
{
	Matrix::m4x4[0] = vec0.GetX();
	Matrix::m4x4[1] = vec0.GetY();
	Matrix::m4x4[2] = vec0.GetZ();
	Matrix::m4x4[3] = vec0.GetW();
	Matrix::m4x4[4] = vec1.GetX();
	Matrix::m4x4[5] = vec1.GetY();
	Matrix::m4x4[6] = vec1.GetZ();
	Matrix::m4x4[7] = vec1.GetW();
	Matrix::m4x4[8] = vec2.GetX();
	Matrix::m4x4[9] = vec2.GetY();
	Matrix::m4x4[10] = vec2.GetZ();
	Matrix::m4x4[11] = vec2.GetW();
	Matrix::m4x4[12] = vec3.GetX();
	Matrix::m4x4[13] = vec3.GetY();
	Matrix::m4x4[14] = vec3.GetZ();
	Matrix::m4x4[15] = vec3.GetW();
}
SEngine::Matrix::Matrix(SEngine::Matrix& mat)
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

SEngine::Matrix::~Matrix()
{

}