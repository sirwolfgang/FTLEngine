//===============================================================
// File:	GraphicsModule.cpp
// Purpose: To Handle the Game Graphics
//===============================================================
#include "GraphicsModule.h"
using namespace Core;

//---------------------------------------------------------------
GraphicsModule::GraphicsModule() 
	: m_RendererDLL(), m_pRenderer(nullptr)
{
	m_RendererDLL.Create(&m_pRenderer);
}

//---------------------------------------------------------------
GraphicsModule::~GraphicsModule()
{
	m_RendererDLL.Release();
}

//---------------------------------------------------------------
void GraphicsModule::Initialize(InitializationData& _InitializationData)
{
	// Window
	WindowModule::InitializationData WindowInitData;
	WindowInitData.hInstance	= _InitializationData.hInstance;
	WindowInitData.nCmdShow		= _InitializationData.nCmdShow;

	m_windowModule.Initialize(WindowInitData);
	m_windowModule.Startup();

	// Renderer
	Graphics::IRenderer::Settings Settings;

	Settings.nWidth			= 1024;
	Settings.nHeight		= 768;
	Settings.nRefreshRate	= 0;
	Settings.nMSAASamples	= 1;
	Settings.nSampleQuality = 0;
	Settings.nBufferCount	= 1;
	Settings.eDriverMode	= Graphics::IRenderer::eDriverMode_Hardware;
	Settings.hOutput		= m_windowModule.GetHandle();
	Settings.bDebugMode		= true;

	m_pRenderer->Initialize(Settings);
}

//---------------------------------------------------------------
void GraphicsModule::Startup()
{
	// Renderer
	m_pRenderer->Startup();
}

//---------------------------------------------------------------
void GraphicsModule::Shutdown()
{
	// Renderer
	m_pRenderer->Shutdown();

	// Window
	m_windowModule.Shutdown();
}

//---------------------------------------------------------------
void GraphicsModule::Update(float32 _fTime)
{
	// Window
	m_windowModule.Update(_fTime);

	// Renderer
	float Color[4] = {0.33f, 0.33f, 0.33f, 1.00f};

	m_pRenderer->ClearBackBuffer(Color);
	m_pRenderer->Present();
}