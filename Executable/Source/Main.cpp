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
	Engine::CoreDLL		CoreDLL;
	Engine::Core*		pCore;

	CoreDLL.Create(&pCore);
	{

	}
	CoreDLL.Release();

	return 0;
}