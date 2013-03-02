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

	GraphicsModule::InitializationData GraphicsInitData;
	GraphicsInitData.hInstance	= _InitializationData.hInstance;
	GraphicsInitData.nCmdShow	= _InitializationData.nCmdShow;

	m_graphicsModule.Initialize(GraphicsInitData);
}

//---------------------------------------------------------------
void ModuleManager::Startup()
{
	// TODO:: Starup Modules
	m_graphicsModule.Startup();
}

//---------------------------------------------------------------
void ModuleManager::Shutdown()
{
	// TODO:: Shutdown Modules
	m_graphicsModule.Shutdown();
}

//---------------------------------------------------------------
void ModuleManager::Update(float32 _fTime)
{
	// TODO:: Updates Modules
	m_graphicsModule.Update(_fTime);
}