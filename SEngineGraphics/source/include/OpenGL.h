#pragma once
///internal includes
#pragma region Internal includes
#include "MakroDefines.h"
#pragma endregion
///external includes 
#pragma region External includes
#include <glew.h>
#include <wglew.h>
#include <GL\GL.h>
#include <fstream>
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
		bool Init(uint16 wndHeight, uint16 wndWidth); 
		///
		///Clears the screen with a static color
		///
		void ClearScreen(); 
		///
		///Exit OpenGL
		///
		void Exit();
		///
		///little function to set the wndHandle for the graphics API
		///
		void SetWindowHandle(HWND hwnd);
	private: 
		///Member Variables
#pragma region Member Variables
		uint16 m_WndHeight; 
		uint16 m_WndWidth; 
		HDC m_ContextHandle{};
		HGLRC m_Context{};
		HWND m_Hwnd{};
#pragma endregion
	};
}