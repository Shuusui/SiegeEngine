#include "Color.h"

//Default Constructor
SEngine::Color::Color()
{
	Color::r = 0;
	Color::g = 0;
	Color::b = 0;
	Color::a = 0;
	Color::rgba = 0;
}
//Constructor with r,g,b,a 
SEngine::Color::Color(uint8 r, uint8 g, uint8 b, uint8 a)
{
	Color::r = r;
	Color::g = g;
	Color::b = b;
	Color::a = a;
	Color::rgba = Color::r << 24 | Color::g << 16 | Color::b << 8 | Color::a;
}
//Constructor with rgba
SEngine::Color::Color(uint32 rgba)
{
	Color::r = (rgba >> 24) & 0xff;
	Color::g = (rgba >> 16) & 0xff;
	Color::b = (rgba >> 8) & 0xff;
	Color::a = rgba & 0xff;
	Color::rgba = rgba;
}
//Constructor with floats as r,g,b,a
SEngine::Color::Color(float r, float g, float b, float a)
{
	Color::r = r * 255;
	Color::g = g * 255;
	Color::b = b * 255;
	Color::a = a * 255;
	Color::rgba = Color::r << 24 | Color::g << 16 | Color::b << 8 | Color::a;
}
//Copy Constructor
SEngine::Color::Color(const Color& col)
{
	Color::r = col.GetR(); 
	Color::g = col.GetG();
	Color::b = col.GetB(); 
	Color::a = col.GetA();
	Color::rgba = col.GetRGBA(); 
}