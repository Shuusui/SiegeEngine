#pragma once
///internal includes
#pragma region Internal includes
#include "IGraphics.h"
#pragma endregion
///external includes
#pragma region External includes
#include <Windows.h>
#pragma endregion 

///
///
///interface for the window class to run different windows while run the engine
///
///

namespace SEngine
{
	class IWindow
	{
	public:
		///
		///pure virtual function to initialize a window
		///
		virtual void Init() = 0; 
		///
		///pure virtual function to run the window
		///
		virtual WPARAM Run() = 0; 
		///
		///pure virtual function to shut down the window
		///
		virtual MSG ShutDown() = 0; 
		///
		///default Destructor
		///
		~IWindow(); 
	};
}