#pragma once
///internal includes
#pragma region Internal includes
#include "MakroDefines.h"
#pragma endregion
///external includes 
#pragma region External includes
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <math.h>
#pragma endregion

///
///
///OpenGL class which render the window 
///
///

namespace SEngineGraphics
{

	class OpenGL
	{
	public:
		///
		///Constructor
		///
		OpenGL();
		///
		///Initialize the Graphics API
		///
		void Init(uint16 wndHeight, uint16 wndWidth); 
		///
		///Clears the screen with a static color
		///
		void ClearScreen(); 
		///
		///Exit OpenGL
		///
		void Exit();
	private: 
		uint16 m_WndHeight; 
		uint16 m_WndWidth; 
	};
}