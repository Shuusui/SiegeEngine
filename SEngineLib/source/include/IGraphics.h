#pragma once
///internal includes
#pragma region Internal includes
#include "MakroDefines.h"
#pragma endregion
///external includes
#pragma region External includes
#include <Windows.h>
#pragma endregion

///
///
///Interface for the GraphicsAPI class
///
///

namespace SEngine
{
	class IGraphics
	{
	public:
		///
		///pure virtual function to initialize the Graphics API
		///
		virtual void Init(uint16 wndWidth, uint16 wndHeight) = 0; 
		/// 
		///pure virtual function to run the Grahphics API
		///
		virtual void Run() = 0; 
		///
		///pure virtual function to shut down the Graphics API
		///
		virtual void ShutDown() = 0; 
		///
		///pure virtual function to set the wnd handle
		///
		virtual void SetWindowHandle(HWND hwnd) = 0;
		///
		///pure virtual function to set the graphhics API in the first instance
		///
		virtual void SetGraphicsAPI(uint8f index) = 0;
		///
		///pure virtual function to change the graphics API you will use
		///
		virtual void ChangeGraphicsAPI(uint8f from, uint8f to) = 0;
		///
		///default virtual destructor
		///
		//virtual ~IGraphics() = 0;
	};
}