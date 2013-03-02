//===============================================================
// File:	ModuleManager.cpp
// Purpose: To Handle the base module managment interface
//===============================================================
#include "ModuleManager.h"
using namespace Core;

//---------------------------------------------------------------
ModuleManager::ModuleManager()
{

}

//---------------------------------------------------------------
ModuleManager::~ModuleManager()
{

}

//---------------------------------------------------------------
void ModuleManager::Initialize(InitializationData& _InitializationData)
{
	// TODO:: Handle Module Initialization and Settings

	WindowModule::InitializationData WindowInitData;
	WindowInitData.hInstance	= _InitializationData.hInstance;
	WindowInitData.nCmdShow		= _InitializationData.nCmdShow;

	m_windowModule.Initialize(WindowInitData);
}

//---------------------------------------------------------------
void ModuleManager::Startup()
{
	// TODO:: Starup Modules
	m_windowModule.Startup();
}

//---------------------------------------------------------------
void ModuleManager::Shutdown()
{
	// TODO:: Shutdown Modules
	m_windowModule.Shutdown();
}

//---------------------------------------------------------------
void ModuleManager::Update(float32 _fTime)
{
	// TODO:: Updates Modules
	m_windowModule.Update(_fTime);
}