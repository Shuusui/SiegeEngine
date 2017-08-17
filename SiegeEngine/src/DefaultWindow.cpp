#include "include\DefaultWindow.h"

//default WindowProc function
LRESULT CALLBACK WindowProc(HWND m_HWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	if (message == WM_CLOSE)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(
		m_HWnd, message, wParam, lParam);
}
//Default Constructor
SEngine::DefaultWindow::DefaultWindow()
	:m_ResolutionX(NULL)
	,m_ResolutionY(NULL)
	,m_HInstance(NULL)
	,m_NCmdShow(NULL)
	,m_Graphics(nullptr)

{	
}
//Constructor which sets the resolution and other settings for the wnd Class
SEngine::DefaultWindow::DefaultWindow(uint16 resX, uint16 resY, HINSTANCE m_HInstance, int m_NCmdShow)
	:m_ResolutionX(resX)
	,m_ResolutionY(resY)
	,m_HInstance(m_HInstance)
	,m_NCmdShow(m_NCmdShow)
	,m_Graphics(nullptr)
{
}
//Default Copy Constructor
SEngine::DefaultWindow::DefaultWindow(const SEngine::DefaultWindow& win)
	:m_ResolutionX(win.m_ResolutionX)
	,m_ResolutionY(win.m_ResolutionY)
	,m_HInstance(win.m_HInstance)
	,m_NCmdShow(win.m_NCmdShow)
	,m_Graphics(win.m_Graphics)
{
}
//Initialize function of the DefaultWindow class
void SEngine::DefaultWindow::Init() 
{
	m_Wc.cbSize = sizeof(WNDCLASSEX);
	m_Wc.style = CS_HREDRAW | CS_VREDRAW; 
	m_Wc.lpfnWndProc = WindowProc; 
	m_Wc.hInstance = DefaultWindow::m_HInstance; 
	m_Wc.lpszClassName = L"DefaultWindow_Wclass"; 
	m_Wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	
	RegisterClassEx(&m_Wc);
	m_HWnd = CreateWindowEx(
		NULL,
		L"DefaultWindow_Wclass", 
		L"SiegeEngine", 
		WS_OVERLAPPEDWINDOW, 
		0, 
		0, 
		m_ResolutionX, 
		m_ResolutionY, 
		NULL, 
		NULL, 
		m_HInstance, 
		NULL);
}
//Run function of the DefaultWindow Class
WPARAM SEngine::DefaultWindow::Run()
{
	HMODULE graphicsModule = LoadLibrary(L"module\\SEngineGraphics.dll");
	CREATE_GRAPHICS createGraphics = nullptr; 
	createGraphics = (CREATE_GRAPHICS)GetProcAddress(graphicsModule, "CreateGraphics");
	m_Graphics = createGraphics();
	m_Graphics->SetWindowHandle(m_HWnd);
	m_Graphics->Init(m_ResolutionX, m_ResolutionY);
	while (true)
	{
		if (PeekMessage(&m_Msg, nullptr, 0, 0, PM_REMOVE))
		{

			if (m_Msg.message == WM_QUIT)
			{
				break;
			}
			ShowWindow(m_HWnd, DefaultWindow::m_NCmdShow);
			UpdateWindow(m_HWnd);
			m_Graphics->Run();
			TranslateMessage(&m_Msg);
			DispatchMessage(&m_Msg);
		}
	}
	m_Graphics->ShutDown();
	return m_Msg.wParam;
}
//Shut down function of the DefaultWindow class
MSG SEngine::DefaultWindow::ShutDown()
{
	m_Msg.message = WM_QUIT; 
	return m_Msg;
}
//little function to get the windowHandle of the DefaultWindow class
__forceinline HWND SEngine::DefaultWindow::GetWindowHandle()
{
	return m_HWnd;
}
//Default Destructor
SEngine::DefaultWindow::~DefaultWindow()
{

}