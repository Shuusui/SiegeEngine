#ifndef _COLOR_H_
#define _COLOR_H_
///internal includes
#pragma region Internal includes
#include "MakroDefines.h"
#pragma endregion
///external includes
#pragma region External includes
#pragma endregion


///Helper lines: int farbe = 12873812 || 0xaabbccdd;
/// int a = farbe & 0xff; 
/// int r = (farbe >> 24) & 0xff;

namespace SEngine
{
	class Color
	{
	public:
		///
		///Constructors
		///
		Color();
		Color(uint8 r, uint8 g, uint8 b, uint8 a);
		Color(uint32 rgba);
		Color(float r, float g, float b, float a);	
		Color(const Color& col);
		///
		///Getter functions
		///
		uint32 GetRGBA() const;
		uint8 GetR() const;
		uint8 GetG() const;
		uint8 GetB() const;
		uint8 GetA() const;
		///
		///Function which forms the rgba to argb 
		///
		uint32 ToARGB();
		///
		///Function which forms the rgba to bgra 
		///
		uint32 ToBGRA();
		///
		///Function which forms the rgba to abgr 
		///
		uint32 ToABGR();
		///
		///Function which returns the rgba as a float 
		///
		float ToFloatRGBA();
		///
		///Function which returns the r value as a float 
		///
		float ToFloatR();
		///
		///Function which returns the g value as a float
		///
		float ToFloatG();
		///
		///Function which returns the b value as a float 
		///
		float ToFloatB();
		///
		///Function which returns the a value as a float
		///
		float ToFloatA();
		///
		///operator '==' override 
		///
		Color operator!=(const Color& col);
		///
		///Operator '+' override
		///
		Color operator+(const Color& col);
		///
		///operatpr '-' override
		///
		Color operator-(const Color& col);			
		///
		///operator '*' override
		///
		Color operator*(const Color& col);
		Color operator/(const Color& col);
	private:
		///Member variables 
#pragma region Member variables
		uint32 rgba;
		uint8 r;
		uint8 g;
		uint8 b;
		uint8 a;
#pragma endregion 
	};
}
#include "Color.hpp"
#endif //_COLOR_H_