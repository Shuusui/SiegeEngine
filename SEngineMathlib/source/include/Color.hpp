#ifndef _COLOR_H_
#error Do not include this file directly! 
#elif !defined _COLOR_HPP_
#define _COLOR_HPP_


uint32 SEngine::Color::GetRGBA() const
{
	return Color::rgba;
}
uint8 SEngine::Color::GetR() const
{
	return Color::r;
}
uint8 SEngine::Color::GetG() const
{
	return Color::g;
}
uint8 SEngine::Color::GetB() const
{
	return Color::b;
}
uint8 SEngine::Color::GetA() const
{
	return Color::a;
}
uint32 SEngine::Color::ToARGB()
{
	uint8 a = Color::a;
	uint8 r = Color::r;
	uint8 g = Color::g;
	uint8 b = Color::b;
	uint32 argb = a << 24 | r << 16 | g << 8 | b;
	return argb;
}

uint32 SEngine::Color::ToBGRA()
{
	uint8 b = Color::b;
	uint8 g = Color::g;
	uint8 r = Color::r;
	uint8 a = Color::a;
	uint32 bgra = b << 24 | g << 16 | r << 8 | a;
	return bgra;

}
uint32 SEngine::Color::ToABGR()
{
	uint8 a = Color::a;
	uint8 b = Color::b;
	uint8 g = Color::g;
	uint8 r = Color::r;

	uint32 abgr = a << 24 | b << 16 | g << 8 | r;
	return abgr;
}
float SEngine::Color::ToFloatRGBA()
{
	float rgbaf = Color::rgba / 255;
	return rgbaf;
}
float SEngine::Color::ToFloatR()
{
	float rf = Color::r / 255;
	return rf;
}
float SEngine::Color::ToFloatG()
{
	float gf = Color::g / 255;
	return gf;
}
float SEngine::Color::ToFloatB()
{
	float bf = Color::b / 255;
	return bf;
}
float SEngine::Color::ToFloatA()
{
	float af = Color::a / 255;
	return af;
}
SEngine::Color SEngine::Color::operator!=(const Color& col)
{
	uint32 val1 = Color::rgba;
	uint32 val2 = col.rgba;
	return val1 != val2;
}
//SEngine::Color SEngine::Color::operator+(const Color& col)
//{
//
//}
//SEngine::Color SEngine::Color::operator-(const Color& col)
//{
//
//}
//SEngine::Color SEngine::Color::operator*(const Color& col)
//{
//
//}
//SEngine::Color SEngine::Color::operator/(const Color& col)
//{
//
//}




#endif