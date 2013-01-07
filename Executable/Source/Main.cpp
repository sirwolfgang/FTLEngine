//===============================================================
// File:	Main.cpp
// Purpose: Entry Point for Game/Engine
//===============================================================
#include <FTLCore.h>

int CALLBACK WinMain(HINSTANCE _hInstance, 
					 HINSTANCE _hPrevInstance, 
					 LPSTR _lpCmdLine, 
					 int _nCmdShow)
{
	// TODO: Handle Parsing CMDLine arguments

	Platform::WindowManager wManager(_hInstance, _nCmdShow);

	wManager.Create(Platform::WindowManager::WINDOW_MODE_NORMAL, L"FTL Engine", 0, 0, 800, 600);
	
	while(wManager.Update());

	return NULL;
}