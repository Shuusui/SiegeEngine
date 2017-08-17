#include <Windows.h>
#include <fstream>
#include "include\DefaultWindow.h"
#include "EngineMakros.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DefaultWindow win = DefaultWindow(1920,1080,hInstance, nCmdShow);
	win.Init();
	win.Run();
	
	
	return 0;
}