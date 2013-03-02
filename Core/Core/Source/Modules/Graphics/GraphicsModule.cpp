//===============================================================
// File:	GraphicsModule.cpp
// Purpose: To Handle the Game Graphics
//===============================================================
#include "GraphicsModule.h"
using namespace Core;

//---------------------------------------------------------------
GraphicsModule::GraphicsModule()
{

}

//---------------------------------------------------------------
GraphicsModule::~GraphicsModule()
{

}

//---------------------------------------------------------------
void GraphicsModule::Initialize(InitializationData& _InitializationData)
{
	// Window
	WindowModule::InitializationData WindowInitData;
	WindowInitData.hInstance	= _InitializationData.hInstance;
	WindowInitData.nCmdShow		= _InitializationData.nCmdShow;

	m_windowModule.Initialize(WindowInitData);
}

//---------------------------------------------------------------
void GraphicsModule::Startup()
{
	// Window
	m_windowModule.Startup();
}

//---------------------------------------------------------------
void GraphicsModule::Shutdown()
{
	// Window
	m_windowModule.Shutdown();
}

//---------------------------------------------------------------
void GraphicsModule::Update(float32 _fTime)
{
	// Window
	m_windowModule.Update(_fTime);
}