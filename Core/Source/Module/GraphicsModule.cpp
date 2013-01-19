//===============================================================
// File:	GraphicsModule.cpp
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#include "GraphicsModule.h"
using namespace Core;

//---------------------------------------------------------------
GraphicsModule::GraphicsModule()
{
	m_pRenderer = nullptr;
}

//---------------------------------------------------------------
GraphicsModule::~GraphicsModule()
{
	// TODO:: Error, Wasnt Shutdown
	if(m_pRenderer)
		Shutdown();
}

//---------------------------------------------------------------
void GraphicsModule::Startup()
{
	// TODO:: Error, Wasnt Shutdown
	if(m_pRenderer)
		Shutdown();

	m_WindowModule.Startup();

	// TODO:: Handle Dynamic Settings
	Graphics::Renderer::Settings Settings;
	//Settings.Width		= ;
	//Settings.Height		= ;
	//Settings.RefreshRate	= ;
	Settings.hOutput		= m_WindowModule.Window()->GetHandle();

	m_pRenderer = new Graphics::Renderer(Settings);
}

//---------------------------------------------------------------
void GraphicsModule::Shutdown()
{
	if(m_pRenderer)
	{
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	m_WindowModule.Shutdown();
}

//---------------------------------------------------------------
void GraphicsModule::Update(float32 _fTime)
{
	m_WindowModule.Update(_fTime);
	m_pRenderer->RenderFrame();
}