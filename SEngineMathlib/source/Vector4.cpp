#include "include\Vector4.h"


SEngine::Vector4::Vector4()
{
	Vector4::X = 0;
	Vector4::Y = 0;
	Vector4::Z = 0;
	Vector4::W = 0;
}

SEngine::Vector4::Vector4(float x, float y, float z, float w)
{
	Vector4::X = x;
	Vector4::Y = y;
	Vector4::Z = z;
	Vector4::W = w;
}
SEngine::Vector4::Vector4(int8 x, int8 y, int8 z, int8 w)
{
	Vector4::X = static_cast<float>(x);
	Vector4::Y = static_cast<float>(y);
	Vector4::Z = static_cast<float>(z);
	Vector4::W = static_cast<float>(w);
}
SEngine::Vector4::Vector4(int16 x, int16 y, int16 z, int16 w)
{
	Vector4::X = static_cast<float>(x);
	Vector4::Y = static_cast<float>(y);
	Vector4::Z = static_cast<float>(z);
	Vector4::W = static_cast<float>(w);
}
SEngine::Vector4::Vector4(int32 x, int32 y, int32 z, int32 w)
{
	Vector4::X = static_cast<float>(x);
	Vector4::Y = static_cast<float>(y);
	Vector4::Z = static_cast<float>(z);
	Vector4::W = static_cast<float>(w);
}

SEngine::Vector4::Vector4(const Vector4& vec0)
{
	Vector4::X = vec0.X;
	Vector4::Y = vec0.Y;
	Vector4::Z = vec0.Z;
	Vector4::W = vec0.W;
}
SEngine::Vector4::Vector4(SEVector3& vec0, float w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY();
	Vector4::Z = vec0.GetZ();
	Vector4::W = w;
}
SEngine::Vector4::Vector4(SEVector3& vec0, int8 w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY();
	Vector4::Z = vec0.GetZ();
	Vector4::W = w;
}
SEngine::Vector4::Vector4(SEVector3& vec0, int16 w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY();
	Vector4::Z = vec0.GetZ();
	Vector4::W = w;
}
SEngine::Vector4::Vector4(SEVector3& vec0, int32 w)
{
	Vector4::X = vec0.GetX();
	Vector4::Y = vec0.GetY();
	Vector4::Z = vec0.GetZ();
	Vector4::W = w;
}

SEngine::Vector4::~Vector4()
{

}