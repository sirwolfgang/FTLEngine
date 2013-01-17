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

	Graphics::Renderer::Settings Settings;
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
}