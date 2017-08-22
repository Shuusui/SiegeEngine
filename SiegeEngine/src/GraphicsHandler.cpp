#include "include\GraphicsHandler.h"
SEngineGraphics::GraphicsHandler::GraphicsHandler()
	:m_GraphicsIndex(NULL)
	
	,m_WndWidth(NULL)
	,m_WndHeight(NULL)
{
	
}

void SEngineGraphics::GraphicsHandler::Init(uint16 wndWidth, uint16 wndHeight)
{
	
	m_WndWidth = wndWidth; 
	m_WndHeight = wndHeight;
	if (m_GraphicsIndex == 0)
	{
		HMODULE graphicsModule = LoadLibrary(L"module\\SEngineGraphics.dll");
		CREATE_GRAPHICS createGraphics = nullptr;
		createGraphics = (CREATE_GRAPHICS)GetProcAddress(graphicsModule, "CreateGraphics");
		m_Graphics = createGraphics();
		
	}
	else if (m_GraphicsIndex == 1)
	{
	}
}
void SEngineGraphics::GraphicsHandler::Run()
{
	if (m_GraphicsIndex == 0)
	{
	}
	else if (m_GraphicsIndex == 1)
	{

	}
}
void SEngineGraphics::GraphicsHandler::ShutDown()
{
	if (m_GraphicsIndex == 0)
	{
	}
	else if(m_GraphicsIndex == 1)
	{ }
}
void SEngineGraphics::GraphicsHandler::SetWindowHandle(HWND hwnd)
{
	if (m_GraphicsIndex == 0)
	{
	}
	else if (m_GraphicsIndex == 1)
	{

	}
}
void SEngineGraphics::GraphicsHandler::ChangeGraphicsAPI(uint8f from, uint8f to)
{
	if (from == 0)
	{
		if (to == 1)
		{
			//TODO: include openGL here
		}
	}
	else if (from == 1)
	{
		//TODO: include openGL here
		{
			if (to == 0)
			{
			}
		}
	}
	else
	{
		printf("there are no GraphicAPI's avaiable, please choose 0 for DX11 or 1 for OpenGL");
	}

}
//Use this function only before instantiate the Graphics API the first time to predefine the GraphicsAPI. Use ChangeGraphicsAPI to change the Grahpics API in runtime
void SEngineGraphics::GraphicsHandler::SetGraphicsAPI(uint8f index)
{
	m_GraphicsIndex = index; 
}
SEngine::IGraphics* SEngineGraphics::GraphicsHandler::CreateGraphics()
{
	static SEngine::IGraphics* graphics = nullptr;
	graphics = new GraphicsHandler();
	return graphics;
}
SEngineGraphics::GraphicsHandler::~GraphicsHandler()
{
}