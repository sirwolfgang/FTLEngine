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
void ModuleManager::Startup()
{
	// Memory
	// File System
	// Video
	// Texture
	m_GraphicsModule.Startup();
	// Animation
	// Physics
	// ...
	// Simulation
}

//---------------------------------------------------------------
void ModuleManager::Shutdown()
{
	// Simulation
	// ...
	// Physics
	// Animation
	m_GraphicsModule.Shutdown();
	// Texture
	// Video
	// File System
	// Memory
}

//---------------------------------------------------------------
void ModuleManager::Update(float32 _fTime)
{
	// Memory
	// File System
	// Video
	// Texture
	m_GraphicsModule.Update(_fTime);
	// Animation
	// Physics
	// ...
	// Simulation
}