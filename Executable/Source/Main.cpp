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
	int32 ReturnCode = NULL;

	CoreDLL.Create(&pCoreInterface);
	{
		Core::Engine::InitializationData InitData;
		InitData.hInstance	= _hInstance;
		InitData.lpCmdLine	= _lpCmdLine;
		InitData.nCmdShow	= _nCmdShow;

		Core::Engine* pEngine = pCoreInterface->InitializeEngine(InitData);

		ReturnCode = pEngine->Run();
	}
	CoreDLL.Release();

	return ReturnCode;
}