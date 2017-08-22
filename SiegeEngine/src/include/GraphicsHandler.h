#pragma once
///internal includes
#pragma region Internal includes
#include "IGraphics.h"
#include "MakroDefines.h"

#pragma endregion

///
///
///Handler for the Graphics API's to make sure they work fluent. Use 0 for DX11 or 1 for OpenGL
///
///

namespace SEngineGraphics
{
	class GraphicsHandler : public SEngine::IGraphics
	{
	public:
		///
		///constructor which will set the Graphics API in first instance.
		///
		GraphicsHandler();
		///
		///initialize the set graphics API
		///
		void Init(uint16 wndWidth, uint16 wndHeight) override;
		///
		///Run the set graphics API
		///
		void Run() override; 
		///
		///ShutDown the set graphics API
		///
		void ShutDown() override; 
		///
		///function to set the wnd handle for the Graphics API
		///
		void SetWindowHandle(HWND hwnd) override;
		///
		///function to choose the GraphicsAPI at the first instance
		/// 
		void SetGraphicsAPI(uint8f index) override;
		///
		///function  which will change the Graphics API in real time.
		///
		void ChangeGraphicsAPI(uint8f from, uint8f to) override;
		///
		///Destructor
		///
		~GraphicsHandler(); 
	private: 
		///
		///private function which returns a IGraphics* to use the DLL. 
		///
		SEngine::IGraphics* CreateGraphics();

		///member variables
#pragma region Member variables
		IGraphics* m_Graphics;
		uint8f m_GraphicsIndex; 
		uint16 m_WndWidth; 
		uint16 m_WndHeight;
#pragma endregion
	};
}
typedef SEngine::IGraphics* (*CREATE_GRAPHICS)();
