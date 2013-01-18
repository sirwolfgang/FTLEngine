//===============================================================
// File:	Engine.cpp
// Purpose: To handle game engine runtime, and scope
//===============================================================
#include "Engine.h"
using namespace Core;

Engine* Engine::sm_Instance = nullptr;

//---------------------------------------------------------------
Engine::Engine()
{

}

//---------------------------------------------------------------
Engine::Engine(HINSTANCE _hInstance, LPSTR _lpCmdLine, int _nCmdShow) 
{
	m_hInstance = _hInstance;
	m_lpCmdLine = _lpCmdLine;
	m_nCmdShow	= _nCmdShow;

	// TODO:: Handle Error of engine already being registered
	sm_Instance = this;
}

//---------------------------------------------------------------
Engine::~Engine()
{
	sm_Instance = nullptr;
}

//---------------------------------------------------------------
int32 Engine::Run()
{
	ModuleManager moduleManager;

	// Startup
	moduleManager.Startup();

	// Run
	while(true)
	{
		// TODO:: Add Timer
		moduleManager.Update(NULL);
	}

	// Shutdown
	moduleManager.Shutdown();

	// TODO:: Return Errors
	return NULL;
}