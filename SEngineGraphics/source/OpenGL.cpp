#include "include\OpenGL.h"

SEngineGraphics::OpenGL::OpenGL()
	:m_WndHeight(0)
	,m_WndWidth(0)
	,m_Context(nullptr)
	,m_ContextHandle(nullptr)
	,m_Hwnd(nullptr)
{

}


bool SEngineGraphics::OpenGL::Init(uint16 wndWidth, uint16 wndHeight)
{
	m_WndHeight = wndHeight; 
	m_WndWidth = wndWidth; 

	m_ContextHandle = GetDC(m_Hwnd);

	PIXELFORMATDESCRIPTOR pixForDesc{};
	pixForDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR); 
	pixForDesc.nVersion = 1;
	pixForDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixForDesc.iPixelType = PFD_TYPE_RGBA;
	pixForDesc.cColorBits = 32;
	pixForDesc.cDepthBits = 32; 
	
	int32 format = ChoosePixelFormat(m_ContextHandle, &pixForDesc);
	if (format == 0)
	{
		return false;
	}
	if (SetPixelFormat(m_ContextHandle, format, &pixForDesc)== FALSE)
	{
		return false;
	}
	m_Context = wglCreateContext(m_ContextHandle);
	if (!wglMakeCurrent(m_ContextHandle, m_Context))
	{
		return false;
	}
	GLenum errContext = glewInit(); 
	if (errContext != GLEW_OK)
	{
		fprintf(stderr, "%s\n", glewGetErrorString(errContext));
		return false;
	}
	return true;
}

void SEngineGraphics::OpenGL::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static bool i = false; 
	i = !i; 
	glClearColor(i ? .5f : .1f, i ? .8f : .3f, i ? .1f : .2f, i ? .7f : 1.0f);
	SwapBuffers(m_ContextHandle);
}

void SEngineGraphics::OpenGL::Exit()
{
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(m_Context);
	m_Context = nullptr;
}

void SEngineGraphics::OpenGL::SetWindowHandle(HWND hwnd)
{
	m_Hwnd = hwnd;
	if (m_Context != nullptr)
	{
		ReleaseDC(m_Hwnd, m_ContextHandle);
		m_ContextHandle = nullptr;
	}
	if (m_ContextHandle != nullptr)
	{
		wglDeleteContext(m_Context); 
		m_Context = nullptr;
	}
}

