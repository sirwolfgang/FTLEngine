//===============================================================
// File:	Main.cpp
// Purpose: Entry Point for Game/Engine
//===============================================================
#include <FTLGraphics.h>

int CALLBACK WinMain(HINSTANCE _hInstance, 
					 HINSTANCE _hPrevInstance, 
					 LPSTR _lpCmdLine, 
					 int _nCmdShow)
{
	// TODO: Handle Parsing CMDLine arguments
	Platform::Window Window(_hInstance, _nCmdShow);

	Window.Create(Platform::Window::WINDOW_MODE_NORMAL, L"FTL Engine", 0, 0, 1024, 768);

	while(Window.Update());

	return NULL;
}