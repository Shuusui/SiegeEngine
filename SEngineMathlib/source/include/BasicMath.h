#ifndef _BASICMATH_H_
#define _BASICMATH_H_
///Internal includes 

///External includes

#define PI float 3.14159265359
///
///
///Some basic static Math functions 
///
///

namespace SEngineMathlib
{
	class BasicMath
	{

		///
		///Static function for the squareRoot
		///
		__forceinline static float sqrRoot(float x); 

	};
}
#include "BasicMath.hpp"
#endif