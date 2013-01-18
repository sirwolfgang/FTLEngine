//===============================================================
// File:	Main.cpp
// Purpose: Entry Point for Game/Engine
//===============================================================
#include <FTLCore.h>
using Core::Engine;

int CALLBACK WinMain(HINSTANCE _hInstance, 
					 HINSTANCE _hPrevInstance, 
					 LPSTR _lpCmdLine, 
					 int _nCmdShow)
{

	Engine Game(_hInstance, _lpCmdLine, _nCmdShow);
	return Game.Run();
}