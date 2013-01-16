//===============================================================
// File:	GraphicsModule.cpp
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#include "GraphicsModule.h"
#include "Renderer.h"
using namespace Graphics;

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

	Renderer::Settings Settings;
	m_pRenderer = new Renderer(Settings);
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