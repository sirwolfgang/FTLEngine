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
	Core::CoreDLL			CoreDLL;
	Core::CoreInterface*	pCoreInterface;

	CoreDLL.Create(&pCoreInterface);
	{

	}
	CoreDLL.Release();

	return 0;
}