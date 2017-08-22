#include "include\GraphicsHandler.h"
SEngineGraphics::GraphicsHandler::GraphicsHandler()
	:m_GraphicsIndex(NULL)
	,m_DX11(nullptr)
	,m_OpenGL(nullptr)
	,m_WndWidth(NULL)
	,m_WndHeight(NULL)
{
	m_DX11 = new DirectX11();
	m_OpenGL = new OpenGL();
}

void SEngineGraphics::GraphicsHandler::Init(uint16 wndWidth, uint16 wndHeight)
{
	m_WndWidth = wndWidth; 
	m_WndHeight = wndHeight;
	if (m_GraphicsIndex == 0)
	{
		m_DX11->Init(wndWidth, wndHeight);
	}
	else if (m_GraphicsIndex == 1)
	{
		m_OpenGL->Init(wndWidth, wndHeight);
	}
}
void SEngineGraphics::GraphicsHandler::Run()
{
	if (m_GraphicsIndex == 0)
	{
		m_DX11->Run();
	}
	else if (m_GraphicsIndex == 1)
	{
		m_OpenGL->ClearScreen();
	}
}
void SEngineGraphics::GraphicsHandler::ShutDown()
{
	if (m_GraphicsIndex == 0)
	{
		m_DX11->ShutDown(); 
	}
	else if(m_GraphicsIndex == 1)
	{
		m_OpenGL->Exit();
	}
}
void SEngineGraphics::GraphicsHandler::SetWindowHandle(HWND hwnd)
{
	if (m_GraphicsIndex == 0)
	{
		m_DX11->SetWindowHandle(hwnd);
	}
	else if (m_GraphicsIndex == 1)
	{
		m_OpenGL->SetWindowHandle(hwnd);
	}
}
void SEngineGraphics::GraphicsHandler::ChangeGraphicsAPI(uint8f from, uint8f to)
{
	if (from == 0)
	{
		m_DX11->ShutDown();
		if (to == 1)
		{
			m_OpenGL->Init(m_WndHeight, m_WndWidth); 
			m_OpenGL->ClearScreen();
		}
	}
	else if (from == 1)
	{
		m_OpenGL->Exit();
		{
			if (to == 0)
			{
				m_DX11->Init(m_WndWidth, m_WndHeight); 
				m_DX11->Run();
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
	delete m_DX11; 
	delete m_OpenGL;
}