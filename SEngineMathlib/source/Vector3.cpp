#include "include\Vector3.h"



SEngine::Vector3::Vector3()
{
	Vector3::X = 0;
	Vector3::Y = 0;
	Vector3::Z = 0;
}
SEngine::Vector3::Vector3(float x, float y, float z)
{
	Vector3::X = x;
	Vector3::Y = y;
	Vector3::Z = z;
}

SEngine::Vector3::Vector3(int8 x, int8 y, int8 z)
{
	Vector3::X = static_cast<float>(x);
	Vector3::Y = static_cast<float>(y);
	Vector3::Z = static_cast<float>(z);
}

SEngine::Vector3::Vector3(int16 x, int16 y, int16 z)
{
	Vector3::X = static_cast<float>(x);
	Vector3::Y = static_cast<float>(y);
	Vector3::Z = static_cast<float>(z);
}

SEngine::Vector3::Vector3(int32 x, int32 y, int32 z)
{
	Vector3::X = static_cast<float>(x);
	Vector3::Y = static_cast<float>(y);
	Vector3::Z = static_cast<float>(z);
}

SEngine::Vector3::Vector3(const Vector3& vec0)
{
	Vector3::X = vec0.X;
	Vector3::Y = vec0.Y;
	Vector3::Z = vec0.Z;
}

SEngine::Vector3::~Vector3()
{

}
