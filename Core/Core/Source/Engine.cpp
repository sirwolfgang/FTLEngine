//===============================================================
// File:	Engine.cpp
// Purpose: To handle game engine runtime, and scope
//===============================================================	
#include "Engine.h"
#include "Modules\ModuleManager.h"
using namespace Core;

//---------------------------------------------------------------
Engine_DLL::Engine_DLL()
{
	m_hInstance		= NULL;
	m_lpCmdLine		= nullptr;
	m_nCmdShow		= NULL;
}

//---------------------------------------------------------------
Engine_DLL::Engine_DLL(InitializationData& _InitializationData)
{
	m_hInstance		= _InitializationData.hInstance;
	m_lpCmdLine		= _InitializationData.lpCmdLine;
	m_nCmdShow		= _InitializationData.nCmdShow;
}

//---------------------------------------------------------------
Engine_DLL::~Engine_DLL()
{

}

//---------------------------------------------------------------
int32 Engine_DLL::Run()
{
	ModuleManager moduleManager;

	// Init
	ModuleManager::InitializationData InitData;
	InitData.hInstance	= m_hInstance;
	InitData.nCmdShow	= m_nCmdShow;

	moduleManager.Initialize(InitData);

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