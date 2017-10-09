#pragma once
///internal includes
#pragma region Internal includes
#include "IWindow.h"
#include "MakroDefines.h"
#include "IGraphics.h"
#pragma endregion
///external includes
#pragma region External includes
#include <cstdint>
#include <Windows.h>
#pragma endregion


///
///
///DefaultWindow class which inherits from IWindow interface. Use this class if yout want a normal window. Use another class if you want some other kinds of windows
///
///

namespace SEngine
{
	class DefaultWindow : public IWindow
	{
	public:
		///
		///Constructors
		///
		DefaultWindow();
		DefaultWindow(uint16 resX, uint16 resY, HINSTANCE hInstance, int nCmdShow);		
		DefaultWindow(const DefaultWindow& win);
		///
		///Initialize the Window
		///
		void Init() override; 
		///
		///Run the Window
		///
		WPARAM Run() override; 
		///
		///ShutDown the Window
		///
		MSG ShutDown() override; 
		///
		///Destructor 
		///
		//~DefaultWindow();
		///
		///lil function to get the wndHandle for Graphics API
		///
		__forceinline HWND GetWindowHandle();
	private:
		///member variables
#pragma region Member variables
		uint16 m_ResolutionX; 
		uint16 m_ResolutionY; 
		uint16 m_NCmdShow;
		HINSTANCE m_HInstance;
		MSG m_Msg; 
		HWND m_HWnd{};
		WNDCLASSEX m_Wc{};
		IGraphics* m_Graphics;
#pragma endregion
	}; 
	///typedef to use the craphics DLL
	typedef SEngine::IGraphics* (*CREATE_GRAPHICS)();
}
