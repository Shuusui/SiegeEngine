#include "include\Vector2.h"

SEngine::Vector2::Vector2()
{
	Vector2::X = 0;
	Vector2::Y = 0;
}
SEngine::Vector2::Vector2(float x, float y)
{
	Vector2::X = x;
	Vector2::Y = y;
}
SEngine::Vector2::Vector2(int8 x, int8 y)
{
	Vector2::X = static_cast<float>(x);
	Vector2::Y = static_cast<float>(y);
}
SEngine::Vector2::Vector2(int16 x, int16 y)
{
	Vector2::X = static_cast<float>(x);
	Vector2::Y = static_cast<float>(y);
}
SEngine::Vector2::Vector2(int32 x, int32 y)
{
	Vector2::X = static_cast<float>(x);
	Vector2::Y = static_cast<float>(y);
}
SEngine::Vector2::Vector2(const Vector2& vec0)
{
	Vector2::X = vec0.X;
	Vector2::Y = vec0.Y;
}

SEngine::Vector2::~Vector2()
{

}